#include<iostream>
#include<iomanip>
using namespace std;

class matran
{
	private:
		int a[10][10];
		int m;
	public:
		matran()
		{
			m=0;
		}
		matran(int n)
		{
			m=n;
		}
		friend istream& operator>>(istream& x,matran &y);
		friend ostream& operator<<(ostream& x,matran t);
		matran operator +(matran k);
		matran operator*(matran h);
};

istream& operator>>(istream& x,matran &y)
{	
	for(int i=0;i<y.m;i++)
		for(int j=0;j<y.m;j++)
		{
			cout<<"\nNhap phan tu "<<i<<j<<": ";
			x>>y.a[i][j];
		}
}

ostream& operator<<(ostream& z,matran t)
{
	for(int i=0;i<t.m;i++)
	{
		for(int j=0;j<t.m;j++)
		{
			z<<t.a[i][j]<<"\t";
		}
		z<<endl;
	}
}

matran matran::operator+(matran k)
{
	matran kq;
	kq.m=m;
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			kq.a[i][j]=a[i][j] + k.a[i][j];
	return kq;
}

matran matran::operator*(matran h)
{
	matran kq;
	kq.m=m;
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			kq.a[i][j]=a[i][j] * h.a[i][j];
	return kq;
}

main()
{
	matran x(3),y(3);
	
	cout<<"\nNhap ma tran x: ";
	cin>>x;
	cout<<"\nMa tran x la: "<<endl;
	cout<<x;
	
	cout<<"\nNhap ma tran y: ";
	cin>>y;
	cout<<"\nMa tran y la: "<<endl;
	cout<<y;
	
	cout<<"\nTong hai ma tran: "<<endl<<x+y;
	
	cout<<"\nTich hai ma tran: "<<endl<<x*y;
	
	
}
