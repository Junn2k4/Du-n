#include <bits/stdc++.h>
using namespace std;
class date
{
	private:
		int d,m,y;
	public:
		void nhap();
		void xuat();
};
class nsx
{
	private:
		char tensx[30];
		char diachi[30];
	public:
		void nhap();
		void xuat();
	friend class hang;
};
class hang
{
	protected:
		char
		 tenhang[30];
		nsx x;
		int dongia;
	public:
		void nhap();
		void xuat();
		hang();
};
class tivi:public hang
{
	private:
		int kichthuoc;
		date ngaynhap;
	public:
		void nhap();
		void xuat();
		tivi();
	 
};
void date::nhap()
{
	cout<<"\n nhap ngay:";		cin>>d;
	cout<<"\n nhap thang:";		cin>>m;
	cout<<"\n nhap nam:";		cin>>y;
	
}
void date::xuat()
{
	cout<<"\nDate:"<<d<<"/"<<m<<"/"<<y<<endl;
}
void nsx::nhap()
{
	cout<<"\n nhap ten nha san xuat:";			fflush(stdin);		gets(tensx);
	cout<<"\n nhap dia chi:";					fflush(stdin);		gets(diachi);
	
}
void nsx::xuat()
{
	cout<<"\nTen nha san xuat:"<<tensx<<endl;
	cout<<"\nDia chi:"<<diachi<<endl;
}
hang::hang()
{
	strcpy(x.tensx,"DUAN");
	strcpy(x.diachi,"0");
	strcpy(tenhang,"D");
	dongia=1000;
}
void hang::nhap()
{
	cout<<"\n nhap ten hang:";			fflush(stdin);		gets(tenhang);
	x.nhap();
	cout<<"\n nhap don gia:";		cin>>dongia;
}

void hang::xuat()
{
	cout<<"\nTen hang:"<<tenhang<<endl;
	x.xuat();
	cout<<"\n Don gia:"<<dongia;
}
tivi::tivi():hang()
{

	kichthuoc=30;
	
}
void tivi::nhap()
{
	hang::nhap();
	cout<<"Nhap kich thuoc:";		cin>>kichthuoc;
	ngaynhap.nhap();
	
}
void tivi::xuat()
{
	hang::xuat();
	cout<<"\n Kich thuoc:"<<kichthuoc;
	ngaynhap.xuat();
}

main()
{
	tivi a;
	a.nhap();
	cout<<"\n THONG TIN CUA TIVI:"<<endl;
	a.xuat();
		return 0;
}
