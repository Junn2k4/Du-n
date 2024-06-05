class songuyen:
    def __init__(self,a):
        self.a=a
    def chanle(self):
        if self.a%2==0:
            return 1
        else:
            return 0
    def snt(self):
        if self.a<1:
            return 0
        else:
            for i in range(2,int(self.a**0.5)+1):
                if self.a%i==0:
                    return 0
        return 1
    def scp(self):
        if self.a <1:
            return 0
        else:
            for i in range(1,int(self.a**0.5)+1):
                if i**2==self.a:
                    return 1
        return 0
def nhapso(n):
    mang=[]
    le=[]
    snt=[]
    scp=[]
    for i in range(n):
        while 1:
            try:
                a=int(input("nhap so:"))
                so=songuyen(a)
                mang.append(so.a)
                if so.chanle()==0:
                    le.append(so.a)
                if so.snt()==1:
                    snt.append(so.a)
                if so.scp()==1:
                    scp.append(so.a)
                break
            except ValueError:
                print("nhap lai")
    return mang,le,snt,scp
while 1:
    try:
        n=int(input("nhap so nguyen:"))
        mang,le,snt,scp=nhapso(n)
        if n<0:
            print("nhap lai")
        else:
            if not mang:
                print("khong co danh sach nao ca")
            else:
                print("danh sach:",mang)
            if not le:
                print("khong co so le")
            else:
                print("danh sach so le:",le)
            if not snt:
                print("khong co so nguyen to")
            else:
                tich=1
                for i in snt:
                    tich*=i
                print("tich cac so nguyen to la:",tich)
            if not scp:
                print("khong co so chinh phuong")
            else:
                minn=scp[0]
                for i in scp:
                    minn=min(minn,i)
                print("so chinh phuong nho nhat la:",minn)
            break
    except ValueError:
        print("nhap lai")
