class PhuongTrinhBacNhat:
  def __init__(self, a, b):
    self.a = a
    self.b = b

  def tim_nghiem(self):
    if self.a == 0:
      if self.b == 0:
        return "Vô số nghiệm"
      else:
        return "Vô nghiệm"
    else:
      return -self.b / self.a


def in_danh_sach_phuong_trinh(danh_sach):
  print("Danh sách phương trình:")
  for pt in danh_sach:
    print(f"Phương trình: {pt.a}x + {pt.b} = 0")


def tao_tuple_nghiem_duong(danh_sach):
  nghiem_duong = tuple(pt.tim_nghiem() for pt in danh_sach if pt.tim_nghiem() > 0)
  return nghiem_duong


def dem_vo_nghiem_vo_so_nghiem(danh_sach):
  count_vo_nghiem = sum(1 for pt in danh_sach if pt.tim_nghiem() == "Vô nghiệm")
  count_vo_so_nghiem = sum(1 for pt in danh_sach if pt.tim_nghiem() == "Vô số nghiệm")
  return count_vo_nghiem, count_vo_so_nghiem


def main():
  # Nhập số lượng phương trình
  n = int(input("Nhập số lượng phương trình: "))

  # Nhập danh sách phương trình
  danh_sach_phuong_trinh = []
  for i in range(n):
    a = float(input(f"Nhập hệ số a của phương trình thứ {i + 1}: "))
    b = float(input(f"Nhập hệ số b của phương trình thứ {i + 1}: "))
    danh_sach_phuong_trinh.append(PhuongTrinhBacNhat(a, b))

  # In danh sách phương trình
  in_danh_sach_phuong_trinh(danh_sach_phuong_trinh)

  # Tạo tuple chứa các nghiệm dương của các phương trình trong danh sách
  nghiem_duong = tao_tuple_nghiem_duong(danh_sach_phuong_trinh)
  print("\nTuple chứa các nghiệm dương của các phương trình trong danh sách:")
  print(nghiem_duong)

  # Đếm số lượng phương trình vô nghiệm và vô số nghiệm trong danh sách
  count_vo_nghiem, count_vo_so_nghiem = dem_vo_nghiem_vo_so_nghiem(danh_sach_phuong_trinh)
  print(f"\nSố lượng phương trình vô nghiệm trong danh sách: {count_vo_nghiem}")
  print(f"Số lượng phương trình vô số nghiệm trong danh sách: {count_vo_so_nghiem}")


if __name__ == "__main__":
  main()
