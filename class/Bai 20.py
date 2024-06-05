import math



class SoNguyen:
    def __init__(self, a):
        self.a = a

    def am_duong(self):
        if self.a < 0:
            return 1
        else:
            return 0

    def la_scp(self):
        for i in range(1, int(math.sqrt(self.a)) + 1):
            if i * i == self.a:
                return 1
        return 0

    def la_sht(self):
        if self.a <= 0:
            return 0
        tong = 0
        for i in range(1, self.a):
            if self.a % i == 0:
                tong += i
        if tong == self.a:
            return 1
        return 0

while True:
    try:
        n = int(input("Nhập số lượng số nguyên: "))
        if n < 0:
            print("Nhập số dương.")
        else:
            break
    except ValueError:
        print("Nhập lại!")

def nhap_so_nguyen(n):
    danh_sach = []
    am = []
    scp = []
    sht = []
    for i in range (n):
        print(f'Nhap so thu {i+1}')
        while True:
            try:
                a=int(input("Nhap so: "))
                so=SoNguyen(a)
                danh_sach.append(so)
                if so.am_duong() == 1:
                    am.append(so.a)
                if so.la_scp() == 1:
                    scp.append(so.a)
                if so.la_sht() == 1:
                    sht.append(so.a)
                break
            except ValueError:
                print("Nhap Lai. ")
    return danh_sach,am,scp,sht

def in_ra(day,am,scph,shth):
    if not day:
        print("Không có số nào.")
    if not shth:
        print("Không có số hoàn thiện nào trong danh sách nhập")
    else:
        print("Các số hoàn thiện trong danh sách là: ", shth)
    if not am:
        print("Khong co so am trong day")
    else:
        print(f"So am trong day la: {am}")
        print("Số am lớn nhất là ", max(am)) 
    if not scph:
        print("Khong co so cp trong day")
    else:
        print(f"So cp la: {scph}")
day,am,scph,shth = nhap_so_nguyen(n)
in_ra(day,am,scph,shth)

