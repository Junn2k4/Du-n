#include<iostream>
using namespace std;

class sophuc
{
	private:
		float a,b;
	public:
//		sophuc()
//		{
//			a=b=0;
//		}
		sophuc(float m, float n)
		{
			a=m;
			b=n;
		}
		friend ostream& operator<<(ostream& k, sophuc l);
		sophuc operator+(sophuc x);
		sophuc operator-(sophuc x);
};

ostream& operator<<(ostream& k, sophuc l)
{
	k<<l.a<<" + "<<l.b<<"*i";
	return k;
}

sophuc sophuc::operator+(sophuc x)
{
	sophuc kq;
	kq.a=a+	x.a;
	kq.b=b+ x.b;
	return kq;
} 

sophuc sophuc::operator-(sophuc x)
{
	sophuc kq;
	kq.a=a - x.a;
	kq.b=b - x.b;
	return kq;
} 

main()
{
	sophuc sp1(2,3),sp2(5,6),sp3,sp4;
	sp3=sp1+sp2;
	sp4=sp1-sp2;
	cout<<"\nSo phuc sp1: "<<sp1;
	cout<<"\nSo phuc sp2: "<<sp2;
	cout<<"\nTong hai so phuc da nhap la: "<<sp3;
	cout<<"\nHieu hai so phuc da nhap la: "<<sp4;
	
	
}





