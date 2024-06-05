#include<iostream>
using namespace std;

class phanso
{
	private:
		int a,b;
	public:
		phanso()
		{
			a=b=0;
		}
		
		phanso(int m, int n)
		{
			a=m;
			b=n;
		}
		
		void xuat()
		{
			cout<<"\nPhan so: "<<a<<"/"<<b;
		}
		
		phanso operator+(phanso y)
		{
			phanso kq;
			kq.a=a*y.b + y.a*b;
			kq.b=b*y.b;
			return kq;
		}
		
		
};




main()
{
	phanso a,p1(5,6), p2(2,5);
	p1.xuat();
	p2.xuat();
	cout<<"\n y1 + y2 = ";
	a=p1+p2;
	a.xuat();
}
