#include <iostream>
#include <fstream>
using namespace std;
class matran
{
	private:
		double a[30][30];
		int m,n;
	public:
		matran();
		matran(int b, int c);
		friend istream&operator>>(istream &a,matran&b);
		friend ostream&operator<<(ostream &a,matran b);
		matran operator--();
};
matran::matran()
{
	m=0;
	n=0;
}
matran::matran(int b,int c)
{
	m=b;
	n=c;
}
istream&operator>>(istream &a,matran&b)
{
	cout<<"\n nhap hang:";
	a>>b.m;
	cout<<"\n nhap cot:";
	a>>b.n;
	for( int i=0;i<b.m;i++)
	{
		for(int j=0;j<b.n;j++)
		{
			cout<<"\n phan tu ["<<i<<j<<"]:";
			a>>b.a[i][j];
		}
	}
	return a;
}
ostream&operator<<(ostream &a,matran b)
{
	for( int i=0;i<b.m;i++)
	{
		for(int j=0;j<b.n;j++)
		{
			a<<b.a[i][j]<<"\t";
		}
		a<<endl;
	}
	return a;
}
matran matran::operator--()
{
	matran kq;
	kq.m=n;
	kq.n=m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<kq.m;j++)
		{
			kq.a[i][j]=a[j][i];	
		}
	}
	return kq;
}
main()
{
	ofstream file("Oke.txt",ios::out);
	matran a,b;
	cout<<"\n nhap ma tran a:";
	cin>>a;
	cout<<"\n nhap ma tran b:";
	cin>>b;
	cout<<"\n Ma tran a:"<<endl;
	cout<<a<<endl;
	cout<<"\n Ma tran b"<<endl;
	cout<<b<<endl;
	cout<<"\n chuyen vi ma tran a:"<<endl;
	matran c=--a;
	cout<<c<<endl;
	file<<"\n ma tran a:";
	file<<a<<endl;
	file<<"\n ma tran b:";
	file<<b<<endl;
	file<<"\n chuyen vi ma tran a:"<<endl;
	file<<c<<endl;;
	cout<<"\n KET QUA IN VAO Oke.txt";
	return 0;
	
	
}
