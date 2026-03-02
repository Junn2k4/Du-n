import { useState } from "react";
import { sendPasswordResetEmail } from "firebase/auth";
import { auth } from "../firebase";
import { useNavigate } from "react-router-dom";

export default function ForgotPassword() {
  const [email, setEmail] = useState("");
  const [message, setMessage] = useState("");
  const [loading, setLoading] = useState(false);
  const navigate = useNavigate();

  const handleReset = async () => {
    setMessage("");
    if (!email) {
      setMessage("❌ Vui lòng nhập email!");
      return;
    }

    try {
      setLoading(true);
      await sendPasswordResetEmail(auth, email);
      setMessage("✅ Email khôi phục mật khẩu đã được gửi!");
    } catch (error) {
      setMessage("❌ Email không tồn tại hoặc lỗi xảy ra!");
    } finally {
      setLoading(false);
    }
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
          maxWidth: "380px",
          background: "#ffffff",
          borderRadius: "18px",
          padding: "35px 30px",
          boxShadow: "0 10px 25px rgba(0, 0, 0, 0.15)",
          position: "relative",
          animation: "fadeIn 0.4s ease",
        }}
      >
        {/* ✅ Nút quay lại */}
        <button
          onClick={() => navigate(-1)}
          style={{
            position: "absolute",
            top: "12px",
            left: "12px",
            background: "transparent",
            border: "none",
            fontSize: "20px",
            cursor: "pointer",
            color: "#00a89e",
          }}
        >
          ←
        </button>

        <h2 style={{ marginBottom: "10px", color: "#00a89e", textAlign: "center" }}>
          🔑 Khôi phục mật khẩu
        </h2>

        <p style={{ color: "#666", marginBottom: "25px", textAlign: "center" }}>
          Nhập email để nhận liên kết đặt lại mật khẩu
        </p>

        <input
          type="email"
          placeholder="Nhập email"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
          style={{
            width: "100%",
            padding: "12px 15px",
            marginBottom: "20px",
            borderRadius: "12px",
            border: "1px solid #dcdcdc",
            fontSize: "15px",
            outline: "none",
          }}
        />

        <button
          onClick={handleReset}
          disabled={loading}
          style={{
            width: "100%",
            background: loading ? "#018f71" : "#00A885",
            color: "#fff",
            padding: "12px 0",
            border: "none",
            borderRadius: "12px",
            fontSize: "16px",
            fontWeight: "bold",
            cursor: loading ? "not-allowed" : "pointer",
            transition: "0.25s",
          }}
        >
          {loading ? "Đang gửi…" : "Gửi email khôi phục"}
        </button>

        {message && (
          <p
            style={{
              color: message.includes("✅") ? "green" : "red",
              marginTop: "15px",
              fontSize: "14px",
              textAlign: "center",
            }}
          >
            {message}
          </p>
        )}

        <p
          style={{
            textAlign: "center",
            marginTop: "20px",
            cursor: "pointer",
            color: "#009f94",
            fontSize: "14px",
            fontWeight: "500",
          }}
          onClick={() => navigate("/login")}
        >
          ← Quay lại đăng nhập
        </p>
      </div>
    </div>
  );
}
