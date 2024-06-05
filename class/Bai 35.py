import math
class PhuongTrinhBac2:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
    def tinh_nghiem(self):
        delta = self.b**2 - 4 * self.a * self.c
        if delta > 0:
            x1 = (-self.b + math.sqrt(delta)) / (2 * self.a)
            x2 = (-self.b - math.sqrt(delta)) / (2 * self.a)
            return x1, x2
        elif delta == 0:
            x = -self.b / (2 * self.a)
            return x,
        else:
            return None
# Nhập danh sách phương trình
n = int(input("Nhập số lượng phương trình: "))
phuong_trinh_list = []
for i in range(n):
    print(f"Nhập thông tin cho phương trình thứ {i + 1}:")
    a = float(input("Hệ số a: "))
    b = float(input("Hệ số b: "))
    c = float(input("Hệ số c: "))
    pt = PhuongTrinhBac2(a, b, c)
    phuong_trinh_list.append(pt)
# In danh sách phương trình vừa nhập (bao gồm cả các hệ số và nghiệm)
print("\nDanh sách phương trình vừa nhập:")
for i, pt in enumerate(phuong_trinh_list):
    nghiem = pt.tinh_nghiem()
    print(f"Phương trình {i + 1}: a={pt.a}, b={pt.b}, c={pt.c}, Nghiệm: {nghiem}")
# Đếm số phương trình vô nghiệm và in ra
phuong_trinh_vo_nghiem = [i + 1 for i, pt in enumerate(phuong_trinh_list) if pt.tinh_nghiem() is None]
print(f"\nTrong danh sách có {len(phuong_trinh_vo_nghiem)} phương trình vô nghiệm, là các phương trình thứ: {phuong_trinh_vo_nghiem}")
# Đếm số nghiệm dương và in ra
so_nghiem_duong = 0
print("\nDanh sách nghiệm dương:")
for i, pt in enumerate(phuong_trinh_list):
    nghiem = pt.tinh_nghiem()
    if nghiem and all(x > 0 for x in nghiem):
        so_nghiem_duong += 1
        print(f"Phương trình {i + 1}: Nghiệm dương: {nghiem}")
print(f"\nTrong danh sách có {so_nghiem_duong} phương trình có nghiệm dương.")


