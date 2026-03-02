import React, { useEffect, useState } from "react";
import { db } from "../firebase";
import { ref, onValue } from "firebase/database";
import { useNavigate } from "react-router-dom";
import RevenueChart from "../components/RevenueChart";

export default function Revenue() {
  const [revenue, setRevenue] = useState({});
  const [filter, setFilter] = useState("day");
  const navigate = useNavigate();

  // ✅ Format tiền
  const formatMoney = (value) =>
    value ? value.toLocaleString("vi-VN") + " ₫" : "0 ₫";

  // ✅ Lấy dữ liệu doanh thu từ Firebase
  useEffect(() => {
    const revenueRef = ref(db, "revenue");
    onValue(revenueRef, (snapshot) => {
      if (snapshot.exists()) setRevenue(snapshot.val());
      else setRevenue({});
    });
  }, []);

  // ✅ Lọc theo ngày / tháng / năm
  const filteredData = Object.keys(revenue)
    .filter((key) => {
      if (filter === "day") return key.length === 10; // YYYY-MM-DD
      if (filter === "month") return key.length === 7; // YYYY-MM
      if (filter === "year") return key.length === 4; // YYYY
      return true;
    })
    .reduce((obj, key) => {
      obj[key] = revenue[key];
      return obj;
    }, {});

  // ✅ Chuyển về mảng để truyền xuống biểu đồ
  const chartData = Object.keys(filteredData).map((key) => ({
    date: key,
    total: filteredData[key].total || 0,
  }));

  return (
    <div
      style={{
        padding: "20px",
        fontFamily: "Arial",
        maxWidth: "900px",
        margin: "auto",
      }}
    >
      {/* TIÊU ĐỀ */}
      <h2
        style={{
          textAlign: "center",
          marginBottom: "20px",
          color: "#0AAB8B",
          fontWeight: "bold",
        }}
      >
        💰 Doanh Thu
      </h2>

      {/* NÚT FILTER */}
      <div
        style={{
          display: "flex",
          justifyContent: "center",
          gap: "12px",
          marginBottom: "25px",
        }}
      >
        {["day", "month", "year"].map((type) => (
          <button
            key={type}
            onClick={() => setFilter(type)}
            style={filterButton(filter === type)}
          >
            {type === "day" && "Ngày"}
            {type === "month" && "Tháng"}
            {type === "year" && "Năm"}
          </button>
        ))}
      </div>

      {/* DANH SÁCH DOANH THU */}
      <div style={listContainer}>
        {Object.keys(filteredData).length ? (
          <ul style={{ padding: 0, listStyle: "none" }}>
            {Object.keys(filteredData).map((key) => (
              <li key={key} style={listItem}>
                <div style={{ fontWeight: "bold", color: "#0AAB8B" }}>{key}</div>
                <div>{formatMoney(filteredData[key].total)}</div>
                <div style={{ fontSize: "13px", color: "gray" }}>
                  {filteredData[key].transactions} giao dịch
                </div>
              </li>
            ))}
          </ul>
        ) : (
          <p style={{ textAlign: "center", color: "gray" }}>
            Không có dữ liệu doanh thu
          </p>
        )}
      </div>

      {/* BIỂU ĐỒ */}
      <div style={chartContainer}>
        <h3
          style={{
            textAlign: "center",
            color: "#0AAB8B",
            marginBottom: "15px",
            fontWeight: "bold",
          }}
        >
          📈 Biểu đồ doanh thu
        </h3>

        <RevenueChart data={chartData} />
      </div>

      {/* NÚT QUAY LẠI */}
      <button style={backButton} onClick={() => navigate("/dashboard")}>
        ⬅ Quay lại
      </button>
    </div>
  );
}

/* =======================
    STYLE COMPONENT
======================= */
const filterButton = (active) => ({
  padding: "10px 24px",
  borderRadius: "25px",
  border: "2px solid #0AAB8B",
  background: active ? "#0AAB8B" : "white",
  color: active ? "white" : "#0AAB8B",
  cursor: "pointer",
  fontWeight: "bold",
  transition: "0.25s",
});

const listContainer = {
  background: "white",
  padding: "20px",
  borderRadius: "12px",
  boxShadow: "0px 4px 12px rgba(0,0,0,0.06)",
  marginBottom: "30px",
};

const listItem = {
  padding: "12px 15px",
  marginBottom: "10px",
  background: "#F2FFFC",
  borderRadius: "10px",
  display: "flex",
  justifyContent: "space-between",
  alignItems: "center",
};

const chartContainer = {
  background: "white",
  padding: "20px",
  borderRadius: "12px",
  boxShadow: "0px 4px 12px rgba(0,0,0,0.08)",
};

const backButton = {
  marginTop: "25px",
  background: "#0AAB8B",
  color: "white",
  border: "none",
  padding: "12px 18px",
  borderRadius: "10px",
  cursor: "pointer",
  width: "100%",
  fontWeight: "bold",
};
