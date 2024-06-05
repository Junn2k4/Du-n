"""
- Tạo class lũy thừa gồm giá trị của 1 số nguyên và 3 phương thức tính bình phương, tính lập phương, tính giai thừa 
- Nhập 1 list có N object lũy thừa (là object tạo bởi class trong yêu cầu 1.) 
- Tạo 1 dictionary có key là số nguyên vừa nhập, value là lập phương của số nguyên đó.
-  In ra giai thừa các số vừa nhập  
- Tìm tổng lập phương các số vừa nhập. 
"""
class luythua():
    def __init__(self,k):
        self.k=k
    def binhphuong(self):
        return self.k**2
    def lapphuong(self):
        return self.k**3
    def giaithua(self):
        gthua=1
        for i in range(1, self.k+1): 
            gthua*=i
        return  gthua
def nhap(n):
    ds=[]
    for i in range(n):
        print(f"Nhap so thu {i+1} la:")
        while 1:
            try:
                r=int(input("Nhap so: "))
                if r<0:
                    print("Moi nhap lai")
                else:
                    lt=luythua(r)
                    ds.append(lt)
                    break
            except ValueError:
                print("Nhap lai")
    return ds
def inra(n):
    if not n:
        print("Khong co so danh sach nao")
    else:
        so=[]
        for i in n:
            so.append(i.k)
        print(f"So nguyen vua nhap la: {so}")
        dem=0
        for i in n:
            dem+=1
            print(f" binh phuong no la {i.binhphuong()}")
            print(f"Giai thua so vua nhap la: {i.giaithua()}")
def tonglapphuong(n):
    tlp=[]
    for i in n:
        tlp.append(i.lapphuong())
    tonglp=sum(tlp)
    return tonglp
while True:
    try:
        n=int(input("Nhap so luong phan tu."))
        if n<0:
            print("Nhap so duong: ")
        else:
            break
    except ValueError:
        print("nhap lai!!!")
ds=nhap(n)
inra(ds)