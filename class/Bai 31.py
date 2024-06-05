class ConKien:
    def __init__(self, loai_kien, nang_suat_tha_moi, thoi_gian_tha_moi):
        self.loai_kien = loai_kien
        self.nang_suat_tha_moi = nang_suat_tha_moi
        self.thoi_gian_tha_moi = thoi_gian_tha_moi
    def tinh_so_gram_moi_tha_duoc(self):
        return self.nang_suat_tha_moi * self.thoi_gian_tha_moi
# Nhập danh sách con kiến
n = int(input("Nhập số lượng con kiến: "))
con_kien_list = []
for i in range(n):
    print(f"Nhập thông tin cho con kiến thứ {i + 1}:")
    loai_kien = input("Loại kiến: ")
    nang_suat_tha_moi = float(input("Năng suất tha mồi (gram/phút): "))
    thoi_gian_tha_moi = float(input("Thời gian tha mồi (phút): "))
    con_kien = ConKien(loai_kien, nang_suat_tha_moi, thoi_gian_tha_moi)
    con_kien_list.append(con_kien)
# In danh sách con kiến vừa nhập
print("\nDanh sách con kiến vừa nhập:")
for i, kien in enumerate(con_kien_list):
    print(f"Con kiến {i + 1}: Loại kiến: {kien.loai_kien}, Năng suất tha mồi: {kien.nang_suat_tha_moi} gram/phút, Thời gian tha mồi: {kien.thoi_gian_tha_moi} phút, Số gram mồi đã thả được: {kien.tinh_so_gram_moi_tha_duoc()} gram")
# Tìm con kiến có năng suất tha mồi kém nhất và in ra những vị trí nó xuất hiện
nang_suat_kem_nhat = min(kien.nang_suat_tha_moi for kien in con_kien_list)
vi_tri_nang_suat_kem_nhat = [i + 1 for i, kien in enumerate(con_kien_list) if kien.nang_suat_tha_moi == nang_suat_kem_nhat]
print(f"\nCon kiến có năng suất tha mồi kém nhất là {nang_suat_kem_nhat} gram/phút tại các vị trí: {vi_tri_nang_suat_kem_nhat}")
# Tính tổng số gram mồi đàn kiến đã thả được
tong_gram_moi_tha_duoc = sum(kien.tinh_so_gram_moi_tha_duoc() for kien in con_kien_list)
print(f"\nTổng số gram mồi đàn kiến đã thả được là: {tong_gram_moi_tha_duoc} gram.")
