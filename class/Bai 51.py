class con_minh:
  def __init__(self, loai, tuoi, gioi_tinh, so_con):
    self.loai = loai
    self.tuoi = tuoi
    self.gioi_tinh = gioi_tinh
    self.so_con = so_con

  def tinh_so_trung(self):
    x = self.tuoi
    y = self.loai
    z = self.gioi_tinh
    a = self.so_con
    if x > 45 and y == 'ri' and z == 'mai':
      return (self.tuoi - 45) * a
    if x > 30 and y == 'lai' and z == 'mai':
      return (self.tuoi - 30) * 2 * a
    if x > 35 and y != 'ri' and y != 'lai' and z == 'mai':
      return (self.tuoi - 35) * a
    if z == 'trong':
      return "không đẻ được"


while True:
  try:
    n = int(input("Số loài: "))
    if n <= 0:
      print("Nhập lại")
    else:
      break
  except ValueError:
    print("Nhập lại")


def nhap_du_lieu(n):
  ds = []
  gt = ['trong', 'mai']
  for i in range(n):
    ten = input("loài: ")
    while True:
      try:
        tuoi = int(input("tuổi gà: "))
        gioi_tinh = input("giới tính: ")
        so_con = int(input("số con: "))
        if tuoi > 0 and gioi_tinh in gt and so_con > 0:
          ds.append(con_minh(ten, tuoi, gioi_tinh, so_con))
          break
        else:
          print("Nhập lại thông tin")
      except ValueError:
        print("Nhập lại thông tin")
  return ds


def inn(ds):
  for i, s in enumerate(ds):
    print(f"{i + 1}, {s.loai}: tuổi = {s.tuoi}, giới tính: {s.gioi_tinh}, số con: {s.so_con}"
          f"\n=> số trứng đẻ được: {s.tinh_so_trung()}")


ds = nhap_du_lieu(n)
print("*     Danh sách các loài gà vừa nhập:")
inn(ds)

tong = sum(i.tinh_so_trung() for i in ds if i.gioi_tinh == 'mai')
print(f"*   tổng số trứng cả đàn là: {tong}")

tong_ri = sum(i.tinh_so_trung() for i in ds if i.loai == 'ri')
print(f"*   tổng số trứng gà ri là: {tong_ri}")