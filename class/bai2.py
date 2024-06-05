class hcn:
    def __init__(self,a,b):
        self.a=a
        self.b=b
    def chuvi(self):
        return self.a*2+self.b*2
    def dientich(self):
        return self.a*self.b
    def dgcheo(self):
        return (self.a**2+self.b**2)**0.5
while 1:
    try:
        n=int(input("nhap so luong hinh chu nhat:"))
        if n<0:
            print("vui long nhap lai")
        else:
            break
    except ValueError:
        print("nhap lai")
def nhapcanh(n):
    danhsach=[]
    for i in range(n):
        print(f"Hinh chu nhat thu {i+1}:")
        while 1:
            try:
                a=float(input("nhap chieu dai:"))
                b=float(input("nhap chieu rong:"))
                if a<0 or b<0:
                    print("nhap lai")
                else:
                    h=hcn(a,b)
                    danhsach.append(h)
                    break
            except ValueError:
                print("nhap lai")
    return danhsach
def inds(danhsach):
    if not danhsach:
        print("khong co danh sach nao ca")
    else:
        for i,h in enumerate(danhsach):
            print(f"Hinh chu nhat thu {i+1}:,Chieu dai:{h.a},Chieu rong:{h.b},CHu vi:{h.chuvi()},DIen tich:{h.dientich()},Duong cheo:{h.dgcheo()}")
ds=nhapcanh(n)
print("-----------")
inds(ds)
print("----------------")
def tongdientich(ds):
    tong=0
    for i in ds:
        tong=tong+i.dientich()
    return tong

print("Tong dien tich cua n hcn la:",tongdientich(ds))
def dgcheomin(ds):
    dgcheominn=ds[0].dgcheo()
    dem=1
    for i,h in enumerate (ds):
        if dgcheominn>h.dgcheo():
            dem+=1
            dgcheominn=h.dgcheo()
    return dem,dgcheominn
d,dg=dgcheomin(ds)
print("---------------")
print(f"Duong cheo nho nhat cua hinh chu nhat thu {d}la",dg)