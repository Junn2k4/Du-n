#include <bits/stdc++.h>
using namespace std;
class TAMGIAC
{
	private:
		float a,b,c;
	public:
		friend istream& operator >>(istream& in,TAMGIAC &x);
		friend ostream& operator <<(ostream& out,TAMGIAC y);
		friend TAMGIAC operator + (TAMGIAC x,TAMGIAC y);
		friend TAMGIAC operator - (TAMGIAC x,TAMGIAC y);
		friend bool operator / (TAMGIAC x,TAMGIAC y);
};
istream& operator >>(istream& in,TAMGIAC &x)
{
	cout<<"\n Nhap canh a= ";		in>>x.a;
	cout<<"\n Nhap canh b= ";		in>>x.b;
	cout<<"\n Nhap canh c= ";		in>>x.c;
	return in;
}
ostream& operator <<(ostream& out,TAMGIAC y)
{
	out<<"Canh a= "<<y.a<<endl;
	out<<"Canh b= "<<y.b<<endl;
	out<<"Canh c= "<<y.c<<endl;
	return out;
}
TAMGIAC operator + (TAMGIAC x,TAMGIAC y)
{
	TAMGIAC c;
	c.a=x.a+y.a;
	c.b=x.b+y.b;
	c.c=x.c+y.c;
	return c;
}
TAMGIAC operator - (TAMGIAC x,TAMGIAC y)
{
	TAMGIAC c;
	c.a=x.a-y.a;
	c.b=x.b-y.b;
	c.c=x.c-y.c;
	return c;
}
bool operator / (TAMGIAC x,TAMGIAC y)
{
	if(x.a==y.a&&x.b==y.b&&x.c==y.c&&x.a>0&&x.b>0&&x.c>0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
int main()
{
	ofstream file ("Tamgiac01.txt",ios::out);
	TAMGIAC a;
	cout<<"\t\t\t\t NHAP THONG TIN CHO TAM GIAC a: \n";
	cin>>a;
	cout<<"\t\t\t\t CAC THONG TIN TAM GIAC a: \n ";
	cout<<a;
	file<<"CAC THONG TIN TAM GIAC a:"<<a<<endl;
	TAMGIAC b;
	cout<<"\t\t\t\t NHAP THONG TIN CHO TAM GIAC b: \n";
	cin>>b;
	cout<<"\t\t\t\t CAC THONG TIN TAM GIAC b: \n ";
	cout<<b;
	file<<"CAC THONG TIN TAM GIAC b:"<<b<<endl;
	TAMGIAC c=a+b;
	cout<<"\n TONG 2 TAM GIAC la: \n"<<c<<endl;
	file<<"Tong 2 tam giac: "<<c<<endl;
	TAMGIAC d=a-b;
	cout<<"\n HIEU 2 TAM GIAC la: \n"<<d<<endl;
	file<<"Hieu 2 tam giac: "<<d<<endl;
	if(a/b==true)
	{
		cout<<"Hai tam giac bang nhau "<<endl;
		file<<"Hai tam giac bang nhau "<<endl;
	}
	else
	{
		cout<<"Hai tam giac khong bang nhau"<<endl;
		file<<"Hai tam giac khong bang nhau"<<endl;
	}
	file.close();
	return 0;
}
