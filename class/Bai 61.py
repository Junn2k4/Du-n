class TauCa:
  def __init__(self, ten_tau, so_lit_dau, don_gia_dau, so_tien_ban_ca, ty_le_chi_phi=5):
    self.ten_tau = ten_tau
    self.so_lit_dau = so_lit_dau
    self.don_gia_dau = don_gia_dau
    self.so_tien_ban_ca = so_tien_ban_ca
    self.ty_le_chi_phi = ty_le_chi_phi

  def co_lai(self):
    return self.so_tien_ban_ca >= self.so_lit_dau * self.don_gia_dau * self.ty_le_chi_phi


def in_danh_sach_tau_ca(danh_sach):
  print("Danh sách tàu cá:")
  for tau_ca in danh_sach:
    print(
      f"Tên tàu: {tau_ca.ten_tau}, Số lít dầu tiêu thụ: {tau_ca.so_lit_dau}, Đơn giá dầu: {tau_ca.don_gia_dau}đ, Số tiền bán cá: {tau_ca.so_tien_ban_ca}đ")


def tao_tuple_tau_co_lai(danh_sach):
  return tuple(tau_ca for tau_ca in danh_sach if tau_ca.co_lai())


def sap_xep_danh_sach(danh_sach):
  return sorted(danh_sach, key=lambda x: x.so_tien_ban_ca)


def main():
  # Nhập số lượng tàu cá
  n = int(input("Nhập số lượng tàu cá: "))

  # Nhập danh sách tàu cá
  danh_sach_tau_ca = []
  for i in range(n):
    ten_tau = input(f"Nhập tên tàu của tàu cá thứ {i + 1}: ")
    so_lit_dau = float(input(f"Nhập số lít dầu tiêu thụ của tàu cá thứ {i + 1}: "))
    don_gia_dau = float(input(f"Nhập đơn giá dầu của tàu cá thứ {i + 1}: "))
    so_tien_ban_ca = float(input(f"Nhập số tiền bán cá của tàu cá thứ {i + 1}: "))
    danh_sach_tau_ca.append(TauCa(ten_tau, so_lit_dau, don_gia_dau, so_tien_ban_ca))

  # In danh sách tàu cá
  in_danh_sach_tau_ca(danh_sach_tau_ca)

  # Tạo tuple chứa danh sách các tàu cá có lãi
  tuple_tau_co_lai = tao_tuple_tau_co_lai(danh_sach_tau_ca)
  print("\nTuple chứa danh sách các tàu cá có lãi:")
  print(tuple_tau_co_lai)

  # Sắp xếp danh sách theo thứ tự tăng dần của số tiền thu về
  danh_sach_sap_xep = sap_xep_danh_sach(danh_sach_tau_ca)
  print("\nDanh sách tàu cá sau khi sắp xếp:")
  in_danh_sach_tau_ca(danh_sach_sap_xep)


if __name__ == "__main__":
  main()
