#include<bits/stdc++.h>
using namespace std;
class ptb1
{
	private:
		int a,b,c;
	public:
		ptb1();
		ptb1(int m,int n,int t);
		// ham toan tu nhap, khong la phuong toan tu nhap
	friend istream& operator >>( istream& d,ptb1 &e);
	friend ostream& operator <<(ostream& f, ptb1 g);	
		void nhap();// phuong thuc
		void xuat();// phuong thuc
		// phuong thuc toan tu - ham toan tu
//c1:
	friend ptb1 operator +(ptb1 x,ptb1 y); 
//c2:	ptb1 operator -(ptb1 x);
		ptb1 operator -(ptb1 x);
		int operator --();
};
ptb1::ptb1()
{
	a=0;
	b=0;
	c=0;
}
ptb1::ptb1(int m, int n, int t)
{
	a=m;
	b=n;
	c=t;
}
istream& operator >>( istream& d,ptb1 &e)
{
	cout<<"\n nhap he so a: ";	d>>e.a;	
	cout<<"\n nhap he so b: ";	d>>e.b;
	cout<<"\n nhap he so c: ";	d>>e.c;
return d;
}
ostream& operator <<(ostream& f, ptb1 g) 
{
	f<<g.a<<"x+"<<g.b<<"y+"<<g.c<<"=0";
return f;	
}
ptb1 operator +(ptb1 x,ptb1 y)
{
	ptb1 kq;
	kq.a=x.a +y.a;
	kq.b=x.b+y.b;
	kq.c=x.c+y.c;
return kq;	
}
ptb1 ptb1::operator -(ptb1 x)
{
	ptb1 kq;
	kq.a=a-x.a;
	kq.b=b-x.b;
	kq.c=c-x.c;
return kq;
}
int ptb1::operator --()
{
	return a+b+c;
}


main()
{
	ptb1 P,Q,K;
	cout<<"\n nhap cho dt P:";
	cin>>P;
	cout<<"\n in dt P:";
	cout<<P;
	cout<<"\n nhap cho dt Q:";
	cin>>Q;
	cout<<"\n in dt Q:";
	cout<<Q;
	K=P+Q;
	cout<<"\n K=P+Q=  "<<K;
	cout<<"\n P-Q= "<<P-Q;
	cout<<"\n tong cac he so K: "<<--K;
	
}
