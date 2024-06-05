#include<iostream>
using namespace std;

class matran
{
	private:
		int a[10][10];
		int n,m;
	public:
		void nhap();
		matran operator+(matran x);
		void xuat();
		matran operator-(matran x);
		void tong_chan();
};


void matran::nhap()
{
	cout<<"\nNhap so hang m: ";   cin>>m;
	cout<<"\nNhap so cot n: ";	  cin>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			cout<<"\nNhap phan tu "<<i<<j<<": ";
			cin>>a[i][j];
		}
}

void matran::xuat()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<"\t"<<a[i][j];
		cout<<"\n";	
	}
}


matran matran::operator+(matran x)
{
	if(x.m==m && x.n==n)
	{
		matran kq;
		kq.n=n;
		kq.m=m;
	
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				kq.a[i][j]=a[i][j] + x.a[i][j];
		return kq;
	}
	else
		cout<<"\nKhong the cong hai ma tran: "<<endl;
}

matran matran::operator-(matran x)
{
	if(x.m==m && x.n==n)
	{
		matran kq;
		kq.n=n;
		kq.m=m;
	
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				kq.a[i][j]=a[i][j] - x.a[i][j];
		return kq;
	}
	else
		cout<<"\nKhong the tru hai mai tran: "<<endl;
}	

void matran::tong_chan()
{
	int S=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(a[i][j] %2 ==0)
				S=S + a[i][j];
	cout<<"\nTong cac so chan trong ma tran 1 la: "<<S;
}

main()
{
	matran a,b;
	a.nhap();
	cout<<"\nMa tran vua nhap la: "<<endl;
	a.xuat();
	
	b.nhap();
	cout<<"\nMa tran vua nhap la: "<<endl;
	b.xuat();
	
	cout<<"\nTong hai ma tran vua nhap la: "<<endl;
	(a+b).xuat();
	
	cout<<"\nHieu hai ma tran vua nhap la: "<<endl;
	(a-b).xuat();
	
	b.tong_chan();
	
	
}
