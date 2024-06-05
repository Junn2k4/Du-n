class MonHoc:
  def __init__(self, ten_mon_hoc, so_tin_chi, he_so, don_gia_tin_chi=100000):
    self.ten_mon_hoc = ten_mon_hoc
    self.so_tin_chi = so_tin_chi
    self.he_so = he_so
    self.don_gia_tin_chi = don_gia_tin_chi

  def tinh_hoc_phi(self):
    return self.so_tin_chi * self.he_so * self.don_gia_tin_chi


def in_danh_sach_mon_hoc(danh_sach):
  print("Danh sách môn học:")
  for mon_hoc in danh_sach:
    print(
      f"Tên môn học: {mon_hoc.ten_mon_hoc}, Số tín chỉ: {mon_hoc.so_tin_chi}, Hệ số: {mon_hoc.he_so}, Học phí: {mon_hoc.tinh_hoc_phi()}")


def tinh_tong_hoc_phi(danh_sach):
  tong_hoc_phi = sum(mon_hoc.tinh_hoc_phi() for mon_hoc in danh_sach)
  print(f"Tổng học phí của n môn học là: {tong_hoc_phi}")


def tao_dictionary_hoc_phi(danh_sach):
  max_so_tin_chi = max(mon_hoc.so_tin_chi for mon_hoc in danh_sach)
  dictionary = {}
  for mon_hoc in danh_sach:
    if mon_hoc.so_tin_chi == max_so_tin_chi:
      dictionary[mon_hoc.ten_mon_hoc] = mon_hoc.tinh_hoc_phi()
  return dictionary


def main():
  # Nhập số lượng môn học
  n = int(input("Nhập số lượng môn học: "))

  # Nhập danh sách môn học
  danh_sach_mon_hoc = []
  for i in range(n):
    ten_mon_hoc = input(f"Nhập tên môn học thứ {i + 1}: ")
    so_tin_chi = int(input(f"Nhập số tín chỉ của môn học {ten_mon_hoc}: "))
    he_so = float(input(f"Nhập hệ số của môn học {ten_mon_hoc}: "))
    danh_sach_mon_hoc.append(MonHoc(ten_mon_hoc, so_tin_chi, he_so))

  # In danh sách môn học
  in_danh_sach_mon_hoc(danh_sach_mon_hoc)

  # Tính tổng học phí của n môn học
  tinh_tong_hoc_phi(danh_sach_mon_hoc)

  # Tạo dictionary có key là tên môn và value là học phí của các môn có số tín chỉ nhiều nhất
  dictionary_hoc_phi = tao_dictionary_hoc_phi(danh_sach_mon_hoc)
  print("\nDictionary học phí của các môn có số tín chỉ nhiều nhất:")
  print(dictionary_hoc_phi)


if __name__ == "__main__":
  main()
