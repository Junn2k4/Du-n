class songuyen:
    def __init__(self,a):
        self.a=a
    def ktrchanle(self):
        for i in range(self.a+1):
            if self.a%2==0: return 1
        return 0
    def ktnt(self):
        if self.a<2: return 0
        for i in range (2,int(self.a**0.5)+1):
            if self.a%i==0: return 0
        return 1
    def scp(self):
        if self.a<1: return 0
        for i in range(1,int(self.a**0.5)+1):
            if i*i==self.a: return 1
        return 0
def nhapso(n):
    list_so=[]
    chan=[]
    le=[]
    scp=[]
    snt=[]
    for i in range(n):
        print(f"so thu {i+1}:")
        while 1:
            try:
                a=int (input("nhap so:") )
                so=songuyen(a)
                list_so.append(so)
                if so.ktrachanle()==1: chan.append(so.a)
                if so.ktnt()==1: snt.append(so.a)
                if so.scp()==1: scp.append(so.a)
                break
            except ValueError:
                print ("nhap lai!")
    return list_so,chan,le,scp,snt
def in_so(day,sochann,scpp,sntt):
    if not day:
        print("khong co danh sach nao")
    else:
        if not sochann:
            print("khong co so chan")
        else:
            print(f"cac so chan la:{sochann}")
        if not scpp:
            print("khong co so chinh phuong")
        else:
            tong=0
            for i in scpp:
                tong+=i
            print(f"so chinh phuong{tong}")
        if not sntt:
            print("khong co so nguyen to")
        else:
            print(f"so nguyen to max:{max_nguyento(nguyento)}")
def max_nguyento(nguyento):
    max=nguyento[0]
    for i in nguyento:
        if i>max:
            max=i
    return max
while 1:
    try:
        n=int(input("nhap so chu so:"))
        day,sochann,scpp,sntt=nhapso(n)
        if n<0:
            print("nhap lai")
        else:
            in_so(day,sochann,scpp,sntt)
            break
    except ValueError:
        print("nhaplai")



