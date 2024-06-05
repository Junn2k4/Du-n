#include<iostream>
using namespace std;

class matran
{
	private:
		int a[10][10];
		int m,n;
	public:
		void nhap();
		void xuat();
		matran operator+(matran x);
		matran operator-(matran y);
		void tong();
		void vt_mincp();
		void tong_le();
		void max_chan();
};

void matran::nhap()
{
	cout<<"\nNhap so hang: ";		cin>>m;
	cout<<"\nNhap so cot: ";		cin>>n;
	
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
			cout<<a[i][j]<<"\t";
		cout<<"\n";
	}
}

matran matran::operator+(matran x)
{
	matran kq;
	kq.m=m;
	kq.n=n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			kq.a[i][j]=a[i][j] + x.a[i][j];
	return kq;	
}

matran matran::operator-(matran x)
{
	matran kq;
	kq.m=m;
	kq.n=n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			kq.a[i][j]=a[i][j] - x.a[i][j];
	return kq;	
}

void matran::tong()
{
	int S=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			S=S+ a[i][j];
		cout<<"\nTong phan tu dong "<<i<<": "<<S;
		S=0;
	}
}
int ktcp(int a)
{
	for(int i=1;i<=a;i++)
		if(a==i*i)
			return 1;
	return 0;	
}

void matran::vt_mincp()
{
	int min;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(ktcp(a[i][j])==1)
				min=a[i][j];
				
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(ktcp(a[i][j])==1 && a[i][j]<min)
				min=a[i][j];
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]==min)
				cout<<"\nVi tri so chinh phuong be nhat la phan tu "<<i<<j;
}

void matran::tong_le()
{
	int S=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(a[i][j] %2 ==1)
				S=S + a[i][j];
	cout<<"\nTong cac so le trong ma tran la: "<<S;
}

void matran::max_chan()
{
	int max;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(a[i][j] % 2 ==0)
				max=a[i][j];
				
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(a[i][j] % 2 ==0 && a[i][j] > max)
				max=a[i][j];
	cout<<"\nSo chan lon nhat trong ma tran la: "<<max;
}
main()
{
	matran a,b;
	a.nhap();
	cout<<"\nMa tran a: "<<endl;
	a.xuat();
	
	b.nhap();
	cout<<"\nMa tran b: "<<endl;
	b.xuat();
	
	cout<<"\nTong ma tran a + b = "<<endl;
	(a+b).xuat();
	
	cout<<"\nHieu ma tran a - b = "<<endl;
	(a-b).xuat();
	
	a.tong();
	b.vt_mincp();
	a.tong_le();
	b.max_chan();
}
