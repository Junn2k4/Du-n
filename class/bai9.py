import math
class duongthang:
    def __init__(self,x1,x2,y1,y2):
        self.x1=x1
        self.x2=x2
        self.y1=y1
        self.y2=y2
    def dodai(self):
        return math.sqrt((self.x2-self.x1)**2+(self.y2-self.y1)**2)
n=3
def nhaptoado(n):
    danhsach=[]
    for i in range(n):
        print(f"Doan thang thu {i+1}:")
        while 1:
            try:
                x1=float(input("Nhap toa do x1:"))
                x2=float(input("Nhap toa do x2:"))
                y1 = float(input("Nhap toa do y1:"))
                y2 = float(input("Nhap toa do y2:"))
                if x1<0 or x2<0 or y1<0 or y2<0:
                    print("nhap lai")
                else:
                    d=duongthang(x1,x2,y1,y2)
                    danhsach.append(d)
                    break
            except ValueError:
                print("nhap lai")
    return danhsach
def inds(danhsach):
    if not danhsach:
        print("Khong co danh sach nao ca")
    else:
        for i,h in enumerate(danhsach):
            print(f"Doan thang thu {i+1}:toa do 1:({h.x1},{h.y1});toa do 2({h.x2},{h.y2})")
            print(f"Do dai doan thang la:{h.dodai()}")
ds=nhaptoado(n)
inds(ds)

def ktra(ds):
    for i in range(len(ds)):
        for j in range(i + 1, len(ds)):
            for k in range(j + 1, len(ds)):
                if (ds[i].dodai() + ds[j].dodai() > ds[k].dodai() and
                    ds[i].dodai() + ds[k].dodai() > ds[j].dodai() and
                    ds[j].dodai() + ds[k].dodai() > ds[i].dodai()):
                    return True
    return False
if ktra(ds):
    print("khong tao thanh tam giac")
else:
    print("3 doan thang tao thanh tam giac")
def dgthangmax(ds):
    dgthangmaxx=ds[0].dodai()
    dem=1
    for i,h in enumerate( ds):
        if dgthangmaxx<h.dodai():
            dgthangmaxx=h.dodai()
            dem+=1
    return dem,dgthangmaxx
d,t=dgthangmax(ds)
print(f"Doan thang thu {d} co do dai lon nhat",t)