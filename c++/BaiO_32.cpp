#include<iostream>
#include<fstream>
using namespace std;

class tg
{
	private:
		float a,b,c;
	public:
		float operator++();
		friend istream& operator>>(istream &x,tg &y);
		friend ostream& operator<<(ostream &z,tg t);
};

float tg::operator++()
{
	return (a+b+c);
}

istream& operator>>(istream &x,tg &y)
{
	cout<<"\nNhap canh a: ";		x>>y.a;
	cout<<"\nNhap canh b: ";		x>>y.b;
	cout<<"\nNhap canh c: ";		x>>y.c;
	return x;	
}

ostream& operator<<(ostream &z,tg t)
{
	z<<"\nBa canh cua tam giac lan luot la: "<<t.a<<" , "<<t.b
	<<" , "<<t.c<<endl;
	z<<"Chu vi tam giac la: "<<++t;
	return z;
}

main()
{
	tg p,q;
	fstream b("INOUT.txt",ios::out);
	
	cout<<"\nNhap cac canh tam giac p: ";
	cin>>p;
	
	cout<<"\nNhap cac canh tam giac q: ";
	cin>>q;
	
	cout<<"\nThong tin tam giac p: "<<p;
	b<<"\nThong tin tam giac p: "<<p;
	
	cout<<"\nThong tin tam giac p: "<<q;
	b<<"\nThong tin tam giac p: "<<q;
	
}
