#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include "time.h"

bool isPlateInParking(String plate);
bool isCardInParking(String cardId);
// ================== Cấu hình WiFi & Firebase =================
#define WIFI_SSID     "iPhone"
#define WIFI_PASSWORD "1234567890"

#define API_KEY       "AIzaSyANuOc4feLOxOLN0oSi5Xgzo1tgeMwvmxc"
#define DATABASE_URL  "https://baidoxe-002-default-rtdb.asia-southeast1.firebasedatabase.app/"

#define USER_EMAIL    "nguyentuyenduan9ctptd@gmail.com"
#define USER_PASSWORD "555555"

// Firebase objects
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// ----- LCD I2C -----
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ----- RFID RC522 (SPI) -----
#define SS_PIN   5
#define RST_PIN  4
#define MOSI_PIN 7
#define MISO_PIN 10
#define SCK_PIN  6
MFRC522 rfid(SS_PIN, RST_PIN);

// ----- IR Sensors -----
#define IR_IN     2   // cảm biến cổng vào
#define IR_OUT    3   // cảm biến cổng ra
#define IR_SLOT1  13  // slot 1
#define IR_SLOT2  14  // slot 2
#define IR_SLOT3  15  // slot 3

// ----- Servo SG90 -----
#define SERVO_IN_PIN  11
#define SERVO_OUT_PIN 12
Servo servoIn;
Servo servoOut;

const int SERVO_OPEN_ANGLE = 90;
const int SERVO_CLOSED_ANGLE = 0;
const unsigned long SERVO_OPEN_TIME = 3000; // ms

int totalSlots = 3;   // tổng số chỗ
int freeSlots = 3;    // số chỗ trống
int usedSlots = 0;    // số chỗ đã dùng

// ----- NTP -----
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 7*3600;
const int daylightOffset_sec = 0;

// ===================== Hàm lấy giờ thực =====================
String getCurrentTime() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Khong the co thoi gian");
    return "0000-00-00T00:00:00";
  }
  char buffer[25];
  strftime(buffer, 25, "%Y-%m-%dT%H:%M:%S", &timeinfo);
  return String(buffer);
}

// ===================== Hàm tính tiền =====================
int calculateAmount(float totalHours) {
  const int pricePerBlock = 5000; // 30 phút
  int totalMinutes = ceil(totalHours * 60);
  int blocks = ceil(totalMinutes / 30.0);

  return blocks * pricePerBlock;
}

// ===================== Hàm mở cổng =====================
void openGate(Servo &servo, String gateName) {
  servo.write(SERVO_OPEN_ANGLE);
  Serial.println(gateName + " MO");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(gateName + " Dang mo...");
  delay(SERVO_OPEN_TIME);
  servo.write(SERVO_CLOSED_ANGLE);
  Serial.println(gateName + "Dong");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(gateName + " Dong");
  delay(500);
}

// ===================== Cập nhật slot Firebase =====================
void updateSlotsToFirebase(bool s1, bool s2, bool s3) {
  if (Firebase.ready()) {
    Firebase.RTDB.setBool(&fbdo, "/parkingSlots/slot1", s1);
    Firebase.RTDB.setBool(&fbdo, "/parkingSlots/slot2", s2);
    Firebase.RTDB.setBool(&fbdo, "/parkingSlots/slot3", s3);
  }
}

// ===================== Hiển thị và tính slot =====================
void showSlots() {int s1 = digitalRead(IR_SLOT1);
  int s2 = digitalRead(IR_SLOT2);
  int s3 = digitalRead(IR_SLOT3);

  usedSlots = 0;
  bool slot1Occupied = (s1 == LOW);
  bool slot2Occupied = (s2 == LOW);
  bool slot3Occupied = (s3 == LOW);

  if (slot1Occupied) usedSlots++;
  if (slot2Occupied) usedSlots++;
  if (slot3Occupied) usedSlots++;

  freeSlots = totalSlots - usedSlots;

  updateSlotsToFirebase(slot1Occupied, slot2Occupied, slot3Occupied);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("S1:");
  lcd.print(slot1Occupied ? "X" : "O");
  lcd.print(" S2:");
  lcd.print(slot2Occupied ? "X" : "O");

  lcd.setCursor(0,1);
  lcd.print("S3:");
  lcd.print(slot3Occupied ? "X" : "O");
  lcd.print(" F:");
  lcd.print(freeSlots);
  lcd.print("/");
  lcd.print(totalSlots);

  Serial.print("Slot1="); Serial.print(slot1Occupied ? "X" : "O");
  Serial.print(" | Slot2="); Serial.print(slot2Occupied ? "X" : "O");
  Serial.print(" | Slot3="); Serial.print(slot3Occupied ? "X" : "O");
  Serial.print(" | Free="); Serial.print(freeSlots);
  Serial.print(" | Used="); Serial.println(usedSlots);
}

// ===================== Log check-in/out =====================
String createLogId() {
  return "log" + String(millis());
}

// ================== CHECK IN ==================
// ================== CHECK IN ==================
bool addCheckInLog(String cardId) {
  String logId = createLogId();
  String currentTime = getCurrentTime();

  // ---- Lấy biển số từ YOLO ----
  String plateNumber = "null";
  if (Firebase.RTDB.getString(&fbdo, "/latest_plate_candidates/plate")) {
    if (fbdo.dataType() == "string") {
      plateNumber = fbdo.stringData();
    }
  }

  // ❌ CẤM TRÙNG BIỂN
  if (isPlateInParking(plateNumber)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Plate existed!");
    lcd.setCursor(0,1);
    lcd.print("Denied");
    delay(2000);
    return false;
  }

  FirebaseJson json;
  json.set("cardId", cardId);
  json.set("plateNumber", plateNumber);
  json.set("checkInTime", currentTime);
  json.set("checkOutTime", "null");
  json.set("status", "in");

  if (Firebase.RTDB.setJSON(&fbdo, "/parkingLogs/" + logId, &json)) {
    Serial.println("Check-in OK");
    return true;
  }

  return false;
}



void addCheckOutLog(String cardId) {
  if (!Firebase.ready()) return;

  if (!Firebase.RTDB.getJSON(&fbdo, "/parkingLogs")) {
    Serial.println("Failed to get logs: " + fbdo.errorReason());
    return;
  }

  FirebaseJson &logs = fbdo.jsonObject();
  size_t len = logs.iteratorBegin();
  String logId = "";
  String checkInTimeStr = "";
  String plateNumber = "null"; // lưu biển số gốc

  for (size_t i = 0; i < len; i++) {
    int type;
    String key, value;
    logs.iteratorGet(i, type, key, value);

    FirebaseJsonData idData, statusData, timeData, plateData;

    logs.get(idData, (key + "/cardId").c_str());
    logs.get(statusData, (key + "/status").c_str());
    logs.get(plateData, (key + "/plateNumber").c_str());

    if (idData.success && statusData.success) {
      String id = idData.stringValue;
      String status = statusData.stringValue;

      if (id == cardId && status == "in") {
        logId = key;
        logs.get(timeData, (key + "/checkInTime").c_str());
        if (timeData.success) checkInTimeStr = timeData.stringValue;

        if (plateData.success) plateNumber = plateData.stringValue; // Lấy biển số gốc
        break;
      }
    }
  }
  logs.iteratorEnd();

  if (logId == "") {
    Serial.println("No check-in log found for card: " + cardId);
    return;
  }

  // thời gian check-out
  String checkOutTimeStr = getCurrentTime();
  struct tm tmCheckIn, tmCheckOut;
  strptime(checkInTimeStr.c_str(), "%Y-%m-%dT%H:%M:%S", &tmCheckIn);
  strptime(checkOutTimeStr.c_str(), "%Y-%m-%dT%H:%M:%S", &tmCheckOut);
  time_t tCheckIn = mktime(&tmCheckIn);
  time_t tCheckOut = mktime(&tmCheckOut);

  float totalHours = difftime(tCheckOut, tCheckIn) / 3600.0;
  float amount = calculateAmount(totalHours);

  // cập nhật log
  FirebaseJson jsonUpdate;
  jsonUpdate.set("checkOutTime", checkOutTimeStr);
  jsonUpdate.set("status", "out");
  jsonUpdate.set("totalHours", totalHours);
  jsonUpdate.set("amount", amount);
  jsonUpdate.set("plateNumber", plateNumber); // **giữ nguyên biển số gốc**

  if (Firebase.RTDB.updateNode(&fbdo, "/parkingLogs/" + logId, &jsonUpdate)) {
    Serial.println("Check-out log updated: " + logId + " | Plate: " + plateNumber);
  } else {
    Serial.println("Firebase update failed: " + fbdo.errorReason());
  }

  // cập nhật revenue theo ngày
  String date = checkOutTimeStr.substring(0,10);
  float oldTotal = 0;
  int oldTransactions = 0;

  if (Firebase.RTDB.getFloat(&fbdo, "/revenue/" + date + "/total")) 
    oldTotal = fbdo.floatData();
  if (Firebase.RTDB.getInt(&fbdo, "/revenue/" + date + "/transactions")) 
    oldTransactions = fbdo.intData();

  Firebase.RTDB.setFloat(&fbdo, "/revenue/" + date + "/total", oldTotal + amount);
  Firebase.RTDB.setInt(&fbdo, "/revenue/" + date + "/transactions", oldTransactions + 1);
}


// ===================== Setup =====================
void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Parking System");
// WiFi
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("Dang ket noi WiFi");
while (WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(300);
}
Serial.println("\nDa ket noi WiFi!");

// Firebase config
config.api_key = API_KEY;
auth.user.email = USER_EMAIL;
auth.user.password = USER_PASSWORD;
config.database_url = DATABASE_URL;

// Bắt đầu Firebase
Firebase.begin(&config, &auth);
Firebase.reconnectWiFi(true);

// Chờ login xíu
Serial.print("Dang dang nhap Firebase");
while ((auth.token.uid) == "") {
  Serial.print(".");
  delay(500);
}
Serial.println("\nDa dang nhap Firebase!");

 

  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, SS_PIN);
  rfid.PCD_Init();

  pinMode(IR_IN, INPUT);
  pinMode(IR_OUT, INPUT);
  pinMode(IR_SLOT1, INPUT);pinMode(IR_SLOT2, INPUT);
  pinMode(IR_SLOT3, INPUT);

  servoIn.attach(SERVO_IN_PIN);
  servoOut.attach(SERVO_OUT_PIN);
  servoIn.write(SERVO_CLOSED_ANGLE);
  servoOut.write(SERVO_CLOSED_ANGLE);

  // NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  delay(1500);
  showSlots();
}
// ================== KIỂM TRA BIỂN ĐANG TRONG BÃI ==================
bool isPlateInParking(String plate) {
  if (plate == "null") return false;

  if (!Firebase.RTDB.getJSON(&fbdo, "/parkingLogs")) return false;

  FirebaseJson &logs = fbdo.jsonObject();
  size_t len = logs.iteratorBegin();

  for (size_t i = 0; i < len; i++) {
    int type;
    String key, value;
    logs.iteratorGet(i, type, key, value);

    FirebaseJsonData plateData, statusData;
    logs.get(plateData, (key + "/plateNumber").c_str());
    logs.get(statusData, (key + "/status").c_str());

    if (plateData.success && statusData.success) {
      if (plateData.stringValue == plate && statusData.stringValue == "in") {
        logs.iteratorEnd();
        return true;   // ❌ biển đã ở trong bãi
      }
    }
  }
  logs.iteratorEnd();
  return false;
}

// ================== KIỂM TRA THẺ ĐANG TRONG BÃI ==================
bool isCardInParking(String cardId) {
  if (!Firebase.RTDB.getJSON(&fbdo, "/parkingLogs")) return false;

  FirebaseJson &logs = fbdo.jsonObject();
  size_t len = logs.iteratorBegin();

  for (size_t i = 0; i < len; i++) {
    int type;
    String key, value;
    logs.iteratorGet(i, type, key, value);

    FirebaseJsonData idData, statusData;
    logs.get(idData, (key + "/cardId").c_str());
    logs.get(statusData, (key + "/status").c_str());

    if (idData.success && statusData.success) {
      if (idData.stringValue == cardId && statusData.stringValue == "in") {
        logs.iteratorEnd();
        return true;   // ✅ thẻ hợp lệ để ra
      }
    }
  }
  logs.iteratorEnd();
  return false;
}

// ===================== Loop =====================
void loop() {
  showSlots();

  int irInState = digitalRead(IR_IN);
  int irOutState = digitalRead(IR_OUT);

// --- Cổng vào ---
if (irInState == LOW && freeSlots > 0) { 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Car at IN gate");
  lcd.setCursor(0,1);
  lcd.print("Scan RFID...");

  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String uidString = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      if (rfid.uid.uidByte[i] < 0x10) uidString += "0";
      uidString += String(rfid.uid.uidByte[i], HEX);
      if (i != rfid.uid.size-1) uidString += ":";
    }
    uidString.toUpperCase();

    Serial.print("Card UID (IN): ");
    Serial.println(uidString);

    // Thông báo xác nhận thẻ
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("RFID OK");
    lcd.setCursor(0,1);
    lcd.print("Gate Opening...");
    delay(1000);

    if (addCheckInLog(uidString)) {
  openGate(servoIn, "IN GATE");
}


    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    showSlots();
  }
} else if (irInState == LOW && freeSlots == 0) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Parking FULL!");
  delay(1000);
  showSlots();
}

// --- Cổng ra ---
if (irOutState == LOW) { 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Car at OUT gate");
  lcd.setCursor(0,1);
  lcd.print("Scan RFID...");

  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String uidString = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      if (rfid.uid.uidByte[i] < 0x10) uidString += "0";
      uidString += String(rfid.uid.uidByte[i], HEX);
      if (i != rfid.uid.size-1) uidString += ":";
    }
    uidString.toUpperCase();

    Serial.print("Card UID (OUT): ");
    Serial.println(uidString);

    // Thông báo xác nhận thẻ
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("RFID OK");
    lcd.setCursor(0,1);
    lcd.print("Gate Opening...");
    delay(1000);

    if (isCardInParking(uidString)) {
  addCheckOutLog(uidString);
  openGate(servoOut, "OUT GATE");
} else {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Invalid card!");
  lcd.setCursor(0,1);
  lcd.print("No vehicle in");
  delay(2000);
}

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    showSlots();
  }
}

  delay(500); // tránh LCD nhấp nháy
}