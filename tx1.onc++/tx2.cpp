#include<bits/stdc++.h>
using namespace std;

class DH
{
	private:
		char Ten[20];
		int Cs;
		float Dg;
	public:
		DH();
		DH(char *a,int b,float c);
		friend istream& operator>>(istream &in, DH &d);
		friend ostream& operator<<(ostream &out, DH d);	
		friend bool operator +(DH h,DH g);
};

DH::DH()
{
	strcpy(Ten,"LG");
	Cs=100;
	Dg=50;
}

DH::DH(char *a,int b,float c)
{
	strcpy(Ten,a);
	Cs=b;
	Dg=c;
}

istream& operator>>(istream &in, DH &d)
{
	cout<<"\n Nhap Ten: ";		fflush(stdin);		gets(d.Ten);
	cout<<"\n Nhap Cs: ";		in>>d.Cs;
	cout<<"\n Nhap Dg: ";		in>>d.Dg;	
	return in;
}

ostream& operator<<(ostream &out, DH d)
{
	out<<"\n Thong tin may: "<<endl;
	out<<d.Ten<<endl;
	out<<d.Cs<<endl;
	out<<d.Dg<<endl;	
	return out;	
}

bool operator +(DH h,DH g)
{
	if(strcmp(h.Ten,g.Ten)==0 && h.Cs==g.Cs && h.Dg==g.Dg )
		return true;
	return false;
}

int main()
{
	ofstream file ("Ketqua.txt");
	DH e("Toyota",500,100),f,k;
	cout<<e<<endl;
	cin>>f;
	cout<<f<<endl;
	cin>>k;
	cout<<k<<endl;
	file<<f<<endl;
	file<<k<<endl;
	if(e+k)
	{
		cout<<"2 thong tin cung nhau: ";
		file<<"2 thong tin cung nhau: ";
	}
	else 
	{
		cout<<"2 thong tin khong cung nhau: ";
		file<<"2 thong tin khong cung nhau: ";
	}
	file.close();
	return 0;
}	


