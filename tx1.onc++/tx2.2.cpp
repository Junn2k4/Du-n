#include<bits/stdc++.h>
using namespace std;

class THOIGIAN
{
	private:
		int gio;
		int phut;
		int giay;
	public:
		THOIGIAN();
		THOIGIAN(int a,int b,int c);
		friend istream& operator>>(istream &in, THOIGIAN &d);
		friend ostream& operator<<(ostream &out, THOIGIAN d);	
		friend int operator -(THOIGIAN g,THOIGIAN h);	
};

THOIGIAN::THOIGIAN()
{
	gio=phut=giay=1;
}

THOIGIAN::THOIGIAN(int a,int b,int c)
{
	gio=a;
	phut=b;
	giay=c;
}

istream& operator>>(istream &in, THOIGIAN &d)
{
	cout<<"\n Nhap gio: ";		in>>d.gio;
	cout<<"\n Nhap phut: ";		in>>d.phut;
	cout<<"\n Nhap giay: ";		in>>d.giay;
	return in;	
}

ostream& operator<<(ostream &out, THOIGIAN d)
{
	out<<d.gio<<" gio "<<d.phut<<" phut "<<d.giay<<" giay "<<endl;
	return out;	
}

int operator -(THOIGIAN g,THOIGIAN h)
{
	return (g.gio*3600+g.phut*60+g.giay)-(h.gio*3600+h.phut*60+h.giay);
}

int main()
{
	ofstream file("ketqua1.txt",ios::out);
	THOIGIAN e,f(2,3,4),g,h;
	cout<<e<<endl;
	cout<<f<<endl;
	cout<<"\n Thong tin moc thoi gian 1: ";
	cin>>g;
	cout<<g<<endl;
	cout<<"\n Thong tin moc thoi gian 2: ";	
	cin>>h;
	cout<<h<<endl;
	cout<<"So giay chenh lech: "<<h-g<<endl;
	file<<"\n Thong tin moc thoi gian 1: ";
	file<<g<<endl;
	file<<"\n Thong tin moc thoi gian 2: ";
	file<<h<<endl;
	file<<"\n So giay chenh lech: "<<h-g<<endl;
	file.close();
	return 0;
}



