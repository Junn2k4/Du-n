#include<iostream>
#include<iomanip>
using namespace std;
class mp;
class hcn
{
	private:
		char ten[20];
		char mau[10];
		float d,r;
	public:
		void nhap();
		void xuat();
};

class ht
{
	private:
		char ten[20];
		char mau[10];
		char tam[15];
		float bk;
	public:
		void nhap();
		void xuat();
};

class mp
{
	private:
		hcn a;
		ht b;
	public:
		void nhap();
		void xuat();
};

void hcn::nhap()
{
	cout<<"\nNhap ten hcn: ";		fflush(stdin);		gets(ten);
	cout<<"\nNhap mau hcn: ";		fflush(stdin);		gets(mau);
	cout<<"\nNhap chieu dai:";							cin>>d;
	cout<<"\nNhap chieu rong:";							cin>>r;
}

void hcn::xuat()
{
	cout<<setw(15)<<ten<<setw(10)<<mau<<setw(10)<<d<<setw(10)<<r<<endl;
}

void ht::nhap()
{
	cout<<"\nNhap ten ht: ";		fflush(stdin);		gets(ten);
	cout<<"\nNhap mau ht: ";		fflush(stdin);		gets(mau);
	cout<<"\nNhap toa do tam I:";	fflush(stdin);		gets(tam);
	cout<<"\nNhap chieu dai ban kinh:";					cin>>bk;
}

void ht::xuat()
{
	cout<<setw(15)<<ten<<setw(10)<<mau<<setw(10)<<tam<<setw(10)<<bk<<endl;
}

void mp::nhap()
{
	a.nhap();
	b.nhap();
}

void mp::xuat()
{
	cout<<"\nThong tin hinh chu nhat la: "<<endl;
	a.xuat();
	cout<<"\nThong tin hinh tron la: "	<<endl;
	b.xuat();
}


main()
{
	mp a;
	a.nhap();
	a.xuat();
}
