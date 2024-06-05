class tgiac:
    def __init__(self,a,b,c,d):
        self.a=a
        self.b=b
        self.c=c
        self.d=d
    def chuvi(self):
        return self.a+self.b+self.c+self.d
    def max_canh(self):
        return max(self.a,self.b,self.c,self.d)
while True:
    try:
        n=int(input("số hình tứ giác là:"))
        if n<0:
            print("nhập không hợp lệ")
            continue
        else:
            break
    except ValueError:
        print("nhập lại!")
def nhap_canh(n):
    ds_tgiac=[]
    for i in range(n):
        print(f"hình tứ giác thứ{i+1} là:")
        while True:
            try:
                a=int(input("nhập cạnh thứ 1:"))
                b=int(input("nhập cạnh thứ 2:"))
                c=int(input("nhập cạnh thứ 3:"))
                d=int(input("nhập cạnh thứ 4:"))
                if(a<0 or b<0 or c<0 or d<0):
                    print("vui lòng nhập lại")
                else:
                    h=tgiac(a,b,c,d)
                    ds_tgiac.append(h)
                    break
            except ValueError:
                print("nhập lại!")
    return ds_tgiac
def in_tgiac(ds):
    if not ds:
        print("không có danh sách nào cả")
    else:
        print("các hình tứ giác là:")
        for i,h in enumerate(ds):
            print(f"hình tứ giác thứ{i+1},cạnh thứ 1:{h.a},cạnh thứ 2:{h.b},cạnh thứ 3:{h.c},cạnh thứ 4:{h.d},chu vi:{h.chuvi()},canh_max:{h.max_canh()}")
        chuvimin=ds[0].chuvi()
        for h in ds:
            a=h.chuvi()
        if a<chuvimin:
             a=chuvimin
        print("chu vi nho nhất trong ds là:",a)

ds= nhap_canh(n)
in_tgiac(ds)