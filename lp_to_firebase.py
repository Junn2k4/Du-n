import cv2
import torch
import time
import firebase_admin
from firebase_admin import credentials, db
import function.utils_rotate as utils_rotate
import function.helper as helper

SERVICE_ACCOUNT_PATH = "firebase_key.json"
DATABASE_URL = "https://baidoxe-002-default-rtdb.asia-southeast1.firebasedatabase.app"

cred = credentials.Certificate(SERVICE_ACCOUNT_PATH)
firebase_admin.initialize_app(cred, {
    'databaseURL': DATABASE_URL
})

# Node candidate cho ESP32-S3 lấy
ref_candidate = db.reference('/latest_plate_candidates')

# --- LOAD MODEL YOLO ---
yolo_LP_detect = torch.hub.load('yolov5', 'custom', path='model/LP_detector_nano_61.pt', source='local')
yolo_license_plate = torch.hub.load('yolov5', 'custom', path='model/LP_ocr_nano_62.pt', source='local')
yolo_license_plate.conf = 0.60

# --- STREAM TỪ ESP32-CAM ---
VID_STREAM = "http://192.168.1.22:81/stream"
vid = cv2.VideoCapture(VID_STREAM)
if not vid.isOpened():
    print("❌ Không kết nối được camera ESP32-CAM")
    exit()

prev_frame_time = 0
stable_plate_count = {}
plate_first_seen = {}
STABLE_COUNT_REQUIRED = 7
STABLE_TIME_WINDOW = 10
try:
    while True:
        ret, frame = vid.read()
        if not ret or frame is None:
            time.sleep(0.2)
            continue

        plates = yolo_LP_detect(frame, size=640)
        list_plates = plates.pandas().xyxy[0].values.tolist()

        for plate in list_plates:
            x, y, xmax, ymax, conf, cls, name = plate
            x, y, w, h = int(x), int(y), int(xmax-x), int(ymax-y)
            if w <= 0 or h <= 0:
                continue
            crop_img = frame[y:y+h, x:x+w]
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)

            lp = helper.read_plate(yolo_license_plate, utils_rotate.deskew(crop_img, 0, 0))
            if lp and lp != "unknown":
                now = time.time()

                # lần đầu thấy biển số này
                if lp not in plate_first_seen:
                    plate_first_seen[lp] = now
                    stable_plate_count[lp] = 1
                else:
                    stable_plate_count[lp] += 1

                # kiểm tra ổn định
                if (now - plate_first_seen[lp] <= STABLE_TIME_WINDOW
                    and stable_plate_count[lp] >= STABLE_COUNT_REQUIRED):

                    print(f"✅ Biển số ổn định: {lp}")

                    # push duy nhất biển số ổn định lên Firebase
                    ref_candidate.set({
                        "plate": lp,
                        "timestamp": int(now)
                    })

                    # reset để không push trùng
                    stable_plate_count.clear()
                    plate_first_seen.clear()

                cv2.putText(frame, lp, (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX,
                            0.9, (36, 255, 12), 2)

        # FPS
        new_frame_time = time.time()
        fps = 1/(new_frame_time-prev_frame_time) if prev_frame_time else 0
        prev_frame_time = new_frame_time
        cv2.putText(frame, f"FPS: {int(fps)}", (7,70), cv2.FONT_HERSHEY_SIMPLEX, 2, (100,255,0), 2)

        cv2.imshow('ESP32-CAM', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

except KeyboardInterrupt:
    print("Stopped by user")

finally:
    vid.release()
    cv2.destroyAllWindows()
