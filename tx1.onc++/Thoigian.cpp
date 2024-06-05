#include<bits/stdc++.h>
using namespace std;

class THOIGIAN
{
	private:
		int gio,phut,giay;
	public:
		THOIGIAN();
		THOIGIAN(int a,int b,int c);
		friend istream &operator>>(istream &in,THOIGIAN &d);
		friend ostream &operator<<(ostream &out,THOIGIAN d);
		friend int operator -(THOIGIAN m,THOIGIAN n);
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

istream &operator>>(istream &in,THOIGIAN &d)
{
	cout<<"\n Nhap gio: ";		in>>d.gio;
	cout<<"\n Nhap phut: ";		in>>d.phut;
	cout<<"\n Nhap giay: ";		in>>d.giay;
	return in;	
}

ostream &operator<<(ostream &out,THOIGIAN d)
{
	out<<d.gio<<" gio "<<d.phut<<" phut "<<d.giay<<" giay "<<endl;
	return out;
}

int operator -(THOIGIAN m,THOIGIAN n)
{
	return (n.gio*3600+n.phut*60+n.giay)-(m.gio*3600+m.phut*60+m.giay);
}
int main()
{
	ofstream file("THOIGIAN.txt",ios::out);
	THOIGIAN e,f(2,3,4),g,h;
	cout<<e<<endl;
	cout<<f<<endl;
	cout<<"\n Nhap thong tin moc thoi gian 1: "<<endl;
	cin>>g;
	cout<<"\n Thong tin moc thoi gian 1: ";
	cout<<g<<endl;
	cout<<"\n Nhap thong tin moc thoi gian 2: "<<endl;
	cin>>h;
	cout<<"\n Thong tin moc thoi gian 2: ";
	cout<<h<<endl;	
	file<<"\n Thong tin moc thoi gian 1: ";
	file<<g<<endl;
	file<<"\n Thong tin moc thoi gian 2: ";
	file<<h<<endl;
	if(g-h)
	{
		cout<<"\n So giay chenh lech: "<<g-h<<" giay "<<endl;
		file<<"\n So giay chenh lech: "<<g-h<<" giay "<<endl;
	}
	file.close();
	return 0;
}

