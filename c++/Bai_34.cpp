#include<iostream>
#include<math.h>
using namespace std;

class ptbh
{
	private:
		int a,b,c;
	public:
		void nhap();
		void xuat();
		void giai();
		ptbh()
		{
			a=b=c=0;
		}
		ptbh(int m, int n, int p)
		{
			a=m;
			b=n;
			c=p;
		}
};

void ptbh::nhap()
{
	cout<<"\nNhap a: "; cin>>a;
	cout<<"\nNhap b: "; cin>>b;
	cout<<"\nNhap c: "; cin>>c;
}

void ptbh::xuat()
{
	cout<<a<<"x^2 + "<<b<<"x + "<<c;
}

void ptbh::giai()
{
	float delta=b*b -4*a*c;
	if(delta > 0) 
		cout<<"\nPhuong trinh co hai nghiem phan biet: "<<(-b + sqrt(delta))/2*a
		<<" va "<<(-b - sqrt(delta))/2*a;
	
	else if(delta < 0)
		cout<<"\nPhuong trinh vo nghiem:";
	
	else
		cout<<"\nPhuong trinh co nghiem kep: "<<-b/2*a;
}


main()
{
	ptbh p(1,2,-5),p1;
	cout<<"\nPhuong trinh bac hai p la: ";
	p.xuat();
	p.giai();
	
	p1.nhap();
	p1.xuat();
	p1.giai();
}

