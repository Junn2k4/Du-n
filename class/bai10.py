class thisinh:
    def __init__(self,ten,nam,toan,van,anh):
        self.ten=ten
        self.nam=nam
        self.toan=toan
        self.van=van
        self.anh=anh
    def tuoi(self):
        return 2024-self.nam
    def tong(self):
        return self.toan+self.van+self.anh
while 1:
    try:
        n=int(input("nhap so luong thi sinh:"))
        if n<0:
            print("nhap lai")
        else:
            break
    except ValueError:
        print("nhap lai")
def nhapten():
    ten=input("Nhap ho ten:")
    if ten.isalpha():
        return ten
    else:
        print("ho ten chi nhan ky tu chu.Vlui long nhap lai")
def nhapds(n):
    danhsach=[]
    for i in range(n):
        print(f"Thi sinh thu {i+1}:")
        while 1:
            try:
                ten=nhapten()
                nam=int(input("Nhap nam sinh :"))
                toan=int(input("Nhap diem toan:"))
                van=int(input("Nhap diem van:"))
                anh=int(input("Nhap diem ngoai ngu:"))
                if nam<0 or toan<0 or van <0 or anh<0:
                    print("nhap lai")
                else:
                    h=thisinh(ten,nam,toan,van,anh)
                    danhsach.append(h)
                    break
            except ValueError:
                print("nhap lai")
    return danhsach-
    .
    .


    
def inds(danhsach):
    if not danhsach:
        print("khong co danh sach nao ca")
    else:
        for i ,h in enumerate(danhsach):
            print(f"Thi sinh thu {i+1}:")
            print(f"Ten la:{h.ten},Tuoi:{h.tuoi()},Sinh nam :{h.nam}")
            print(f"Diem toan:{h.toan},Diem van:{h.van},Diem ngoai ngu:{h.anh}")
            print(f"Tong diem 3 mon:{h.tong()}")
ds=nhapds(n)
inds(ds)
print("----------------")
def tuoimin(ds):
    tuoiminn=ds[0].tuoi()
    dem=1
    for i,h in enumerate(ds):
        if tuoiminn>h.tuoi():
            dem+=1
            tuoiminn=h.tuoi()
    return dem,tuoiminn
d1,t=tuoimin(ds)
print(f"Thi sinh thu {d1} co so tuoi nho nhat la:",t)
def toanmax(ds):
    toanmaxx=ds[0].toan
    dem=1
    for i,h in enumerate (ds):
        if toanmaxx<h.toan:
            toanmaxx=h.toan
    return dem,toanmaxx
d2,toann=toanmax(ds)
print("---------------------")
print(f"Thi sinh thu{d2} co diem toan cao nhat la:",toann)