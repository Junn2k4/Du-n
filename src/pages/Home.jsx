import React from "react";
import { useNavigate } from "react-router-dom";

export default function Home() {
  const navigate = useNavigate();

  return (
    <div style={styles.container}>
      <div style={styles.header}>
        <h1 style={styles.logo}>Smart Parking</h1>
        <p style={styles.slogan}>Nhanh chóng · Tiện lợi · Thông minh</p>
      </div>

      <div style={styles.cardContainer}>
        <div style={styles.card} onClick={() => navigate("/user")}>
          <div style={styles.iconCircle}>
            <span style={styles.icon}>👤</span>
          </div>
          <h3 style={styles.cardTitle}>Người dùng</h3>
          <p style={styles.cardDesc}>Xem tình trạng bãi đỗ xe</p>
        </div>

        <div style={styles.card} onClick={() => navigate("/login")}>
          <div style={styles.iconCircleAdmin}>
            <span style={styles.icon}>🔑</span>
          </div>
          <h3 style={styles.cardTitle}>Quản trị</h3>
          <p style={styles.cardDesc}>Quản lý dữ liệu & doanh thu</p>
        </div>
      </div>
    </div>
  );
}

const styles = {
  container: {
    height: "100vh",
    background: "#E8F8F1", // nền xanh nhạt kiểu Grab
    padding: "40px 20px",
    textAlign: "center",
    fontFamily: "sans-serif",
  },

  header: {
    marginBottom: "35px",
  },

  logo: {
    fontSize: "34px",
    fontWeight: "700",
    color: "#00A885", // màu xanh Grab
    marginBottom: "8px",
  },

  slogan: {
    fontSize: "15px",
    color: "#555",
  },

  cardContainer: {
    display: "flex",
    justifyContent: "center",
    gap: "20px",
    flexWrap: "wrap",
  },

  card: {
    width: "160px",
    padding: "20px",
    borderRadius: "18px",
    background: "#fff",
    boxShadow: "0 4px 15px rgba(0,0,0,0.1)",
    cursor: "pointer",
    transition: "0.25s",
  },

  cardTitle: {
    marginTop: "10px",
    fontSize: "18px",
    fontWeight: "600",
    color: "#333",
  },

  cardDesc: {
    fontSize: "13px",
    color: "#777",
  },

  iconCircle: {
    width: "60px",
    height: "60px",
    background: "#00A885",
    borderRadius: "50%",
    display: "flex",
    justifyContent: "center",
    alignItems: "center",
    margin: "0 auto",
    boxShadow: "0 3px 10px rgba(0,168,133,0.3)",
  },

  iconCircleAdmin: {
    width: "60px",
    height: "60px",
    background: "#0D8AFF",
    borderRadius: "50%",
    display: "flex",
    justifyContent: "center",
    alignItems: "center",
    margin: "0 auto",
    boxShadow: "0 3px 10px rgba(13,138,255,0.3)",
  },

  icon: {
    fontSize: "28px",
  },
};
