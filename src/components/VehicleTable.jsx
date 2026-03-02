// ===== Format datetime (CHỈ 1 HÀM DUY NHẤT) =====
const formatDateTime = (isoString) => {
  if (!isoString || isoString === "null") return "-";

  const date = new Date(isoString);
  if (isNaN(date.getTime())) return "-";

  return date.toLocaleString("vi-VN", {
    day: "2-digit",
    month: "2-digit",
    year: "numeric",
    hour: "2-digit",
    minute: "2-digit",
    second: "2-digit",
    hour12: false,
  });
};

// ===== Component =====
export default function VehicleTable({ logs }) {
  if (!logs || Object.keys(logs).length === 0) {
    return <p>Không có xe nào</p>;
  }

  // ===== Helper =====
  const formatDuration = (hours) => {
    if (!hours) return "-";

    const totalSeconds = Math.round(hours * 3600);
    const minutes = Math.floor(totalSeconds / 60);
    const seconds = totalSeconds % 60;

    return `${minutes} phút ${seconds} giây`;
  };

  const formatMoney = (amount) => {
    if (!amount) return "-";
    return amount.toLocaleString("vi-VN") + " ₫";
  };

  const renderStatus = (status) => {
    if (status === "in") {
      return <span style={{ color: "green" }}>🟢 Trong bãi</span>;
    }
    if (status === "out") {
      return <span style={{ color: "red" }}>🔴 Đã ra</span>;
    }
    return status;
  };

  // ===== Parse & sort =====
  const sorted = Object.keys(logs)
    .map((key) => ({
      id: key,
      ...logs[key],
      timeValue: new Date(logs[key].checkInTime).getTime(),
    }))
    .sort((a, b) => b.timeValue - a.timeValue);

  // ===== Render =====
  return (
    <table
      border="1"
      cellPadding="8"
      style={{ width: "100%", marginTop: "20px", borderCollapse: "collapse" }}
    >
      <thead style={{ backgroundColor: "#0ea5a5", color: "white" }}>
        <tr>
          <th>Thẻ ID</th>
          <th>Biển số</th>
          <th>Giờ vào</th>
          <th>Giờ ra</th>
          <th>Trạng thái</th>
          <th>Thời gian gửi</th>
          <th>Tiền</th>
        </tr>
      </thead>

      <tbody>
        {sorted.map((log) => (
          <tr key={log.id}>
            <td>{log.cardId}</td>
            <td>{log.plateNumber}</td>
            <td>{formatDateTime(log.checkInTime)}</td>
            <td>{formatDateTime(log.checkOutTime)}</td>
            <td>{renderStatus(log.status)}</td>
            <td>{formatDuration(log.totalHours)}</td>
            <td>{formatMoney(log.amount)}</td>
          </tr>
        ))}
      </tbody>
    </table>
  );
}
