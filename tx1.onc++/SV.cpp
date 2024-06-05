#include<bits/stdc++.h>
using namespace std;

class SV
{
	private:
		char Hoten[20];
		int MSV;
		float Diemthi;
	public:
		SV();
		SV(char *a,int b,float c);
		friend istream& operator>>(istream &in,SV &d);
		friend ostream& operator<<(ostream &out,SV d);	
		friend bool operator +(SV m,SV n);
		friend bool operator *(SV p,SV k);
};

SV::SV()
{
	strcpy(Hoten,"Tran Van A");
	MSV=2022112233;
	Diemthi=9;
}

SV::SV(char *a,int b,float c)
{
	strcpy(Hoten,a);
	MSV=b;
	Diemthi=c;
}

istream& operator>>(istream &in,SV &d)
{
	cout<<"\n Nhap Ho ten: ";		fflush(stdin);		gets(d.Hoten);
	cout<<"\n Nhap MSV: ";			in>>d.MSV;
	cout<<"\n Nhap Diem thi: ";		in>>d.Diemthi;
	return in;
}

ostream& operator<<(ostream &out,SV d)
{
	out<<"\n Ho ten: "<<d.Hoten;
	out<<"\n MSV: "<<d.MSV;
	out<<"\n Diem thi:"<<d.Diemthi;
	return out;
}

bool operator +(SV m,SV n)
{
	if(strcmp(m.Hoten,n.Hoten)==0 && m.Diemthi==n.Diemthi)
		return true;
	return false;
}

bool operator *(SV p,SV k)
{
	if(strcmp(p.Hoten,"Nguyen Lan Anh")==0 || strcmp(k.Hoten,"Nguyen Lan Anh")==0 )
		return true;
	return false;
}
int main()
{
	ofstream file("SV.txt",ios::out);
	SV e,f("Nguyen Van B",20222233,8.5),g,h;
	cout<<e<<endl;
	cout<<f<<endl;
	cin>>g;
	cout<<g<<endl;
	cin>>h;
	cout<<h<<endl;
	file<<g<<endl;
	file<<h<<endl;
	if(g+h)
	{
		cout<<"\n Thoa man dieu kien 1"<<endl;
		file<<"\n Thoa man dieu kien 1"<<endl;
	}
	else
	{
		cout<<"\n Khong thoa man dieu kien 1"<<endl;
		file<<"\n Khong thoa man dieu kien 1"<<endl;
	}
	if(g*h)
	{
		cout<<"\n Thoa man dieu kien 2"<<endl;
		file<<"\n Thoa man dieu kien 2"<<endl;
	}
	else
	{
		cout<<"\n Khong thoa man dieu kien 2"<<endl;
		file<<"\n Khong thoa man dieu kien 2"<<endl;
	}
	file.close();
	return 0;
}

