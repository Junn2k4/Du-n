#include <bits/stdc++.h>
using namespace std;
class maytinh;
class nsx
{
	private:
		char tennsx[30];
		char diachi[30];
	public:
		void nhap();
		void xuat();
		
};
class may
{
	protected:
		char nhanhieu[30];
		nsx x;
		float giathanh;
	public:
		void nhap();
		void xuat();
	friend void diem(maytinh *a,int n);
	friend void sx(maytinh *a ,int n);
};
class maytinh:public may
{
	private:
		int tocdo;
		int dlram;
		int dlhdd;
	public:
		void nhap();
		void xuat();
		
};
void nsx::nhap()
{
	cout<<"\n nhap ten nha san xuat:";		fflush(stdin);		gets(tennsx);
	cout<<"\n nhap dia chi nha san xuat:";	fflush(stdin);		gets(diachi);
}
void nsx::xuat()
{
	cout<<setw(15)<<tennsx<<setw(15)<<diachi;
}
void may::nhap()
{
	cout<<"\n nhap ten nhan hieu:";		fflush(stdin);		gets(nhanhieu);
	x.nhap();
	cout<<"\n nhap gia thanh:";			cin>>giathanh;
}
void may::xuat()
{
	cout<<setw(15)<<nhanhieu;
	x.xuat();
	cout<<setw(15)<<giathanh;
}
void maytinh::nhap()
{
	may::nhap();
	cout<<"\n nhap toc do:";			cin>>tocdo;
	cout<<"\n nhap dl ram:";			cin>>dlram;
	cout<<"\n nhap dl hdd:";			cin>>dlhdd;
}
void maytinh::xuat()
{
	may::xuat();
	cout<<setw(15)<<tocdo<<setw(15)<<dlram<<setw(15)<<dlhdd<<endl;
}

void diem(maytinh *a,int n)
{
	for (int i=0;i<n;i++)
	if(strcmp(a[i].nhanhieu,"HP")==0)
	a[i].xuat();
}
void sx(maytinh *a ,int n)
{
	for (int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].giathanh>a[j].giathanh)
			{
				maytinh tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}
main()
{
	int n;
	maytinh *y;
	y=new maytinh[n];
	do
	{
		cout<<"\n nhap so luong may tinh(2<=n<=30):";
		cin>>n;
		if(n<2 || n>30)
		{
			cout<<"\n Nhap sai so luong.Vui long nhap lai";
		}
	}
	while(n<2 || n>30);
		for(int i=0;i<n;i++)
		{
		cout<<"May tinh thu:"<<i+1<<endl;
		y[i].nhap();
	}
	cout<<setw(20)<<"nhanhieu";
	cout<<setw(15)<<"tennsx"<<setw(15)<<"diachi";
	cout<<setw(15)<<"giathanh";
	cout<<setw(15)<<"tocdo"<<setw(15)<<"dlram"<<setw(15)<<"dlhdd"<<endl;
	for (int i=0;i<n;i++)
	{
		cout<<setw(5)<<i+1;
		y[i].xuat();
	}
	cout<<"\n------HIEN THI NHAN HIEU HP------------"<<endl;
	diem(y,n);
	cout<<"\n========SAP XEP TANG DAN THEO GIA THANH===="<<endl;
	sx(y,n);
	for(int i=0;i<n;i++)
	{
	
		y[i].xuat();
	}
			return 0;
}
