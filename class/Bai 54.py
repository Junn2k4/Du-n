class HinhHopChuNhat:
  def __init__(self, chieu_dai, chieu_rong, do_cao):
    self.chieu_dai = chieu_dai
    self.chieu_rong = chieu_rong
    self.do_cao = do_cao

  def dien_tich_toan_phan(self):
    # Diện tích toàn phần = 2 * (diện tích xung quanh + diện tích đáy)
    dien_tich_xung_quanh = 2 * (self.chieu_dai * self.do_cao + self.chieu_rong * self.do_cao)
    dien_tich_day = self.chieu_dai * self.chieu_rong
    return dien_tich_xung_quanh + 2 * dien_tich_day

  def the_tich(self):
    # Thể tích = diện tích đáy * chiều cao
    return self.chieu_dai * self.chieu_rong * self.do_cao


# Nhập danh sách hình hộp chữ nhật
n = int(input("Nhập số lượng hình hộp chữ nhật: "))
danh_sach_hinh_hop_chu_nhat = []
for i in range(n):
  print(f"Nhập thông tin cho hình hộp chữ nhật thứ {i + 1}:")
  chieu_dai = float(input("Chiều dài: "))
  chieu_rong = float(input("Chiều rộng: "))
  do_cao = float(input("Độ cao: "))
  hinh_hop_chu_nhat = HinhHopChuNhat(chieu_dai, chieu_rong, do_cao)
  danh_sach_hinh_hop_chu_nhat.append(hinh_hop_chu_nhat)

# In danh sách vừa nhập
print("\nDanh sách hình hộp chữ nhật:")
for i, hinh_hop_chu_nhat in enumerate(danh_sach_hinh_hop_chu_nhat):
  print(
    f"Hình {i + 1}: Chiều dài = {hinh_hop_chu_nhat.chieu_dai}, Chiều rộng = {hinh_hop_chu_nhat.chieu_rong}, Độ cao = {hinh_hop_chu_nhat.do_cao}")

# Tạo 1 tuple chứa các hình có thể tích > 50
hinh_hop_chu_nhat_tich_lon = tuple(filter(lambda h: h.the_tich() > 50, danh_sach_hinh_hop_chu_nhat))
print("\nCác hình có thể tích > 50:")
for i, hinh in enumerate(hinh_hop_chu_nhat_tich_lon):
  print(f"Hình {i + 1}: Thể tích = {hinh.the_tich()}")

# Sắp xếp danh sách theo thứ tự giảm dẫn của thể tích
danh_sach_hinh_hop_chu_nhat.sort(key=lambda h: h.the_tich(), reverse=True)
print("\nDanh sách hình hộp chữ nhật sau khi sắp xếp:")
for i, hinh in enumerate(danh_sach_hinh_hop_chu_nhat):
  print(f"Hình {i + 1}: Thể tích = {hinh.the_tich()}")
