#include <bits/stdc++.h>
using namespace std;
class tivi;
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
		char tennsx[20];
		char dcnsx[30];
	public:
		void nhap();
		void xuat();
		
};
class hang
{
	protected:
		char tenh[10];
		nsx x;
		int dongia;
	public:
		void nhap();
		void xuat();
	friend void hien(tivi a[20],int n);
};
class tivi:public hang
{
	private:
		int kichthuoc;
		date ngaynhap;
	public:
		void nhap();
		void xuat();
	friend void hien(tivi a[20],int n);
};
void date::nhap()
{
	cout<<"\n nhap ngay:";		cin>>d;
	cout<<"\n nhap thang:";		cin>>m;
	cout<<"\n nhap nam:";		cin>>y;
}
void date::xuat()
{
	cout<<setw(15)<<d<<"/"<<m<<"/"<<y<<endl;
}
void nsx::nhap()
{
	cout<<"\n nhap ten nha san xuat:";				fflush(stdin);		gets(tennsx);
	cout<<"\n nhap dia chi nha san xuat:";			fflush(stdin);		gets(dcnsx);
}
void nsx::xuat()
{
	cout<<setw(15)<<tennsx<<setw(15)<<dcnsx;
}
void hang::nhap()
{
	cout<<"\n nhap ten hang:";						fflush(stdin);		gets(tenh);
	x.nhap();
	cout<<"\n nhap don gia :";				cin>>dongia;
}
void hang::xuat()
{
	cout<<setw(15)<<tenh;
	x.xuat();
	cout<<setw(15)<<dongia;
}
void tivi::nhap()
{
	hang::nhap();
	cout<<"\n nhap kich thuoc:";		cin>>kichthuoc;
	ngaynhap.nhap();
}
void tivi::xuat()
{
	hang::xuat();
	cout<<setw(15)<<kichthuoc;
	ngaynhap.xuat();
}
void hien(tivi a[20],int n)
{
	bool d=false; 
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i].tenh,"LG")==0)
		{
			{
				if(!d) 
				{	
			cout<<"Danh sach Tivi co hang LG:"<<endl;
			cout<<setw(20)<<"Ten hang";
			cout<<setw(15)<<"Ten nha sx"<<setw(15)<<"dia chi sx";
			cout<<setw(15)<<"Don gia";
			cout<<setw(15)<<"Kich thuoc";
			cout<<setw(17)<<"Date"<<endl;
			d=true; 
			}
		a[i].xuat(); 
		}
	}
}
	if(!d) 
	{
		cout<<"\n Khong co Tivi hang LG"<<endl;
	}
}

void xoa(tivi a[20],int &n)
{
	int k;
	do{
		cout<<"\n nhap vi tri xoa:";		cin>>k; 
	} 
	while(k<1 ||k>n);
	for(int i=k;i<n;i++)
	{
		a[i]=a[i+1]; 
		} 
	n--; 
 } 
 
main()
{
	tivi a[30];
	int n;
	cout<<"\n nhap so luong ti vi 0<=n<=30:";		cin>>n;
	while(n<0 ||n>30)
	{
		cout<<"\n nhap lai:";
		cin>>n;
	}
	for(int i=0;i<n;i++)
	{
		cout<<"NHap thong tin Tivi thu:"<<i+1<<endl;
		a[i].nhap();
	}
	cout<<"\n DANH SACH TIVI:"<<endl;
	cout<<setw(20)<<"Ten hang";
	cout<<setw(15)<<"Ten nha sx"<<setw(15)<<"dia chi sx";
	cout<<setw(15)<<"Don gia";
	cout<<setw(15)<<"Kich thuoc";
	cout<<setw(17)<<"Date"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<setw(5)<<i+1;
		a[i].xuat();
	}
	cout<<"\n-----------------------------------"<<endl;
	hien(a,n);
	cout<<"\n----------------------"<<endl;
	xoa(a,n) ;
	cout<<"\n DANH SACH TIVI SAU KHI XOA:"<<endl;
	cout<<setw(20)<<"Ten hang";
	cout<<setw(15)<<"Ten nha sx"<<setw(15)<<"dia chi sx";
	cout<<setw(15)<<"Don gia";
	cout<<setw(15)<<"Kich thuoc";
	cout<<setw(17)<<"Date"<<endl;
	for(int i=0;i<n;i++)
	{
		a[i].xuat(); 
	return 0;
}
}
