import { useEffect, useState } from "react";
import { db } from "../firebase";
import { ref, onValue } from "firebase/database";
import { useNavigate } from "react-router-dom";

export default function User() {
  const [slots, setSlots] = useState({});
  const navigate = useNavigate();

  useEffect(() => {
    const slotsRef = ref(db, "parkingSlots");
    const unsubscribe = onValue(slotsRef, (snapshot) => {
      if (snapshot.exists()) setSlots(snapshot.val());
    });
    return () => unsubscribe();
  }, []);

  return (
    <div style={container}>
      {/* Nút quay lại */}
      <button style={btnBack} onClick={() => navigate("/dashboard")}>
        ⬅ Quay lại
      </button>

      <h2 style={title}>🚗 Parking Status</h2>

      <div style={gridContainer}>
        {Object.entries(slots).length > 0 ? (
          Object.entries(slots).map(([slotId, status]) => (
            <div key={slotId} style={slotBox}>
              <div style={slotInner}>
                <div style={{ ...carIcon, opacity: status ? 1 : 0.2 }}>🚗</div>
                <div style={slotText}>
                  {slotId.toUpperCase()}
                  <div style={slotSubText}>{status ? "Đã có xe" : "Trống"}</div>
                </div>
              </div>
            </div>
          ))
        ) : (
          <div style={{ gridColumn: "1/-1", textAlign: "center", color: "#fff" }}>
            Không có dữ liệu
          </div>
        )}
      </div>
    </div>
  );
}

/* ===== STYLE ===== */
const container = {
  padding: "20px",
  minHeight: "100vh",
  background: "linear-gradient(to bottom right, #E8F8F1, #00a89e)",
  textAlign: "center",
  position: "relative",
  fontFamily: "'Segoe UI', Tahoma, Geneva, Verdana, sans-serif",
};

const btnBack = {
  position: "absolute",
  top: "20px",
  left: "20px",
  background: "#00a89e",
  border: "none",
  padding: "10px 18px",
  color: "white",
  fontWeight: "bold",
  borderRadius: "12px",
  cursor: "pointer",
  boxShadow: "0 4px 10px rgba(0,0,0,0.15)",
  display: "flex",
  alignItems: "center",
  gap: "6px",
};

const title = {
  color: "#006f68",
  marginBottom: "20px",
  fontSize: "28px",
};

const gridContainer = {
  display: "grid",
  gridTemplateColumns: "repeat(auto-fit, minmax(120px, 1fr))", // tự động co giãn đều
  gap: "15px",
  padding: "10px",
  justifyItems: "center",
  marginTop: "40px",
};

const slotBox = {
  width: "100%",
  maxWidth: "180px", // rộng hơn để không dồn góc
  position: "relative",
  borderRadius: "18px",
  backgroundColor: "#e8fff7",
  border: "3px dashed #00a89e",
  boxShadow: "0 8px 20px rgba(0,0,0,0.15)",
  cursor: "pointer",
  overflow: "hidden",
  transition: "transform 0.25s",
};

const slotInner = {
  width: "100%",
  paddingBottom: "133%", // tỉ lệ 3:4
  position: "relative",
};

const carIcon = {
  fontSize: "50px",
  position: "absolute",
  top: "40%",
  left: "50%",
  transform: "translate(-50%, -50%)",
  transition: "0.3s",
};

const slotText = {
  position: "absolute",
  bottom: "8px",
  width: "100%",
  textAlign: "center",
  fontWeight: "bold",
  color: "#007f73",
};

const slotSubText = {
  fontSize: "12px",
  marginTop: "2px",
  fontWeight: "600",
  color: "#d62828",
};

/* ===== Hover Desktop ===== */
if (typeof window !== "undefined") {
  const styleSheet = document.styleSheets[0];
  styleSheet.insertRule(`
    @media (hover: hover) {
      div[style*="border-radius: 18px"]:hover {
        transform: scale(1.05);
      }
    }
  `, styleSheet.cssRules.length);
}
