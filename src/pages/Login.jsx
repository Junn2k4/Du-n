import { useState } from "react";
import { useNavigate } from "react-router-dom";
import { auth } from "../firebase";
import { signInWithEmailAndPassword } from "firebase/auth";

export default function AdminLogin() {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");
  const [showPass, setShowPass] = useState(false);
  const [loading, setLoading] = useState(false);
  const navigate = useNavigate();

  const handleLogin = async (e) => {
    e.preventDefault();
    setError("");

    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!email) return setError("Vui lòng nhập email!");
    if (!emailRegex.test(email)) return setError("Email không hợp lệ!");
    if (!password) return setError("Vui lòng nhập mật khẩu!");

    try {
      setLoading(true);
      await signInWithEmailAndPassword(auth, email, password);
      navigate("/dashboard");
    } catch (err) {
      setError("Sai email hoặc mật khẩu!");
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
          🔑 Admin Login
        </h2>

        <p style={{ color: "#666", marginBottom: "25px", textAlign: "center" }}>
          Hệ thống quản lý Smart Parking
        </p>

        <form onSubmit={handleLogin}>
          {/* Email */}
          <input
            type="email"
            placeholder="Nhập email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            style={{
              width: "100%",
              padding: "12px 15px",
              marginBottom: "15px",
              borderRadius: "12px",
              border: "1px solid #dcdcdc",
              fontSize: "15px",
              outline: "none",
            }}
          />

          {/* Password + icon */}
          <div style={{ position: "relative", width: "100%", marginBottom: "10px" }}>
            <input
              type={showPass ? "text" : "password"}
              placeholder="Mật khẩu"
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              style={{
                width: "100%",
                padding: "12px 15px",
                paddingRight: "15px",
                borderRadius: "12px",
                border: "1px solid #dcdcdc",
                fontSize: "15px",
                outline: "none",
              }}
            />

            <div
              onClick={() => setShowPass(!showPass)}
              style={{
                position: "absolute",
                right: "12px",
                top: "50%",
                transform: "translateY(-50%)",
                height: "26px",
                width: "26px",
                display: "flex",
                justifyContent: "center",
                alignItems: "center",
                cursor: "pointer",
                borderRadius: "50%",
                background: "#f2f2f2",
                fontSize: "15px",
                color: "#444",
              }}
            >
              {showPass ? "🙈" : "👁️"}
            </div>
          </div>

          {/* ✅ Quên mật khẩu */}
          <p
            onClick={() => navigate("/forgot-password")}
            style={{
              textAlign: "right",
              marginBottom: "20px",
              cursor: "pointer",
              color: "#009f94",
              fontSize: "14px",
              fontWeight: "500",
            }}
          >
            Quên mật khẩu?
          </p>

          {/* Submit button */}
          <button
            type="submit"
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
            {loading ? "Đang đăng nhập…" : "Đăng nhập"}
          </button>
        </form>

        {error && (
          <p style={{ color: "red", marginTop: "15px", fontSize: "14px", textAlign: "center" }}>
            {error}
          </p>
        )}
      </div>
    </div>
  );
}
