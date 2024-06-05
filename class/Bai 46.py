class MachMUX:
  def __init__(self, ten_bo_hop_kenh, so_bit_dau_vao, so_bit_dau_ra):
    self.ten_bo_hop_kenh = ten_bo_hop_kenh
    self.so_bit_dau_vao = so_bit_dau_vao
    self.so_bit_dau_ra = so_bit_dau_ra

  def tinh_so_duong_dieu_khien(self):
    import math
    return math.log2(self.so_bit_dau_vao / self.so_bit_dau_ra)


def nhap_danh_sach_mux(n):
  danh_sach_mux = []
  for i in range(n):
    ten_mux = input(f"Nhập tên bộ hợp kênh thứ {i + 1}: ")
    bit_dau_vao = int(input(f"Nhập số bit đầu vào của {ten_mux}: "))
    bit_dau_ra = int(input(f"Nhập số bit đầu ra của {ten_mux}: "))
    mux = MachMUX(ten_mux, bit_dau_vao, bit_dau_ra)
    danh_sach_mux.append(mux)
  return danh_sach_mux


def in_danh_sach_mux(danh_sach_mux):
  print("\nDanh sách các bộ hợp kênh (MUX):")
  for mux in danh_sach_mux:
    print(
      f"Tên bộ hợp kênh: {mux.ten_bo_hop_kenh}, Số bit đầu vào: {mux.so_bit_dau_vao}, Số bit đầu ra: {mux.so_bit_dau_ra}, Số đường điều khiển: {mux.tinh_so_duong_dieu_khien():.2f}")


def sap_xep_theo_bit_dau_vao(danh_sach_mux):
  return sorted(danh_sach_mux, key=lambda x: x.so_bit_dau_vao, reverse=True)


def tim_mux_nhieu_duong_dieu_khien_nhat(danh_sach_mux):
  max_duong_dieu_khien = max(mux.tinh_so_duong_dieu_khien() for mux in danh_sach_mux)
  mux_nhieu_duong_dieu_khien = [mux for mux in danh_sach_mux if mux.tinh_so_duong_dieu_khien() == max_duong_dieu_khien]
  return tuple(mux_nhieu_duong_dieu_khien)


n = int(input("Nhập số lượng bộ hợp kênh (MUX): "))
danh_sach_mux = nhap_danh_sach_mux(n)
in_danh_sach_mux(danh_sach_mux)

danh_sach_mux_sap_xep = sap_xep_theo_bit_dau_vao(danh_sach_mux)
print("\nDanh sách sau khi sắp xếp theo số bit đầu vào:")
in_danh_sach_mux(danh_sach_mux_sap_xep)

mux_nhieu_duong_dieu_khien = tim_mux_nhieu_duong_dieu_khien_nhat(danh_sach_mux)
print(f"\nTuple chứa thông tin của bộ hợp kênh (MUX) có nhiều đường điều khiển nhất: {mux_nhieu_duong_dieu_khien}")
