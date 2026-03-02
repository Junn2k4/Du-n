import React from "react";
import RevenueChart from "../components/RevenueChart";

export default function Dashboard() {
  return (
    <div
      style={{
        padding: "20px",
        fontFamily: "Arial",
        maxWidth: "900px",
        margin: "auto",
      }}
    >
      <h2
        style={{
          textAlign: "center",
          marginBottom: "20px",
          color: "#0AAB8B",
        }}
      >
        📊 Admin Dashboard
      </h2>

      {/* CARD TỔNG QUAN */}
      <div
        style={{
          display: "flex",
          justifyContent: "space-around",
          marginBottom: "30px",
          flexWrap: "wrap",
        }}
      >
        <div style={card}>
          <h3 style={cardTitle}>Tổng doanh thu</h3>
          <p style={cardValue}>—</p>
        </div>

        <div style={card}>
          <h3 style={cardTitle}>Số xe hôm nay</h3>
          <p style={cardValue}>—</p>
        </div>

        <div style={card}>
          <h3 style={cardTitle}>Số lượt gửi</h3>
          <p style={cardValue}>—</p>
        </div>
      </div>

      {/* BIỂU ĐỒ */}
      <div
        style={{
          borderRadius: "12px",
          padding: "20px",
          background: "white",
          boxShadow: "0px 4px 10px rgba(0,0,0,0.05)",
          border: "1px solid #e0e0e0",
        }}
      >
        <h3 style={{ textAlign: "center", color: "#0AAB8B" }}>
          📈 Biểu đồ doanh thu
        </h3>
        <RevenueChart />
      </div>
    </div>
  );
}

const card = {
  background: "#0AAB8B",
  color: "white",
  width: "28%",
  padding: "20px",
  borderRadius: "12px",
  textAlign: "center",
  marginBottom: "15px",
  minWidth: "170px",
  boxShadow: "0px 4px 10px rgba(0,0,0,0.1)",
};

const cardTitle = {
  fontSize: "16px",
  fontWeight: "bold",
  marginBottom: "5px",
};

const cardValue = {
  fontSize: "22px",
  fontWeight: "bold",
};
