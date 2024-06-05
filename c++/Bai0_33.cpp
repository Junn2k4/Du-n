#include<iostream>
using namespace std;

class mt
{
	private:
		double **a;
		int m,n;
	public:
		friend istream& operator>>(istream& x, mt &y);
		friend ostream& operator<<(ostream& c,mt d);
		mt operator --();
};

istream& operator>>(istream& x, mt &y)
{	
	cout<<"\nNhap n: ";		x>>y.n;
	cout<<"\nNhap m: ";		x>>y.m;
	
	y.a = new double*[y.m];
	for(int i = 0; i<y.m; i++)
  		 y.a[i] = new double[y.n];
	//y.a=new double[y.m][y.n];
	for(int i=0;i<y.m;i++)
		for(int j=0;j<y.n;j++)
		{
			cout<<"\nNhap phan tu "<<i<<j<<": ";
			x>>y.a[i][j];
		}
}

ostream& operator<<(ostream& c,mt d)
{
	for(int i=0;i<d.m;i++)
	{
		for(int j=0;j<d.n;j++)
		{
			c<<d.a[i][j]<<"\t";
		}
		c<<endl;
	}
}

mt mt::operator --()
{
	mt x;
	for(int i=0;i<x.n;i++)
		for(int j=0;j<x.m;j++)
		{
			double tg=x.a[i][j];
			x.a[i][j]=x.a[j][i];
			x.a[j][i]=tg;
			
		}
	return x;
}
main()
{
	mt a;
	cin>>a;
	cout<<"\nMa tran vua nhap la: "<<endl;
	cout<<a;	
	
	cout<<"\nMa tran chuyen vi la: "<<--a<<endl;
}
