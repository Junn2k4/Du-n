#include<iostream>
using namespace std;

class matran
{
	private:
		int a[10][10];
		int n;
	public:
		void nhap();
		void tong();
		void xuat();
};

void matran::nhap()
{
	cout<<"\nNhap bac ma tran n: ";   cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cout<<"\nNhap phan tu "<<i<<j<<": ";
			cin>>a[i][j];
		}
}

void matran::xuat()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<"\t"<<a[i][j];
		cout<<"\n";	
	}
}

void matran::tong()
{
	int S=0;
	for(int i=0;i<n;i++)
		S=S + a[i][i];
		
	cout<<"\nTong cac phan tu tren duong cheo chinh la: "<<S;
	
			
}

main()
{
	matran a;
	a.nhap();
	cout<<"\nMa tran vua nhap la: "<<endl;
	a.xuat();
	
	a.tong();
}
