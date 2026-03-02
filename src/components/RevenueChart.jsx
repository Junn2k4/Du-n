import React from "react";
import {
  LineChart,
  Line,
  XAxis,
  YAxis,
  Tooltip,
  CartesianGrid,
  ResponsiveContainer,
} from "recharts";

const formatMoney = (value) => value.toLocaleString("vi-VN") + " ₫";

// ✅ Rút gọn số: 1200000 → 1.2M, 200000 → 200k
const shortNumber = (num) => {
  if (num >= 1_000_000) return (num / 1_000_000).toFixed(1) + "M";
  if (num >= 1_000) return Math.round(num / 1_000) + "k";
  return num.toString();
};

export default function RevenueChart({ data }) {
  if (!data || data.length === 0)
    return (
      <p style={{ textAlign: "center", color: "gray" }}>
        Không có dữ liệu để hiển thị
      </p>
    );

  return (
    <ResponsiveContainer width="100%" height={400}>
      <LineChart
        data={data}
        margin={{ top: 20, right: 30, left: 10, bottom: 10 }}
      >
        {/* ✅ Gradient màu đẹp */}
        <defs>
          <linearGradient id="lineGradient" x1="0" y1="0" x2="0" y2="1">
            <stop offset="0%" stopColor="#00D4A2" stopOpacity={1} />
            <stop offset="100%" stopColor="#00A884" stopOpacity={0.3} />
          </linearGradient>

          <linearGradient id="shadowGradient" x1="0" y1="0" x2="0" y2="1">
            <stop offset="0%" stopColor="#00D4A2" stopOpacity={0.3} />
            <stop offset="100%" stopColor="#00A884" stopOpacity={0} />
          </linearGradient>
        </defs>

        {/* ✅ Grid nhẹ nhàng hiện đại */}
        <CartesianGrid stroke="#e5e7eb" strokeDasharray="4 4" opacity={0.6} />

        <XAxis tick={{ fill: "#6b7280" }} dataKey="date" />

        {/* ✅ Y-axis hiển thị dạng 200k – 500k – 1.2M */}
        <YAxis
          tick={{ fill: "#6b7280" }}
          domain={[0, "auto"]}
          tickFormatter={shortNumber}
        />

        {/* ✅ Tooltip đẹp hơn */}
        <Tooltip
          formatter={(value) => formatMoney(value)}
          contentStyle={{
            backgroundColor: "white",
            borderRadius: 10,
            border: "1px solid #e5e7eb",
            boxShadow: "0 4px 12px rgba(0, 0, 0, 0.08)",
          }}
        />

        {/* ✅ Line gradient + dot đẹp */}
        <Line
          type="monotone"
          dataKey="total"
          stroke="url(#lineGradient)"
          strokeWidth={4}
          dot={{ r: 5, fill: "#00C9A7", strokeWidth: 2, stroke: "white" }}
          activeDot={{ r: 7, fill: "#00D4A2", stroke: "white", strokeWidth: 2 }}
        />
      </LineChart>
    </ResponsiveContainer>
  );
}
