#include<bits/stdc++.h>
using namespace std;
class TAMGIAC
{
	private:
		int C1,C2,C3;
	public:
		TAMGIAC();
		TAMGIAC(int a,int b,int c);
		friend istream& operator>>(istream &in,TAMGIAC &d);
		friend ostream& operator<<(ostream &out,TAMGIAC d);	
		friend TAMGIAC operator +(TAMGIAC P,TAMGIAC Q);
		friend TAMGIAC operator -(TAMGIAC P,TAMGIAC Q);	
		friend bool operator *(TAMGIAC P,TAMGIAC Q);
};

TAMGIAC::TAMGIAC()
{
	C1=C2=C3=4;
}

TAMGIAC::TAMGIAC(int a,int b,int c)
{
	C1=a;
	C2=b;
	C3=c;
}

istream& operator>>(istream &in,TAMGIAC &d)
{
	cout<<"\n Nhap C1: ";		in>>d.C1;
	cout<<"\n Nhap C2: ";		in>>d.C2;
	cout<<"\n Nhap C3: ";		in>>d.C3;	
	return in;
}

ostream& operator<<(ostream &out,TAMGIAC d)
{
	out<<"C1:"<<d.C1<<endl;
	out<<"C2:"<<d.C2<<endl;	
	out<<"C3:"<<d.C3<<endl;	
	return out;
}

TAMGIAC operator +(TAMGIAC P,TAMGIAC Q)
{
	TAMGIAC M;
	M.C1=P.C1+Q.C1;
	M.C2=P.C2+Q.C2;
	M.C3=P.C3+Q.C3;
	return M;
}

TAMGIAC operator -(TAMGIAC P,TAMGIAC Q)
{
	TAMGIAC M;
	M.C1=P.C1-Q.C1;
	M.C2=P.C2-Q.C2;
	M.C3=P.C3-Q.C3;
	return M;
}

bool operator *(TAMGIAC P,TAMGIAC Q)
{
	if(P.C1==Q.C1 && P.C2==Q.C2 && P.C3==Q.C3 && (P.C1,P.C2,P.C3)>0)
		return true;
	return false;	
}
int main()
{
	ofstream file("TAMGIAC01.txt",ios::out);
	TAMGIAC M,P,Q;
	cout<<M<<endl;
	cout<<"\n Nhap thong tin tam giac P "<<endl;
	cin>>P;
	cout<<P<<endl;
	cout<<"\n Nhap thong tin tam giac Q "<<endl;
	cin>>Q;
	cout<<Q<<endl;	
	cout<<"\n Tong hai tam giac: "<<P+Q<<endl;
	cout<<"\n Hieu hai tam giac: "<<P-Q<<endl;
	file<<"\n Nhap thong tin tam giac P "<<endl;
	file<<P<<endl;
	file<<"\n Nhap thong tin tam giac Q "<<endl;
	file<<Q<<endl;	
	file<<"\n Tong hai tam giac: "<<P+Q<<endl;
	file<<"\n Hieu hai tam giac: "<<P-Q<<endl;
	if(P*Q)
	{
		cout<<"2 tam giac bang nhau:";
		file<<"2 tam giac bang nhau: ";
	}
	else
	{
		cout<<"2 tam giac khong bang nhau:";
		file<<"2 tam giac khong bang nhau: ";	
	}
	return 0;
}

