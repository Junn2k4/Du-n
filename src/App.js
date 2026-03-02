import { Routes, Route } from "react-router-dom";

// Pages
import Home from "./pages/Home";
import User from "./pages/User";
import Login from "./pages/Login";
import Register from "./pages/Register";
import Dashboard from "./pages/Dashboard";
import Cars from "./pages/Cars";
import Revenue from "./pages/Revenue";
import ForgotPassword from "./pages/ForgotPassword";
import VisualManagement from "./pages/VisualManagement"; // ✅ ĐÃ IMPORT

export default function App() {
  return (
    <Routes>
      <Route path="/" element={<Home />} />
      <Route path="/user" element={<User />} />

      {/* Auth */}
      <Route path="/login" element={<Login />} />
      <Route path="/register" element={<Register />} />
      <Route path="/forgot-password" element={<ForgotPassword />} />

      {/* Admin */}
      <Route path="/dashboard" element={<Dashboard />} />
      <Route path="/cars" element={<Cars />} />
      <Route path="/revenue" element={<Revenue />} />

      {/* ✅ ROUTE QUẢN LÝ TRỰC QUAN */}
      <Route path="/visual-management" element={<VisualManagement />} />
    </Routes>
  );
}
