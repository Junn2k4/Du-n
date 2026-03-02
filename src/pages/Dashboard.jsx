import React from "react";
import { useNavigate } from "react-router-dom";

export default function Dashboard() {
  const navigate = useNavigate();

  const cardStyle = {
    background: "#00b5a7",
    color: "white",
    padding: "14px 18px",
    borderRadius: "14px",
    marginBottom: "18px",
    cursor: "pointer",
    boxShadow: "0 5px 15px rgba(0,0,0,0.1)",
    transition: "0.25s",
  };

  return (
    <div
      style={{
        minHeight: "100vh",
        background: "linear-gradient(to bottom right, #E8F8F1, #009f94)",
        display: "flex",
        justifyContent: "center",
        alignItems: "center",
        padding: "20px",
      }}
    >
      <div
        style={{
          width: "100%",
          maxWidth: "420px",
          background: "#ffffff",
          borderRadius: "18px",
          padding: "28px 25px",
          boxShadow: "0 10px 25px rgba(0,0,0,0.15)",
          textAlign: "center",
          position: "relative",
        }}
      >
        {/* QUAY LẠI */}
        <button
          onClick={() => navigate(-1)}
          style={{
            position: "absolute",
            top: "18px",
            left: "18px",
            background: "#00a89e",
            border: "none",
            padding: "8px 14px",
            borderRadius: "10px",
            color: "white",
            fontSize: "14px",
            cursor: "pointer",
            boxShadow: "0 4px 12px rgba(0,0,0,0.15)",
            transition: "0.25s",
          }}
        >
          ⬅ Quay lại
        </button>

        <h1 style={{ color: "#00a89e", marginBottom: "10px", fontSize: "24px" }}>
          📊 Admin Dashboard
        </h1>

        <p style={{ color: "#666", marginBottom: "25px" }}>
          Chọn chức năng quản lý:
        </p>

        {/* DOANH THU */}
        <div
          style={cardStyle}
          onClick={() => navigate("/revenue")}
          onMouseEnter={(e) => (e.currentTarget.style.transform = "scale(1.02)")}
          onMouseLeave={(e) => (e.currentTarget.style.transform = "scale(1)")}
        >
          <div style={{ fontSize: "30px" }}>💰</div>
          <h3 style={{ marginTop: "8px", fontSize: "18px" }}>
            Xem Doanh Thu
          </h3>
        </div>

        {/* QUẢN LÝ BÃI XE */}
        <div
          style={cardStyle}
          onClick={() => navigate("/cars")}
          onMouseEnter={(e) => (e.currentTarget.style.transform = "scale(1.02)")}
          onMouseLeave={(e) => (e.currentTarget.style.transform = "scale(1)")}
        >
          <div style={{ fontSize: "30px" }}>🚗</div>
          <h3 style={{ marginTop: "8px", fontSize: "18px" }}>
            Quản lý bãi xe
          </h3>
        </div>
      </div>
    </div>
  );
}
