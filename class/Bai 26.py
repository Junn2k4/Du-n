class SinhVien:
    def __init__(self, ten, ma_sv, diem_thuc_tap, diem_do_an):
        self.ten = ten
        self.ma_sv = ma_sv
        self.diem_thuc_tap = diem_thuc_tap
        self.diem_do_an = diem_do_an
    def tinh_diem_tb(self):
        diem_tb = (7 * self.diem_thuc_tap + 8 * self.diem_do_an) / 15
        return diem_tb
# Nhập danh sách sinh viên
n = int(input("Nhập số lượng sinh viên: "))
sinh_vien_list = []
for i in range(n):
    print(f"Nhập thông tin cho sinh viên thứ {i + 1}:")
    ten = input("Tên: ")
    ma_sv = input("Mã sinh viên: ")
    diem_thuc_tap = float(input("Điểm thực tập: "))
    diem_do_an = float(input("Điểm đồ án: "))
    sinh_vien = SinhVien(ten, ma_sv, diem_thuc_tap, diem_do_an)
    sinh_vien_list.append(sinh_vien)
# In danh sách sinh viên vừa nhập
print("\nDanh sách sinh viên vừa nhập:")
for i, sv in enumerate(sinh_vien_list):
    print(f"Sinh viên {i + 1}: {sv.ten}, Mã sinh viên: {sv.ma_sv}, Điểm thực tập: {sv.diem_thuc_tap}, Điểm đồ án: {sv.diem_do_an}")
# Sắp xếp danh sách sinh viên theo thứ tự giảm dần của điểm TB
sinh_vien_list.sort(key=lambda x: x.tinh_diem_tb(), reverse=True)
# In danh sách sinh viên sau khi sắp xếp
print("\nDanh sách sinh viên sau khi sắp xếp theo điểm TB giảm dần:")
for i, sv in enumerate(sinh_vien_list):
    print(f"Sinh viên {i + 1}: {sv.ten}, Mã sinh viên: {sv.ma_sv}, Điểm TB: {sv.tinh_diem_tb()}")
# Xóa tên các sinh viên có điểm TB < 4.0
sinh_vien_list = [sv for sv in sinh_vien_list if sv.tinh_diem_tb() >= 4.0]
# In danh sách sinh viên sau khi xóa
print("\nDanh sách sinh viên sau khi xóa các sinh viên có điểm TB < 4.0:")
for i, sv in enumerate(sinh_vien_list):
    print(f"Sinh viên {i + 1}: {sv.ten}, Mã sinh viên: {sv.ma_sv}, Điểm TB: {sv.tinh_diem_tb()}")
