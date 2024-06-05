#include <bits/stdc++.h>
using namespace std;
class phieu;
class ncc
{
	private:
		char mancc[30];
		char tenncc[30];
		char diachi[40];
	public:
		void nhap();
		void xuat();
		
};
class hang
{
	private:
		char tenhang[30];
		int dongia,slg;
	public:
		void nhap();
		void xuat();
	friend class phieu;
	friend void sx(phieu&a);
	friend void sua(phieu &a);
};
class phieu
{
	private:
		char maphieu[30];
		int ngay;
		ncc x;
		int n;
		hang y[30];
	public:
		void nhap();
		void xuat();
	friend void sx(phieu&a);
	friend void sua(phieu &a);
};
void ncc::nhap()
{
	cout<<"\n nhap ma nha cung cap:";		fflush(stdin);			gets(mancc);
	cout<<"\n nhap ten nha cung cap:";		fflush(stdin);			gets(tenncc);
	cout<<"\n nhap dia chi:";				fflush(stdin);			gets(diachi);
}
void ncc::xuat()
{
	cout<<setw(15)<<"Ma NCC:"<<mancc<<setw(40)<<"Ten NCC:"<<tenncc<<endl;
	cout<<setw(15)<<"Dia chi"<<diachi<<endl;
}
void hang::nhap()
{
	cout<<"\n nhap ten hang:";		fflush(stdin);			gets(tenhang);
	cout<<"\n nhap don gia:";		cin>>dongia;
	cout<<"\n nhap so luong:";		cin>>slg;
}
void hang::xuat()
{
	cout<<setw(15)<<tenhang<<setw(15)<<dongia<<setw(15)<<slg<<setw(15)<<dongia*slg<<endl;
}
void phieu::nhap()
{
	cout<<"\n nhap ma phieu:";		fflush(stdin);			gets(maphieu);
	cout<<"\n nhap ngay lap:";		cin>>ngay;
	x.nhap();
	cout<<"\n nhap so luong hang:";		cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n Hang thu:"<<i+1<<endl;
		y[i].nhap();
	}
}
void phieu::xuat()
{
	cout<<setw(15)<<"Ma phieu:"<<maphieu<<setw(40)<<"Ngay lap:"<<ngay<<endl;
	x.xuat();
	cout<<setw(20)<<"tenhang"<<setw(15)<<"dongia"<<setw(15)<<"slg"<<setw(15)<<"Thanh tien"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<setw(5)<<i+1;
		y[i].xuat();
	}
	float tong=0;
	for(int i=0;i<n;i++)
	{
		tong=tong+y[i].dongia*y[i].slg;
	}
	cout<<setw(50)<<"Cong thanh tien:"<<tong<<endl;
		
}
void sx(phieu&a)
{
	for (int i=0;i<a.n-1;i++)
	{
		for(int j=i+1;j<a.n;j++)
		{
			if(a.y[i].dongia*a.y[i].slg>a.y[j].dongia*a.y[j].slg)
			{
				hang tp=a.y[i];
					a.y[i]=a.y[j];
					a.y[j]=tp;
				}	
		}
		
		
	}
}
void sua(phieu &a)
{
	for(int i=0;i<a.n;i++)
	{
		if(strcmp(a.y[i].tenhang,"Quat")==0)
		
		
		a.y[i].dongia=20; 
	
	}
}
main()
{
	phieu a;
	a.nhap();
	cout<<"\n=======================PHIEU NHAP HANG==============="<<endl;
	a.xuat();
	cout<<"\n===============PHIEU SAU KHI SAP XEP THEO THANH TIEN==========="<<endl;
	sx(a);
	a.xuat();
	cout<<"\n======================PHIEU SAU KHI SUA==================="<<endl;
	sua(a);
	a.xuat();
	return 0;
}
