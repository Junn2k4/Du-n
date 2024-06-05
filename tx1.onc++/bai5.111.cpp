#include <iostream>
using namespace std;
class phanso
{
	private:
		float tuso,mauso;
	public:
		friend istream& operator>>(istream&a,phanso &b);
		friend ostream& operator<<(ostream&c,phanso d);
		phanso operator+(phanso h);
		phanso operator-(phanso h);
		phanso operator*(phanso h);
		phanso operator/(phanso h);
		float operator++();
};
istream& operator>>(istream&a,phanso &b)
{
	cout<<"\n phan so:";
	cout<<"\n nhap tu so:";	a>>b.tuso;
	cout<<"\n nhap mau so:";a>>b.mauso;
	return a;
}
ostream& operator<<(ostream&c,phanso d)
{
	c<<d.tuso<<"/"<<d.mauso;
	return c;
}
phanso phanso::operator+(phanso h)
{
	phanso kq;
	kq.tuso=this->tuso*h.mauso+this->mauso*h.tuso;
	kq.mauso=this->mauso*h.mauso;
	return kq;
	
}
phanso phanso::operator-(phanso h)
{
	phanso kq;
	kq.tuso=this->tuso*h.mauso-this->mauso*h.tuso;
	kq.mauso=this->mauso*h.mauso;
	return kq;
	
}
phanso phanso::operator*(phanso h)
{
	phanso kq;
	kq.tuso=this->tuso*h.tuso;
	kq.mauso=this->mauso*h.mauso;
	return kq;	
}
phanso phanso::operator/(phanso h)
{
	phanso kq;
	kq.tuso=this->tuso*h.mauso;
	kq.mauso=this->mauso*h.tuso;
	return kq;
	
}
float phanso ::operator++()
{
	return tuso/mauso;
}
main() 
{
	phanso a,b;
	cin>>a;
	cin>>b;
	cout<<"\n2 phan so lan luot la:"<<a<<" va "<<b<<endl;
	cout<<"\ncong 2 phan so:"<<a+b<<" = "<<++(a+b);
	cout<<" \ntru 2 phan so:"<<a-b<<" = "<<++(a-b); 
	cout<<" \ntich 2 phan so:"<<a*b<<" = "<<++(a*b);
	cout<<"\n chia 2 phan so:"<<a/b<<" = "<<++(a/b);
		return 0;
}
