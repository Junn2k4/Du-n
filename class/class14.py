import math
class SoNguyen:
    def __init__(self, gia_tri):
        self.gia_tri = gia_tri

    def so_am_duong(self):
        if self.gia_tri < 0:
            return True  # Số âm
        elif self.gia_tri > 0:
            return False  # Số dương
        else:
            return None  # Số không

    def so_doi_xung(self):
        str_gia_tri = str(self.gia_tri)
        return str_gia_tri == str_gia_tri[::-1]

    def so_hoan_thien(self):
        tong_uoc = sum(i for i in range(1, self.gia_tri) if self.gia_tri % i == 0)
        return tong_uoc == self.gia_tri

def nhap_so(n):
    list_so = []
    list_so_duong = []
    list_doi_xung = []
    list_hoan_thien = []
    for i in range(n):
        print(f'So thu {i + 1}: ')
        while 1:
            try:
                gia_tri = int(input('Nhap so: '))
                so = SoNguyen(gia_tri)
                list_so.append(so)
                if so.so_am_duong() == 1:
                    list_so_duong.append(so.gia_tri)
                if so.so_doi_xung():
                    list_doi_xung.append(so.gia_tri)
                if so.so_hoan_thien():
                    list_hoan_thien.append(so.gia_tri)
                break
            except ValueError:
                print('nhap lai')
    return list_so, list_so_duong, list_doi_xung, list_hoan_thien


def in_so(day_so, so_duong, doi_xung, hoan_thien):
    if not day_so:
        print('Khong co so nao trong day')
    else:

        # in ra các số dương
        if not so_duong:
            print('Khong co so duong trong day')
        else:
            print(f'Cac so duong la: {so_duong}')

        # in ra tổng của các số hoàn thiện
        if not hoan_thien:
            print('Khong co so hoan thien trong day')
        else:
            tong = 0
            for i in hoan_thien:
                tong += i
            print(f'Tong cac so hoan thien la: {tong}')

        # in ra số đối xứng lớn nhất
        if not doi_xung:
            print('Khong co so doi xung')
        else:
            print(f'So doi xung lon nhat la: {max_doi_xung(doi_xung)}')


def max_doi_xung(doixung):
    max = doixung[0]
    for i in doixung:
        if i >max:
            max = i
    return max


while 1:
    try:
        n = int(input('Nhap so chu so: '))
        day_so, so_am, doi_xung, hoan_thien = nhap_so(n)
        if (n < 0):
            print('nhap lai')
        else:
            in_so(day_so, so_am, doi_xung, hoan_thien)
            break
    except ValueError:
        print('Nhap lai')
