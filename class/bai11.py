class songuyen:
    def __init__(self,a):
        self.a=a
    def chanle(self):
        if self.a%2==0:
            return 1
        else:
            return 0
    def snt(self):
        dem=0
        for i in range(2,int(self.a)+1):
            if self.a%i==0:
                dem+=1
        if dem==1:
            return 1
        else:
            return 0
    def scp(self):
        for i in range(1,int(self.a)+1):
            if i**2 == self.a:
                return 1
                break
        return 0
def nhapso(n):
    mang=[]
    chan=[]
    scp=[]
    snt=[]
    for i in range(n):
        while 1:
            try:
                a=int(input("nhap so:"))
                so=songuyen(a)
                mang.append(so.a)
                if so.chanle()==1:
                    chan.append(so.a)
                if so.scp()==1:
                    scp.append(so.a)
                if so.snt()==1:
                    snt.append(so.a)
                break
            except ValueError:
                print("nhap lai")
    return mang,chan,scp,snt
while True:
    try:
        n=int(input("nhap so luong so nguyen:"))
        mang,chan,scp,snt=nhapso(n)
        if n<0:
            print("nhap lai")
        else:
            if not mang:
                print("lhong co danh sach nao ca")
            else:
                print("Danh sach:",mang)
            if not chan:
                print("khong co so chan")
            else:
                print("danh sach so chan la:",chan)
            if not scp:
                print("khong co so chinh phuong")
            else:
                tong=0
                for i in scp:
                    tong+=i
                print("Tong so chinh phuong trong mang la:",tong)
            if not snt:
                print("khong co so nguyen to")
            else:
                maxn=snt[0]
                for i in snt:
                    maxn=max(maxn,i)
                print("So nguyen to lon nhat la:",maxn)
            break
    except ValueError:
        print("nhap lai")

