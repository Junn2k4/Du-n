class songuyen:
    def __init__(self,a):
        self.a=a
    def amduong(self):
        if self.a<0:
            return 0
        else:
            return 1
    def sosaudauphay(self):
        if "." in str(self.a):
            return len(str(self.a).split(".")[1])
        else:
            return 0
def tup(mang):
    return tuple(mang)
def nhapds(n):
    mang=[]
    am=[]
    duong=[]
    sauphay=[]
    for i in range(n):
        print(f"So thu {i+1}:")
        while 1:
            try:
                a=float(input("Nhap so :"))
                so=songuyen(a)
                mang.append(so.a)
                if so.amduong()==0:
                    am.append(so.a)
                else:
                    duong.append(so.a)
                if so.sosaudauphay():
                    sauphay.append(so.a)
                break
            except ValueError:
                print("nhap lai")
    return mang,am,duong,sauphay
def inds(mang,am,duong,sauphay):
    if not mang:
        print("Khong có so thuc nao ca")
    else:
        print("Tuple danh sach so thuc la:",tup(mang))
    if not duong:
        print("khong co so duong nao ca")
    else:
        print("Tuple chua so duong la:",tuple(duong))
    if not am:
        print("khong co so am nao ca")
    else:
        tich=1
        for i in am:
            tich*=i
        print("Tich cach so am la",tich)
    if not sauphay:
        print("khong co so thuc")
    else:
        maxx=max(sauphay,key=lambda x:songuyen(x).sosaudauphay())
        print("so sau dau phay dai nhat la:",maxx)
while 1:
    try:
        n=int(input("nhap so nguyen n:"))
        mang,am,duong,sauphay=nhapds(n)
        if n<0:
            print("nhap lai")
        else:
            inds(mang,am,duong,sauphay)
            break
    except ValueError:
        print("Nhap lai")