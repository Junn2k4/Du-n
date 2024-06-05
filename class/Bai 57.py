class LoApTrung:
  def __init__(self, k, t, x, y):
    self.k = k
    self.t = t
    self.x = x
    self.y = y

  def tinh_so_tien_thu_ve(self):
    so_trung_ap = self.k
    so_trung_no = int(self.k * (self.t / 100))
    so_trung_hong = self.k - so_trung_no
    return so_trung_no * self.x + so_trung_hong * self.y


def in_danh_sach_lo_ap_trung(danh_sach):
  print("Danh sách lò ấp trứng:")
  for lo in danh_sach:
    print(
      f"Số trứng ấp: {lo.k}, Hiệu suất nở con: {lo.t}%, Giá vịt nở: {lo.x}đ, Giá trứng hỏng: {lo.y}đ, Số tiền thu về: {lo.tinh_so_tien_thu_ve()}đ")


def tao_tuple_so_tien_thu_ve(danh_sach):
  return tuple(lo.tinh_so_tien_thu_ve() for lo in danh_sach)


def sap_xep_danh_sach(danh_sach):
  return sorted(danh_sach, key=lambda x: x.k, reverse=True)


def main():
  # Nhập số lượng lò ấp trứng
  n = int(input("Nhập số lượng lò ấp trứng: "))

  # Nhập danh sách lò ấp trứng
  danh_sach_lo_ap_trung = []
  for i in range(n):
    k = int(input(f"Nhập số trứng ấp của lò ấp trứng thứ {i + 1}: "))
    t = float(input(f"Nhập hiệu suất nở con của lò ấp trứng thứ {i + 1} (%): "))
    x = float(input(f"Nhập giá vịt nở của lò ấp trứng thứ {i + 1} (đồng): "))
    y = float(input(f"Nhập giá trứng hỏng của lò ấp trứng thứ {i + 1} (đồng): "))
    danh_sach_lo_ap_trung.append(LoApTrung(k, t, x, y))

  # In danh sách lò ấp trứng
  in_danh_sach_lo_ap_trung(danh_sach_lo_ap_trung)

  # Tạo tuple chứa số tiền thu về trong danh sách trên
  tuple_so_tien_thu_ve = tao_tuple_so_tien_thu_ve(danh_sach_lo_ap_trung)
  print("\nTuple chứa số tiền thu về trong danh sách trên:")
  print(tuple_so_tien_thu_ve)

  # Sắp xếp danh sách theo thứ tự giảm dần của số lượng trứng hỏng
  danh_sach_sap_xep = sap_xep_danh_sach(danh_sach_lo_ap_trung)
  print("\nDanh sách lò ấp trứng sau khi sắp xếp:")
  in_danh_sach_lo_ap_trung(danh_sach_sap_xep)


if __name__ == "__main__":
  main()
