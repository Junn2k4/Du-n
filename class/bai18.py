class nv:
    def __init__(self,hoten,nam,luong,heso):
        self.hoten=hoten
        self.nam=nam
        self.luong=luong
        self.heso=heso
    def tongluong(self):
        s=self.luong*self.heso+self.nam*self.luong*0.1
        return round(s,3)
while 1:
    try:
        n=int(input("nhap so luong nhan vien:"))
        if n>0:
            break
        else:
            print("vui luong nhap lai so duong")
    except ValueError:
        print("nhap lai")
def nhaphoten():
    while 1:
        hoten=input("nhap ho ten nhan vien:")
        if hoten.isalpha():
            return hoten
        else:
            print("Ho ten chi nhan ky tu chu .Vui luong nhap lai")
def nhapds(n):
    danhsach=[]
    for i in range(n):
        print(f"Nhan vien thu {i+1}:")
        while 1:
            try:
                hoten=nhaphoten()
                nam=int(input("nhap nam cong tac:"))
                luong=int(input("nhap luong:"))
                heso=int(input("nhap he so:"))
                if nam<0 or luong<0 or heso<0:
                    print("nhap lai")
                else:
                    danhsach.append(nv(hoten,nam,luong,heso))
                    break
            except ValueError:
                print("nhap lai")
    return danhsach
def indanhsach(danhsach):
    if not danhsach:
        print("khong co danh sach nao ca")
    else:
        for i, h in enumerate(danhsach):
            print(f"Nhan vien {i+1}:,Ho ten:{h.hoten},Nam cong tac:{h.nam},Luong co ban:{h.luong},He so:{h.heso},Tong luong:{h.tongluong()}")
ds=nhapds(n)
print("--------------------")
indanhsach(ds)
print("------------------------------")
def nvlaunam(danhsach):
    maxn=max(danhsach, key= lambda x:x.nam )
    print(f"Nhan vien lau nam la:{maxn.hoten}")
nvlaunam(ds)
print("--------------------------")
def tinh(danhsach):
    tong=0
    for i in danhsach:
        tong+=i.tongluong()
    return tong
print(f'Tong luong cua cac nhan vien da nhap la:',tinh(ds))