class HoaQua:
  def __init__(self, loai_qua, gia_thanh, so_luong, chat_luong):
    self.loai_qua = loai_qua
    self.gia_thanh = gia_thanh
    self.so_luong = so_luong
    self.chat_luong = chat_luong

  def tien_thu_duoc(self):
    if self.chat_luong == 1:
      return self.so_luong * self.gia_thanh
    elif self.chat_luong == 2:
      return self.so_luong * self.gia_thanh * 0.8


# Nhập danh sách hoa quả
n = int(input("Nhập số lượng loại quả: "))
danh_sach_hoa_qua = []
for i in range(n):
  loai_qua = input(f"Nhập tên loại quả thứ {i + 1}: ")
  gia_thanh = float(input(f"Nhập giá thành (đồng/kg) cho {loai_qua}: "))
  so_luong = float(input(f"Nhập số lượng (kg) cho {loai_qua}: "))
  chat_luong = int(input(f"Nhập chất lượng (1: loại 1, 2: loại 2) cho {loai_qua}: "))
  hoa_qua = HoaQua(loai_qua, gia_thanh, so_luong, chat_luong)
  danh_sach_hoa_qua.append(hoa_qua)

# In danh sách vừa nhập
print("\nDanh sách hoa quả:")
for hoa_qua in danh_sach_hoa_qua:
  print(
    f"{hoa_qua.loai_qua}: Giá thành = {hoa_qua.gia_thanh} đồng/kg, Số lượng = {hoa_qua.so_luong} kg, Chất lượng = {hoa_qua.chat_luong}")

# Tạo dictionary chứa số tiền thu được tương ứng với từng loại quả
tien_thu_duoc_dict = {hoa_qua.loai_qua: hoa_qua.tien_thu_duoc() for hoa_qua in danh_sach_hoa_qua}
print("\nSố tiền thu được cho từng loại quả:")
for loai_qua, tien_thu_duoc in tien_thu_duoc_dict.items():
  print(f"{loai_qua}: {tien_thu_duoc} đồng")

# Sắp xếp danh sách theo thứ tự giảm dần của số lượng
danh_sach_hoa_qua.sort(key=lambda hoa_qua: hoa_qua.so_luong, reverse=True)
print("\nDanh sách sau khi sắp xếp:")
for hoa_qua in danh_sach_hoa_qua:
  print(f"{hoa_qua.loai_qua}: Số lượng = {hoa_qua.so_luong} kg")
