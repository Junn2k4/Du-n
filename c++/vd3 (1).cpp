#include<iostream>
#include<iomanip>
using namespace std;

class sinhvien
{
	private:
		char msv[15];
		char hoten[20];
		int tuoi;
		float dtb;
	public:
		void nhap();
		void xuat();
	friend void maxdiem(sinhvien *a, int n);
};

void sinhvien::nhap()
{
	fflush(stdin);
	cout<<"\nNhap ma sinh vien: "; gets(msv);
	fflush(stdin);
	cout<<"\nNhap ho ten: "; gets(hoten);
	cout<<"\nNhap tuoi";cin>>tuoi;
	cout<<"\nNhap diemtb: ";cin>>dtb;
}

void sinhvien:: xuat()
{
	cout<<setw(15)<<msv<<setw(20)<<hoten<<setw(5)<<tuoi<<setw(10)<<dtb<<endl;
}

main()
{
	int n;
	sinhvien *a;
	a= new sinhvien;
	cout<<"\nNhap so luong sinh vien:"; cin>>n;
	for(int i=0;i<n;i++)
		(a+i)->nhap();
	cout<<"\n DANH SACH SINH VIEN LA:"<<endl;
	cout<<setw(15)<<"MSV"<<setw(20)<<"Ho va ten"<<setw(5)<<"Tuoi"<<setw(10)<<"Diem"<<endl;
	for(int i=0;i<n;i++)
		(a+i)->xuat();
}