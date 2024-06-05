#include<iostream>
using namespace std;

class matrix
{
	private:
		double a[10][10];
		int n,m;
	public:
		friend istream& operator>>(istream& x, matrix &y);
		friend ostream& operator<<(ostream& c,matrix d);
		matrix operator --();
		matrix operator +(matrix x);
		matrix operator -(matrix x);
};

istream& operator>>(istream& x, matrix &y)
{	
	cout<<"\nNhap n: ";		x>>y.n;
	cout<<"\nNhap m: ";		x>>y.m;

	//y.a=new double[y.m][y.n];
	for(int i=0;i<y.m;i++)
		for(int j=0;j<y.n;j++)
		{
			cout<<"\nNhap phan tu "<<i<<j<<": ";
			x>>y.a[i][j];
		}
	return x; 
}

ostream& operator<<(ostream& c,matrix d)
{
	for(int i=0;i<d.m;i++)
	{
		for(int j=0;j<d.n;j++)
		{
			c<<d.a[i][j]<<"\t";
		}
		c<<endl;
	}
	return c; 
}

matrix matrix::operator --()
{
	matrix kq;
	kq.m=m;
	kq.n=n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			kq.a[i][j]=-a[i][j];
	return kq;
}

matrix matrix::operator +(matrix x)
{
	matrix kq;
	kq.m=m;
	kq.n=n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			kq.a[i][j]=a[i][j] + x.a[i][j];
		}	
	return kq;	
}

matrix matrix::operator -(matrix x)
{
	matrix kq;
	kq.m=m;
	kq.n=n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			kq.a[i][j]=a[i][j] - x.a[i][j];
		}	
	return kq;	
}

main()
{
	matrix c,d;
	cout<<"\nNhap ma tran c: ";
	cin>>c;
	
	cout<<"\nNhap ma tran d: ";
	cin>>d;
	
	cout<<"\nMa tran c la: "<<endl;
	cout<<c;
	
	cout<<"\nMa tran d la: "<<endl;
	cout<<d;	
	
	cout<<"\nDoi dau ma tran c: "<<endl<<--c;
	
	cout<<"\nTong hai ma tran: "<<endl<<c+d;
	
	cout<<"\nHieu hai ma tran: "<<endl<<c-d;
}

