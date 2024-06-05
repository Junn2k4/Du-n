am=[]
class sothuc:
    def __init__(self, a):
        self.a = a

    def kta(self):
        return self.a < 0

    def ktd(self):
        return self.a > 0

    def dem(self):
        if "." in str(self.a):
            return len(str(self.a).split('.')[1])
        else:
            return 0

def ticham(n):
    tich = 1
    for i in n:
        if i.kta():
            am.append(i.a)
            tich *= i.a
    return tich

def nhapso(n):
    ds = []
    for i in range(n):
        print(f"Nhap so thu {i+1}")
        while True:
            try:
                a = float(input("Nhap so: "))
                st = sothuc(a)
                ds.append(st)
                break
            except ValueError:
                print("Nhap lai")
    return ds

def inra(n):
    if not n:
        print('Khong co so nao')
    else:
        print("Cac so vua nhap:")
        for i, val in enumerate(n):
            print(f"So thu {i+1}: {val.a}, so chu so sau dau phay la: {val.dem()}")

def somaxsauphay(n):
    max_so = 0
    somax = None
    for i in n:
        d = i.dem()
        if d > max_so:
            max_so = d
            somax = i.a
    return max_so, somax

def timso(n, maxsauphay):
    so = []
    for i, s in enumerate(n):
        if s.dem() == maxsauphay:
            so.append(i+1)
    return so

# Main execution starts here
while True:
    try:
        n = int(input("Nhap so so kiem tra: "))
        if n <= 0:
            print("Nhap lai so duong")
        else:
            break
    except ValueError:
        print("Nhap lai")

ds = nhapso(n)
inra(ds)
maxphay, _ = somaxsauphay(ds)
print("So co so cac chu so sau dau phay nhieu nhat:", maxphay)
print("Vi tri cua so co so cac chu so sau dau phay nhieu nhat:", timso(ds, maxphay))
if not am:
    print("Khong co so am")
else:
    print("Tich cac so am:", ticham(ds))
