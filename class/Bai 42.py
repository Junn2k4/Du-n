class ThoThuCong:
  def __init__(self, ten_tho, so_tham_det, don_gia):
    self.ten_tho = ten_tho
    self.so_tham_det = so_tham_det
    self.don_gia = don_gia

  def tinh_cong(self):
    return self.so_tham_det * self.don_gia


def nhap_danh_sach_tho(n):
  danh_sach_tho = []
  for i in range(n):
    ten_tho = input(f"Nhập tên thợ thứ {i + 1}: ")
    so_tham_det = int(input(f"Nhập số thảm đã dệt được của thợ {ten_tho}: "))
    don_gia = float(input(f"Nhập đơn giá của thảm (đơn vị: VNĐ): "))
    tho = ThoThuCong(ten_tho, so_tham_det, don_gia)
    danh_sach_tho.append(tho)
  return danh_sach_tho


def in_danh_sach_tho(danh_sach_tho):
  print("\nDanh sách thợ thủ công:")
  for tho in danh_sach_tho:
    print(f"Tên thợ: {tho.ten_tho}, Số thảm đã dệt được: {tho.so_tham_det}, Công: {tho.tinh_cong()} VNĐ")


def tim_tho_thu_nhap_cao_nhat(danh_sach_tho):
  max_cong = max(tho.tinh_cong() for tho in danh_sach_tho)
  tho_nhieu_cong = [tho for tho in danh_sach_tho if tho.tinh_cong() == max_cong]
  return tho_nhieu_cong


def tim_tho_tham_don_gia_nho_nhat(danh_sach_tho):
  min_don_gia = min(tho.don_gia for tho in danh_sach_tho)
  tho_don_gia_nho_nhat = [tho for tho in danh_sach_tho if tho.don_gia == min_don_gia]
  return tuple(tho_don_gia_nho_nhat)


n = int(input("Nhập số lượng thợ thủ công: "))
danh_sach_tho = nhap_danh_sach_tho(n)
in_danh_sach_tho(danh_sach_tho)

tho_nhieu_cong = tim_tho_thu_nhap_cao_nhat(danh_sach_tho)
print("\nThợ có thu nhập cao nhất:")
for tho in tho_nhieu_cong:
  print(f"Tên thợ: {tho.ten_tho}, Công: {tho.tinh_cong()} VNĐ")

tho_don_gia_nho_nhat = tim_tho_tham_don_gia_nho_nhat(danh_sach_tho)
print(f"\nTuple chứa danh sách thợ dệt được loại thảm có đơn giá nhỏ nhất: {tho_don_gia_nho_nhat}")
