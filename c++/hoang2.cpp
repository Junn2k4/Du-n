#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class sv
{
	private:
		char masv[10];
		char ten[10];
		char lop[10];
		char khoa[10];
	public:
		void nhap();
		void xuat();
};
class diem
{
	private:
		char tenmon[10];
		int st;
		float diem;

	public:
		void nhap();
		void xuat();
		friend class phieu;
};
class phieu
{
	private:
		sv x;
		diem *y;
		int n;
	public:
		void nhap();
		void xuat();
		void tim();
		void xoa();
};
void sv::nhap()
{
	cout<<"\nNhap ma sinh vien: ";			fflush(stdin);			gets(masv);
	cout<<"\nNhap ten sinh vien: ";			fflush(stdin);			gets(ten);
	cout<<"\nNhap lop sinh vien: ";			fflush(stdin);			gets(lop);	
	cout<<"\nNhap khoa sinh vien: ";		fflush(stdin);			gets(khoa);
}
void sv::xuat()
{
	cout<<"ma sinh vien"<<setw(15)<<masv<<setw(20)<<"ten sinh vien"<<setw(15)<<ten<<endl;
	cout<<"lop"<<setw(20)<<lop<<setw(20)<<"khoa"<<setw(20)<<khoa<<endl;
}
void diem::nhap()
{
	cout<<"\nNhap ten mon: ";				fflush(stdin);			gets(tenmon);
	cout<<"\nNhap so trinh: ";cin>>st;
	cout<<"\nNhap diem: ";cin>>diem;
}
void diem::xuat()
{
	cout<<setw(15)<<tenmon<<setw(15)<<st<<setw(15)<<diem<<endl;
}
void phieu::nhap()
{
	x.nhap();
	cout<<"nhap so mon hoc: ";cin>>n;
	y=new diem[n];
	for(int i=0;i<n;i++)
	{
		y[i].nhap();
	}
}
void phieu::xuat()
{
	int tt;
	float t,td;
	x.xuat();
	cout<<setw(15)<<"ten mon"<<setw(15)<<"so trinh"<<setw(15)<<"diem"<<endl;
	for(int i=0;i<n;i++)
	{
		t=y[i].st*y[i].diem;
		td+=t;
		tt+=y[i].st;
		y[i].xuat();}
	cout<<"diem trung binh: "<<td/tt<<endl;
}
void phieu::tim()
{
	for(int i=0;i<n;i++)
	{
		if(y[i].diem<=8)
		y[i].xuat();
	}
}
void phieu::xoa()
{
	for(int i=0;i<n;i++)
	{
		if(y[i].st>5)
		{
			for(int j=i;j<n-1;j++)
				y[j]=y[j+1];
			n--;
			i--;
		}
	}
}
main()
{
	phieu p;
	p.nhap();
	cout<<"\------------------PHIEU BAO DIEM--------------"<<endl;
	p.xuat();
	cout<<"\--------------MON CO DIEM TREN 8--------------"<<endl;
	p.tim();
	p.xoa();
	cout<<"\n sau xoa:"<<endl;
	p.xuat();
}
