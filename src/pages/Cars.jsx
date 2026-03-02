import React, { useEffect, useState } from "react";
import { db } from "../firebase";
import { ref, onValue, push, update, remove } from "firebase/database";
import { useNavigate } from "react-router-dom";
import * as XLSX from "xlsx";

/* ===== FORMAT ===== */
const formatDateTime = (isoString) => {
  if (!isoString) return "-";
  const d = new Date(isoString);
  if (isNaN(d.getTime())) return "-";
  return `${String(d.getHours()).padStart(2,"0")}:${String(d.getMinutes()).padStart(2,"0")}:${String(d.getSeconds()).padStart(2,"0")} ${String(d.getDate()).padStart(2,"0")}/${String(d.getMonth()+1).padStart(2,"0")}/${d.getFullYear()}`;
};

const formatDuration = (hours) => {
  if (!hours) return "-";
  const totalSeconds = Math.round(hours * 3600);
  const minutes = Math.floor(totalSeconds / 60);
  const seconds = totalSeconds % 60;
  return `${minutes} phút ${seconds} giây`;
};

const formatMoney = (money) => {
  if (!money) return "-";
  return Number(money).toLocaleString("vi-VN") + " VND";
};

export default function Dashboard() {
  const [plate, setPlate] = useState("-");
  const [camError, setCamError] = useState(false);

  const [logs, setLogs] = useState({});
  const [searchPlate, setSearchPlate] = useState("");
  const [searchDate, setSearchDate] = useState("");

  const [showForm, setShowForm] = useState(false);
  const [editingId, setEditingId] = useState(null);
  const [formData, setFormData] = useState({ cardId: "", plateNumber: "" });

  const CAM_URL = "http://127.0.0.1:5000/video";
  const navigate = useNavigate();

  /* ===== CAMERA ===== */
  useEffect(() => {
    const plateRef = ref(db, "latest_plate_candidates");
    return onValue(plateRef, (snap) => {
      if (snap.exists() && snap.val().plate) setPlate(snap.val().plate);
      else setPlate("-");
    });
  }, []);

  /* ===== LOGS ===== */
  useEffect(() => {
    const logsRef = ref(db, "parkingLogs");
    onValue(logsRef, (snapshot) => {
      setLogs(snapshot.exists() ? snapshot.val() : {});
    });
  }, []);

  const filtered = Object.keys(logs)
    .map((key) => ({ id: key, ...logs[key] }))
    .filter((row) => {
      if (searchPlate && !row.plateNumber?.toLowerCase().includes(searchPlate.toLowerCase())) return false;
      if (searchDate && row.checkInTime?.split("T")[0] !== searchDate) return false;
      return true;
    })
    .sort((a,b) => new Date(b.checkInTime) - new Date(a.checkInTime));

  /* ===== CRUD ===== */
  const handleSave = async () => {
    if (!formData.cardId || !formData.plateNumber)
      return alert("Nhập đầy đủ thông tin");

    if (editingId) {
      await update(ref(db, `parkingLogs/${editingId}`), {
        cardId: formData.cardId,
        plateNumber: formData.plateNumber
      });
    } else {
      await push(ref(db, "parkingLogs"), {
        cardId: formData.cardId,
        plateNumber: formData.plateNumber,
        checkInTime: new Date().toISOString(),
        checkOutTime: null,
        status: "in",
        totalHours: null,
        amount: null
      });
    }
    resetForm();
  };

  const handleDelete = async (id) => {
    if (window.confirm("Bạn có chắc muốn xóa?"))
      await remove(ref(db, `parkingLogs/${id}`));
  };

  const resetForm = () => {
    setShowForm(false);
    setEditingId(null);
    setFormData({ cardId: "", plateNumber: "" });
  };

  /* ===== EXPORT EXCEL ===== */
  const handleExportExcel = () => {
    if (!filtered.length) return alert("Không có dữ liệu để xuất");

    const data = filtered.map((row, i) => ({
      STT: i + 1,
      "UID RFID": row.cardId,
      "Biển số": row.plateNumber,
      "Giờ vào": formatDateTime(row.checkInTime),
      "Giờ ra": formatDateTime(row.checkOutTime),
      "Trạng thái": row.status === "in" ? "Đang gửi" : "Đã rời bãi",
      "Thời gian gửi": formatDuration(row.totalHours),
      "Số tiền (VND)": row.amount || 0,
    }));

    const ws = XLSX.utils.json_to_sheet(data);
    const wb = XLSX.utils.book_new();
    XLSX.utils.book_append_sheet(wb, ws, "DanhSachXe");

    const today = new Date().toISOString().split("T")[0];
    XLSX.writeFile(wb, `Danh_sach_xe_${today}.xlsx`);
  };

  return (
    <div style={container}>
      <h1 style={title}>🚗 Quản lý bãi xe</h1>

      <div style={main}>
        {/* CAMERA */}
        <div style={cameraBox}>
          <h3 style={cameraTitle}>📷 Camera</h3>
          {!camError ? (
            <img src={CAM_URL} style={camera} onError={()=>setCamError(true)} />
          ) : (
            <div style={camFallback}>❌ Không kết nối Camera</div>
          )}

          <div style={plateBox}>
            <div style={plateDisplay}>{plate}</div>
          </div>
        </div>

        {/* LIST */}
        <div style={listBox}>
          <div style={row}>
            <input placeholder="Tìm biển số" value={searchPlate} onChange={e=>setSearchPlate(e.target.value)} style={input} />
            <input type="date" value={searchDate} onChange={e=>setSearchDate(e.target.value)} style={input} />
            <button style={btn} onClick={()=>{setSearchPlate("");setSearchDate("")}}>Reset</button>
            <button style={btn} onClick={()=>setShowForm(true)}>➕ Thêm</button>
            <button style={btn} onClick={handleExportExcel}>📥 Xuất Excel</button>
          </div>

          {showForm && (
            <div style={formBox}>
              <input placeholder="UID RFID" value={formData.cardId} onChange={e=>setFormData({...formData,cardId:e.target.value})} style={input} />
              <input placeholder="Biển số" value={formData.plateNumber} onChange={e=>setFormData({...formData,plateNumber:e.target.value})} style={input} />
              <div>
                <button style={btn} onClick={handleSave}>💾 Lưu</button>
                <button style={btnGray} onClick={resetForm}>❌ Hủy</button>
              </div>
            </div>
          )}

          <div style={tableBox}>
            <table style={table}>
              <thead>
                <tr style={{background:"#0AAB8B",color:"#fff"}}>
                  <th>RFID</th><th>Biển số</th><th>Giờ vào</th><th>Giờ ra</th>
                  <th>Trạng thái</th><th>Thời gian</th><th>Tiền</th><th></th>
                </tr>
              </thead>
              <tbody>
                {filtered.length ? filtered.map(r=>(
                  <tr key={r.id} style={{textAlign:"center"}}>
                    <td>{r.cardId}</td>
                    <td>{r.plateNumber}</td>
                    <td>{formatDateTime(r.checkInTime)}</td>
                    <td>{formatDateTime(r.checkOutTime)}</td>
                    <td style={{color:r.status==="in"?"green":"red"}}>
                      {r.status==="in"?"Đang gửi":"Đã rời"}
                    </td>
                    <td>{formatDuration(r.totalHours)}</td>
                    <td>{formatMoney(r.amount)}</td>
                    <td>
                      <button onClick={()=>{setShowForm(true);setEditingId(r.id);setFormData({cardId:r.cardId,plateNumber:r.plateNumber})}}>✏️</button>
                      <button onClick={()=>handleDelete(r.id)}>🗑️</button>
                    </td>
                  </tr>
                )) : (
                  <tr><td colSpan={8}>Không có dữ liệu</td></tr>
                )}
              </tbody>
            </table>
          </div>

          <button style={btnBack} onClick={()=>navigate("/dashboard")}>⬅ Quay lại</button>
        </div>
      </div>
    </div>
  );
}

/* ===== STYLE ===== */
const container={padding:30,maxWidth:1300,margin:"auto",background:"#e6f5f1",borderRadius:15};
const title={textAlign:"center",color:"#0AAB8B",marginBottom:20};
const main={display:"flex",gap:20,flexWrap:"wrap"};
const cameraBox={flex:2,background:"#0AAB8B",padding:20,borderRadius:15,color:"#fff"};
const cameraTitle={marginBottom:10};
const camera={width:"100%",borderRadius:12};
const camFallback={height:300,display:"flex",alignItems:"center",justifyContent:"center",background:"#fee2e2",color:"#b91c1c"};
const plateBox={marginTop:15,textAlign:"center"};
const plateDisplay={fontSize:36,fontWeight:"bold",background:"#10b981",padding:"10px 20px",borderRadius:12};
const listBox={flex:3,display:"flex",flexDirection:"column",gap:10};
const row={display:"flex",gap:10};
const input={padding:10,borderRadius:8,border:"1px solid #ccc",flex:1};
const btn={background:"#0AAB8B",color:"#fff",border:"none",padding:"10px 15px",borderRadius:8,cursor:"pointer"};
const btnGray={...btn,background:"#999"};
const btnBack={...btn,marginTop:10,width:150};
const tableBox={border:"1px solid #ddd",borderRadius:12,overflowX:"auto"};
const table={width:"100%",borderCollapse:"collapse"};
const formBox={padding:15,border:"1px solid #ddd",borderRadius:10,display:"flex",flexDirection:"column",gap:10};
