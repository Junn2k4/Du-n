class BoDem:
  def __init__(self, ten, Kd, loai_FF):
    self.ten = ten
    self.Kd = Kd
    self.loai_FF = loai_FF

  def tinh_so_FF(self):
    if self.loai_FF == "JKFF":
      return 2
    elif self.loai_FF == "RSFF":
      return 2
    elif self.loai_FF == "DFF":
      return 1
    elif self.loai_FF == "TFF":
      return 1


def in_danh_sach_bodem_JKFF(danh_sach):
  print("Danh sách các bộ đếm được tạo thành từ JKFF:")
  for bodem in danh_sach:
    if bodem.loai_FF == "JKFF":
      print(f"Tên: {bodem.ten}, Kđ: {bodem.Kd}, Loại Flip flop: {bodem.loai_FF}")


def sap_xep_danh_sach(danh_sach):
  return sorted(danh_sach, key=lambda x: x.Kd, reverse=True)


def xoa_bodem_kd_10(danh_sach):
  danh_sach = [bodem for bodem in danh_sach if bodem.Kd != 10]
  return danh_sach


def main():
  # Nhập số lượng bộ đếm
  n = int(input("Nhập số lượng bộ đếm: "))

  # Nhập danh sách bộ đếm
  danh_sach_bodem = []
  for i in range(n):
    ten = input(f"Nhập tên bộ đếm thứ {i + 1}: ")
    Kd = int(input(f"Nhập Kđ của bộ đếm {ten}: "))
    loai_FF = input(f"Nhập loại Flip flop của bộ đếm {ten} (JKFF, RSFF, DFF, TFF): ")
    danh_sach_bodem.append(BoDem(ten, Kd, loai_FF))

  # In danh sách bộ đếm được tạo thành từ JKFF
  in_danh_sach_bodem_JKFF(danh_sach_bodem)

  # Sắp xếp danh sách bộ đếm theo thứ tự giảm dần của Kđ
  danh_sach_sap_xep = sap_xep_danh_sach(danh_sach_bodem)
  print("\nDanh sách bộ đếm sau khi sắp xếp:")
  for bodem in danh_sach_sap_xep:
    print(f"Tên: {bodem.ten}, Kđ: {bodem.Kd}, Loại Flip flop: {bodem.loai_FF}")

  # Xóa khỏi danh sách các bộ đếm có Kđ = 10
  danh_sach_bodem = xoa_bodem_kd_10(danh_sach_bodem)
  print("\nDanh sách bộ đếm sau khi xóa các bộ đếm có Kđ = 10:")
  for bodem in danh_sach_bodem:
    print(f"Tên: {bodem.ten}, Kđ: {bodem.Kd}, Loại Flip flop: {bodem.loai_FF}")


if __name__ == "__main__":
  main()
