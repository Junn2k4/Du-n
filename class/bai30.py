class bee:
    def __init__(self,loai,v,t):
        self.loai=loai
        self.v=v
        self.t=t
    def s(self):
        return self.v*self.t
def nhapten():
    while 1:
        loai=input("nhap ten loai ong:")
        if loai.isalpha():
            return loai
        else:
            print("Ten chi nhan ky tu chu.Vui long nhap lai")
while 1:
    try:
        n=int(input("Nhap so luong con ong:"))
        if n<0:
            print("nhap lai")
        else:
            break
    except ValueError:
        print("nhap lai")
def nhapds(n):
    danhsach=[]
    for i in range(n):
        print(f"Con ong thu {i+1} la:")
        while 1:
            try:
                loai=nhapten()
                v=int(input("Nhap van toc bay (m/s):"))
                t=int(input("Nhap thoi gian bay (s):"))
                if v<0 or t<0:
                    print("nhap lai")
                else:
                    h=bee(loai,v,t)
                    danhsach.append(h)
                    break
            except ValueError:
                print("nhap lai")
    return danhsach
def inds(danhsach):
    if not danhsach:
        print("Khong co danh sach nao ca")
    else:
        for i,h in enumerate(danhsach):
            print(f"Con ong thu {i+1}:")
            print(f"Ten loai ong:{h.loai}")
            print(f"Van toc bay:{h.v},Thoi gian bay:{h.t},Quang duong bay:{h.s()}")
ds=nhapds(n)
print("------------------")
inds(ds)
print("----------------------")
def maxxv(ds):
    maxx=max(ds,key=lambda x:x.v)
    print(f"Con ong co van toc nhanh nhat la {maxx.loai} voi van toc {maxx.v}:")
maxxv(ds)
def longs(ds):
    m=max(ds,key=lambda x:x.s())
    slg=0
    for i in ds:
        if m.s()==i.s():
            slg+=1
    print(f"Con khoang {slg} con ong bay voi quang duong dai nhat lala:",m.s())
print("-------------")
longs(ds)