#include <iostream>
#include <fstream>
using namespace std;
class tg
{
	private:
		int h,p,s;
	public:
		tg();
		tg(int a,int b,int c);
		friend istream& operator>>(istream &a, tg &b);
		friend ostream& operator<<(ostream &a, tg b);
		int operator ~();
		int operator -(tg t);
 } ;
tg::tg()
{
	h=p=s=1;
}
tg::tg(int a,int b,int c)
{
	h=a;
	p=b;
	s=c;
}
istream& operator>>(istream &a, tg &b)
{
	
	cout<<"\n nhap so gio:";		a>>b.h;
	cout<<"\n nhap so phut:";		a>>b.p;
	cout<<"\n nhap so giay:";		a>>b.s;
	return a;
}
ostream& operator<<(ostream &a, tg b)
{
	a<<b.h<<"Gio \t"<<b.p<<"Phut \t"<<b.s<<"Giay";
	return a;
	
}
int tg::operator~()
{
	return h*3600+p*60+s;
}
int tg::operator -(tg t)
{
	return (h*3600+p*60+s)-(t.h*3600+t.p*60+t.s);
}
main()
{
	ofstream file("duan1.txt",ios::out);
	tg a(3,4,6),b,c,d;
	cout<<"\n Thong tin thoi gian b:"<<endl;
	cout<<b<<"="<<~b<<"giay"<<endl;
	cout<<"\n NHAP THOI GIAN C:"<<endl;
	cin>>c;
	cout<<"\n NHAP THOI GIAN D:"<<endl;
	cin>>d;
	cout<<"\n Thong tin thoi gian c:"<<endl;
	cout<<c<<"="<<~c<<"giay"<<endl;
	cout<<"\n Thong tin thoi gian d:"<<endl;
	cout<<d<<"="<<~d<<"giay"<<endl;
	cout<<"\n Thoi gian chenh lech cua c va d :"<<c-d<<"giay"<<endl;
	cout<<"\n --------------------------"<<endl;
	cout<<" \n THONG TIN DUOC IN TRONG FILE duan1.txt"<<endl;
	file<<"\n Thong tin thoi gian c:"<<endl;
	file<<c<<"="<<~c<<"giay"<<endl;
	file<<"\n Thong tin thoi gian d:"<<endl;
	file<<d<<"="<<~d<<"giay"<<endl;
	file<<"\n Thoi gian chenh lech cua c va d :"<<c-d<<"giay"<<endl;
	return 0;
}
