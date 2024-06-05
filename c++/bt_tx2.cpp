#include<iostream>
#include<iomanip>
#include <bits/stdc++.h> 
using namespace std;
class maytinh;
class nsx
{
	private:
		char tennsx[20];
		char dc[20];
	public:
		void nhap();
		void xuat();
	
};
class may
{
	private:
		char nhanhieu[20];
		nsx x;
		float gt;
	public:
		void nhap();
		void xuat();
	friend void hienthi(maytinh a[20],int n);
};
class maytinh:public may
{
	protected:
		int tocdo;
		int dlram;
		int dlhdd;
	public:
		void nhap();
		void xuat();
	friend void hienthi(maytinh a[],int n);
};
void nsx::nhap()
{
	cout<<"nhapten nsx";fflush(stdin);gets(tennsx);
	cout<<"nhapdc nsx";fflush(stdin);gets(dc);
}
void nsx::xuat()
{
	cout<<"nhasx:"<<tennsx<<endl;
	cout<<"diachi"<<dc<<endl;
}
void may::nhap()
{
	cout<<"nhan hieu";fflush(stdin);gets(nhanhieu);
	x.nhap();
	cout<<"gia thanh";cin>>gt;
}
void may::xuat()
{
	cout<<"nhan hieu"<<nhanhieu<<endl;
	x.xuat();
	cout<<"giathanh"<<gt<<endl<<endl;
}
void maytinh::nhap()
{
	cout<<"toc do";cin>>tocdo;
	cout<<"dlram";cin>>dlram;
	cout<<"dlhdd";cin>>dlhdd;
	may::nhap();
}
void maytinh::xuat()
{
	cout<<"toc do"<<tocdo<<endl;
	cout<<"dl ram"<<dlram<<endl;
	cout<<"dl hdd"<<dlhdd<<endl;
	may::xuat();
}
void hienthi(maytinh a[20],int n)
{
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i].nhanhieu,"HP")==0) 
		{
		
			a[i].xuat();
	}
}
}
main()
{
	maytinh a[20];
	int n;
	cout<<"nhap so luong:";cin>>n;
	for(int i=0;i<n;i++)
		a[i].nhap();
	cout<<"____________________danh sach may"<<endl;
	for(int i=0;i<n;i++)
		a[i].xuat();
	cout<<"danh sach nsx nhan hieu HP"<<endl;
	hienthi(a,n);
		return 0; 
};
