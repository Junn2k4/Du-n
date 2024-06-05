#include<bits/stdc++.h>
using namespace std;
class ncc
{
	private:
		char mancc[20];
		char tncc[20];
		char dc[20];
	public:
		void nhap();
		void xuat();
};
void ncc::nhap()
{
	cout<<"\n Nhap ma nha cung cap: ";		fflush(stdin); 		gets(mancc);
	cout<<"\n Nhap ten nha cung cap: ";		fflush(stdin); 		gets(tncc);
	cout<<"\n Nhap dia chi: ";		fflush(stdin); 		gets(dc);
}
void ncc::xuat()
{
	cout<<setw(15)<<"Ma NCC: "<<mancc;
	cout<<setw(30)<<"Ten NCC: "<<tncc<<endl;
	cout<<setw(15)<<"Dia Chi: "<<dc<<endl;
}
class hang
{
	private:
		char tenhang[20];
		float dg,sl;
	public:
		void nhap();
		void xuat();
};
void hang::nhap()
{
	cout<<"\n Nhap ten hang: ";			fflush(stdin);		gets(tenhang);
	cout<<"\n Nhap don gia: ";		cin>>dg;
	cout<<"\n Nhap so luong: ";		cin>>sl;
}
void hang::xuat()
{
	cout<<setw(15)<<tenhang<<setw(15)<<dg<<setw(15)<<sl<<dg*sl<<endl;
}
class phieu
{
	private:
		char maph[20];
		char ngay[20];
		ncc x;
		hang *y;
		int n;
	public:
		void nhap();
		void xuat();
};
void phieu::nhap()
{
	cout<<"\n Nhap ma phieu: ";		fflush(stdin);		gets(maph);
	cout<<"\n Nhap ngay lap: ";		fflush(stdin);		gets(ngay);
	x.nhap();
	cout<<"\n Nhap so luong hang: ";		cin>>n;
	y=new hang[n];
	for (int i=0;i<n;i++)
	{
		cout<<"\ Nhap mat hang thu "<<i+1<<endl;
		y[i].nhap();
	}
}
void phieu::xuat()
{
	cout<<setw(15)<<"Ma phieu: "<<maph;
	cout<<setw(15)<<"Ngay lap: "<<ngay<<endl;
	x.xuat();
	cout<<setw(15)<<"Ten hang";
	cout<<setw(15)<<"Don gia";
	cout<<setw(15)<<"So luong";
	cout<<setw(15)<<"Thanh tien"<<endl;
	for (int i=0;i<n;i++)
	{
		y[i].xuat();
	}
}
main()
{
	phieu a;
	a.nhap();
	a.xuat();
}

