#include<iostream>
using namespace std;

class phanso
{
	private:
		float a,b;
	public:
		friend istream& operator>>(istream& m, phanso &n);
		friend ostream& operator<<(ostream& p, phanso q);
		phanso operator*(phanso h);
		phanso operator/(phanso h);
		phanso operator+(phanso h);
		phanso operator-(phanso h);
		float operator --();
};

istream& operator>>(istream& m, phanso &n)
{
	cout<<"\nNhap tu so: ";  	m>>n.a;
	cout<<"\nNhap mau so: ";	m>>n.b;	
	return m;
}

ostream& operator<<(ostream& p, phanso q)
{
	p<<q.a<<"/"<<q.b;
	return p;
}

phanso phanso::operator*(phanso h)
{
	phanso kq;
	kq.a=a*h.a;
	kq.b=b*h.b;
	return kq;
}

phanso phanso::operator/(phanso h)
{
	phanso kq;
	kq.a=a*h.b;
	kq.b=b*h.a;
	return kq;
}

phanso phanso::operator+(phanso h)
{
	phanso kq;
	kq.a=a*h.b + h.a*b;
	kq.b=b*h.b;
	return kq;
}

phanso phanso::operator-(phanso h)
{
	phanso kq;
	kq.a=a*h.b - h.a*b;
	kq.b=b*h.b;
	return kq;
}
float phanso::operator --()
{
	return a/b;
}

main()
{
	phanso a,b;
	
	cout<<"\nNhap he so cho phan so a: ";
	cin>>a;
	cout<<"\nNhap he so cho phan so b: ";
	cin>>b;
	cout<<"\nHai phan so a, b lan luot la: "<<a<<" va "<<b<<endl ;
	
	cout<<"\nTich hai phan so la: "<<a*b<<"="<<--(a*b);
	cout<<"\nThuong hai phan so la: "<<a/b<<"="<<--(a/b);
	cout<<"\nTong hai phan so la: "<<a+b<<"="<<--(a+b);
	cout<<"\nHieu hai phan so la: "<<a-b<<"="<<--(a-b);
	
	

	
}





