#include<iostream>
using namespace std;

class ttb2
{
	private:
		float a,b,c;
	public:
		ttb2()
		{
			a=b=c=0;
		}
		ttb2(float m, float n, float p)
		{
			a=m;
			b=n;
			c=p;
		}
		friend ostream& operator<<(ostream& x, ttb2 y);
		ttb2 operator --();
		ttb2 operator+(ttb2 x);
		ttb2 operator-(ttb2 x);
		float operator !();
		//pptt tra ve gia tri lon nhat cua he so a,b,c trong mot tam thuc
};

ostream& operator<<(ostream& x, ttb2 y)
{
	x<<y.a<<"x^2 + "<<y.b<<"x + "<<y.c;
	return x;
}

ttb2 ttb2::operator --()
{
	ttb2 kq;
	kq.a=-a;
	kq.b=-b;
	kq.c=-c;
	return kq;
}

ttb2 ttb2::operator +(ttb2 x)
{
	ttb2 kq;
	kq.a=a+x.a;
	kq.b=b+x.b;
	kq.c=c+x.c;
	return kq;
}

ttb2 ttb2::operator -(ttb2 x)
{
	ttb2 kq;
	kq.a=a-x.a;
	kq.b=b-x.b;
	kq.c=c-x.c;
	return kq;
}

float ttb2::operator !()
{
	float x[3]={a,b,c};
	float gtln=x[0];
	for(int i=0;i<3;i++)
		if(x[i]>gtln)
			gtln=x[i];
	return gtln;	
}
main()
{
	ttb2 a(3,4,5),b(5,6,7),c,d;
	c=--a;
	d=--b;
	
	cout<<"\nTam thuc a sau khi dao dau la: "<<c;
	cout<<"\nTam thuc b sau khi dao dau la: "<<d;
	
	cout<<"\nTong hai tam thuc vua dao dau la: "<<c+d;
	cout<<"\nHieu hai tam thuc vua dao dau la: "<<c-d;
	
	cout<<"\nHe so lon nhat cua tam thuc a la: "<<!a;
	cout<<"\nHe so lon nhat cua tam thuc a la: "<<!d;
	
	
	
}



