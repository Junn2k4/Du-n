#include<bits/stdc++.h>
using namespace std;
class HH
{
	private:
		int CD,CR,CC;
	public:
		HH();
		HH(int a,int b,int c);
		friend istream& operator>>(istream &in,HH &d);
		friend ostream& operator<<(ostream &out,HH d);
		friend bool operator *(HH P,HH Q);	
		friend HH operator +(HH P,HH Q);
		friend HH operator -(HH P,HH Q);	
};

HH::HH()
{
	CD=CR=CC=1;
}

HH::HH(int a,int b,int c)
{
	CD=a;
	CR=b;
	CC=c;
}

istream& operator>>(istream &in,HH &d)
{
	cout<<"\n Nhap CD: ";		in>>d.CD;
	cout<<"\n Nhap CR: ";		in>>d.CR;
	cout<<"\n Nhap CC: ";		in>>d.CC;	
	return in;
}

ostream& operator<<(ostream &out,HH d)
{
	out<<"CD:"<<d.CD<<endl;
	out<<"CR:"<<d.CR<<endl;	
	out<<"CC:"<<d.CC<<endl;	
	return out;
}

bool operator *(HH P,HH Q)
{
	if(P.CD==Q.CD && P.CR==Q.CR && P.CC>0)
		return true;
	return false;	
}

HH operator +(HH P,HH Q)
{
	HH M;
	M.CD=P.CD+Q.CD;
	M.CR=P.CR+Q.CR;
	M.CC=P.CC+Q.CC;
	return M;
}

HH operator -(HH P,HH Q)
{
	HH M;
	M.CD=P.CD-Q.CD;
	M.CR=P.CR-Q.CR;
	M.CC=P.CC-Q.CC;
	return M;
}
int main()
{
	ofstream file("HH03.txt",ios::out);
	HH M,P,Q;
	cout<<M<<endl;
	cout<<"\n Nhap thong tin HH1 "<<endl;
	cin>>P;
	cout<<P<<endl;
	cout<<"\n Nhap thong tin HH2 "<<endl;
	cin>>Q;
	cout<<Q<<endl;	
	if(P*Q)
	{
		cout<<"2 HH bang nhau:";
		file<<"2 HH bang nhau: ";
	}
	else
	{
		cout<<"2 HH khong bang nhau:";
		file<<"2 HH khong bang nhau: ";	
	}
	cout<<"\n Tong hai HH: "<<P+Q<<endl;
	cout<<"\n Hieu hai HH: "<<P-Q<<endl;
	file<<"\n Nhap thong tin HH1 "<<endl;
	file<<P<<endl;
	file<<"\n Nhap thong tin HH2"<<endl;
	file<<Q<<endl;	
	file<<"\n Tong hai HH "<<P+Q<<endl;
	file<<"\n Hieu hai HH "<<P-Q<<endl;
	
	return 0;
}

