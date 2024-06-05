class hhcn:
    def __init__(self,a,b,c):
        self.a=a
        self.b=b
        self.c=c
    def sxungquanh(self):
        return (self.a*self.c)*2+(self.c*self.b)*2
    def thetich(self):
        return self.a*self.b*self.c
while 1:
    try:
        n=int(input("nhap so luong hinh hop chu nhat:"))
        if n<0:
            print("vui long nhap lai")
        else:
            break
    except ValueError:
        print("nhap lai")
def nhapds(n):
    danhsach=[]
    for i in range(n):
        print(f"Hinh hop chu nhat thu {i+1}:")
        while 1:
            try:
                a=float(input("nhap chieu dai:"))
                b=float(input("nhap chieu rong:"))
                c=float(input("nhap chieu cao:"))
                if a<=0 or b<=0 or c<=0:
                    print("nhap so duong")
                else:
                    h=hhcn(a, b, c)
                    danhsach.append(h)
                    break
            except ValueError:
                print("nhap lai")
    return danhsach
def inds(danhsach):
    if not danhsach:
        print("khong co danh sach nao ca")
    else:
        for i ,h in enumerate(danhsach):
            print(f"Hinh hop chu nhat thu {i+1}:,CHieu dai:{h.a},CHieu rong:{h.b},CHieu cao:{h.c},DIen tich xung quanh:{h.sxungquanh()},The tich:{h.thetich()}")
ds=nhapds(n)
print("-------------")
inds(ds)
print("------------------")
def tongd(ds):
    tong=0
    for i in ds:
        tong=tong+i.sxungquanh()
    return tong
print(f"Tong dien tich xung quanh cua",n,"hinh hop chi nhat la",tongd(ds))
def tongt(ds):
    tong=0
    for i in ds:
        tong=tong+i.thetich()
    return tong
print(f"Tong the tich xung quanh cua",n,"hinh hop chi nhat la",tongt(ds))
def vmax(ds):
    vmaxx=ds[0].thetich()
    dem=1
    for i,h  in enumerate (ds):
        if vmaxx<h.thetich():
            dem+=1
            vmaxx=h.thetich()
    return dem,vmaxx
d,v=vmax(ds)
print("---------------")
print(f"the tich cua hinh hop chu nhat thu {d} la the tich lon nhat:",v)