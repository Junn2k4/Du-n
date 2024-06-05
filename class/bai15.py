class songuyen:
    def __init__(self,a):
        self.a=a
    def amduong(self):
        if self.a>0:
            return 1
        else:
            return 0
    def doixung(self):
        stra=str(self.a)
        return stra==stra[::-1]
    def hoanthien(self):
        tonguoc=sum(i for i in range(1,self.a)if self.a%i==0)
        return tonguoc==self.a
def nhapds(n):
    mang=[]
    sodoixung=[]
    sohoanthien=[]
    am=[]
    for i in range(n):
        print(f"So thu {i+1}:")
        while 1:
            try:
                a=int(input("nhap so:"))
                so=songuyen(a)
                mang.append(so.a)
                if so.doixung():
                    sodoixung.append(so.a)
                if so.hoanthien():
                    sohoanthien.append(so.a)
                if so.amduong()==0:
                    am.append(so.a)
                break
            except ValueError:
                print("nhap lai")
    return mang,sodoixung,sohoanthien,am
def inds(mang,sodoixung,sohoanthien,am):
    if not mang:
        print("Khong co danh sach nao ca")
    else:
        print("Danh sach so thuc:",mang)
    if not sodoixung:
        print("Khong co so doi xung nao ca")
    else:
        tich=1
        for i in sodoixung:
            tich*=i
        print(f"Tich cac so doi xung la:",tich)
    if not sohoanthien:
        print("khong co so hoan thien")
    else:
        print("Danh sach so hoan thien la:",sohoanthien)
    if not am:
        print("khong co so am nao ca")
    else:
        ammin=am[0]
        for i in am:
            ammin=min(ammin,i) 
        print("SO am nho nhat la:",ammin)
while 1:
    try:
        n=int(input("Nhap so nguyen n:"))
        mang, sohoanthien, sodoixung, am = nhapds(n)
        if n<0:
            print("nhap lai")
        else:
            inds(mang,sodoixung,sohoanthien,am)
            break
    except ValueError:
        print("nhap lai")