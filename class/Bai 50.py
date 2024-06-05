import math

class MachLocThongThapRC:
    def __init__(self, ten, R, C):
        self.ten = ten
        self.R = R
        self.C = C

    def tinh_tan_so_cat(self):
        return 1 / (2 * math.pi * self.R * self.C)

def in_danh_sach_mach_loc(danh_sach):
    print("Danh sách mạch lọc:")
    for mach_loc in danh_sach:
        print(f"Tên: {mach_loc.ten}, R: {mach_loc.R}, C: {mach_loc.C}, Tần số cắt: {mach_loc.tinh_tan_so_cat()}")

def sap_xep_danh_sach(danh_sach):
    return sorted(danh_sach, key=lambda x: x.R, reverse=True)

def tim_mach_dai_thong_nhat(danh_sach):
    if danh_sach:
        mach_loc_max = max(danh_sach, key=lambda x: x.tinh_tan_so_cat())
        print(f"Mạch có dải thông lớn nhất là {mach_loc_max.ten} với tần số cắt là {mach_loc_max.tinh_tan_so_cat()}")
    else:
        print("Không có mạch lọc nào trong danh sách.")

def main():
    # Nhập số lượng mạch lọc
    n = int(input("Nhập số lượng mạch lọc: "))

    # Nhập danh sách mạch lọc
    danh_sach_mach_loc = []
    for i in range(n):
        ten = input(f"Nhập tên mạch lọc thứ {i+1}: ")
        R = float(input(f"Nhập giá trị của R (Ω) của mạch lọc {ten}: "))
        C = float(input(f"Nhập giá trị của C (F) của mạch lọc {ten}: "))
        danh_sach_mach_loc.append(MachLocThongThapRC(ten, R, C))

    # In danh sách mạch lọc
    in_danh_sach_mach_loc(danh_sach_mach_loc)

    # Sắp xếp danh sách mạch lọc theo thứ tự giảm dần của trở kháng
    danh_sach_sap_xep = sap_xep_danh_sach(danh_sach_mach_loc)
    print("\nDanh sách mạch lọc sau khi sắp xếp:")
    in_danh_sach_mach_loc(danh_sach_sap_xep)

    # Tìm mạch có dải thông lớn nhất
    tim_mach_dai_thong_nhat(danh_sach_mach_loc)

if __name__ == "__main__":
    main()
