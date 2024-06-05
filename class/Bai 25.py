222class DienTro:
    def __init__(self, mau1, mau2, mau3):
        self.mau1 = mau1
        self.mau2 = mau2
        self.mau3 = mau3
    def xac_dinh_gia_tri(self):
        # Dictionary mô phỏng mối quan hệ giữa màu và giá trị số
        mau_gia_tri = {
            'den': 0,
            'nau': 1,
            'do': 2,
            'cam': 3,
            'vang': 4,
            'luc': 5,
            'lam': 6,
            'xanh': 7,
            'cham': 8,
            'tim': 9
        }
        # Xác định giá trị của điện trở theo vòng màu
        gia_tri = int(str(mau_gia_tri[self.mau1]) + str(mau_gia_tri[self.mau2]) + '0' * mau_gia_tri[self.mau3])
        return gia_tri
# Nhập 1 list chứa n điện trở
n = int(input("Nhập số lượng điện trở: "))
dien_tro_list = []
for i in range(n):
    print(f"Nhập thông tin cho điện trở thứ {i + 1}:")
    mau1 = input("Nhập màu vòng thứ nhất: ")
    mau2 = input("Nhập màu vòng thứ hai: ")
    mau3 = input("Nhập màu vòng thứ ba: ")
    dien_tro = DienTro(mau1, mau2, mau3)
    dien_tro_list.append(dien_tro)
# In ra giá trị của các điện trở vừa nhập
print("\nGiá trị của các điện trở vừa nhập:")
for i, dien_tro in enumerate(dien_tro_list):
    gia_tri = dien_tro.xac_dinh_gia_tri()
    print(f"Điện trở {i + 1}: {gia_tri}")
# Tạo tuple chứa giá trị của n điện trở
gia_tri_tuple = tuple(dien_tro.xac_dinh_gia_tri() for dien_tro in dien_tro_list)
print("\nTuple chứa giá trị của n điện trở:", gia_tri_tuple)
# Tìm điện trở có trở kháng nhỏ nhất và in các vị trí điện trở đó xuất hiện
trtro_min = min(gia_tri_tuple)
vi_tri_min = [i + 1 for i, gia_tri in enumerate(gia_tri_tuple) if gia_tri == trtro_min]
print(f"\nĐiện trở có trở kháng nhỏ nhất là {trtro_min} tại các vị trí: {vi_tri_min}")
