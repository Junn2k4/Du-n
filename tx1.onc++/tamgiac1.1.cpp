#include <iostream>
#include <fstream> 
using namespace std;
class tamgiac
{
	private:
		int a,b,c;
	public:
		tamgiac();
		tamgiac(int m,int n, int p);
		friend istream & operator>>(istream &a,tamgiac &b);
		friend ostream & operator<<(ostream &a,tamgiac b);
		tamgiac operator +(tamgiac d);
		tamgiac operator -(tamgiac d);	
		bool operator /(tamgiac d);
		
};
tamgiac::tamgiac()
{
	a=b=c=1;
}
tamgiac::tamgiac(int m,int n, int p)
{
	a=m;
	b=n;
	c=p;
}
istream & operator>>(istream &a,tamgiac &b)
{
	cout<<"\n Nhap canh a:";		a>>b.a;
	cout<<"\n Nhap canh b:";		a>>b.b;
	cout<<"\n Nhap canh c:";		a>>b.c;
	return a;
}
ostream & operator<<(ostream &a,tamgiac b)
{
	a<<"\n Canh a:"<<b.a<<endl;
	a<<"\n Canh b:"<<b.b<<endl;
	a<<"\n Canh c:"<<b.c<<endl;
	return a;
}
tamgiac tamgiac:: operator +(tamgiac d)
{
	tamgiac kq;
	kq.a=a+d.a;
	kq.b=b+d.b;
	kq.c=c+d.c;
	return kq;
}
tamgiac tamgiac ::operator -(tamgiac d)
{
	tamgiac kq;
	kq.a=a-d.a;
	kq.b=b-d.b;
	kq.c=c-d.c;
	return kq;
}
bool tamgiac::operator /(tamgiac d)
{
	if(a==d.a && b==d.b && c==d.c && a>0 && b>0 && c>0)
		return true;
	return false; 
}
main()
{
	ofstream file("duan1.txt",ios::out); 
	tamgiac b(2,4,5),a,c;
	cout<<"\n THONG TIN TAM GIAC B:"<<endl;
	cout<<b<<endl;
	cout<<"\n nhap tam giac a:"<<endl;
	cin>>a;
	cout<<"\n nhap tam giac c:"<<endl;
	cin>>c;
	cout<<"\n THONG TIN TAM GIAC A"<<endl;
	cout<<a<<endl;
	cout<<"\n THONG TIN TAM GIAC C"<<endl;
	cout<<c<<endl;
	cout<<"\n CONG 2 TAM GIAC B va A:"<<endl;
	cout<<b+a<<endl;
	cout<<"\n TRU 2 TAM GIAC B va C:"<<endl;
	cout<<b-c<<endl;
	cout<<"\n-----------------------------------------------------"<<endl;
	file<<"\n THONG TIN TAM GIAC A"<<endl;
	file<<a<<endl;
	file<<"\n THONG TIN TAM GIAC C"<<endl;
	file<<c<<endl;
	file<<"\n CONG 2 TAM GIAC B va A:"<<endl;
	file<<b+a<<endl;
	file<<"\n TRU 2 TAM GIAC B va C:"<<endl;
	file<<b-c<<endl;
	if(a/c)
	{
		cout<<"2 tam giac canh bang nhau va deu  duong"<<endl; 
		file<<"2 tam giac canh bang nhau va deu  duong"<<endl; 
	 } 
	 else
	 {
	 	cout<<"2 tam giac khong co canh bang nhau va deu khong duong"<<endl; 
	 	file<<"2 tam giac khong co canh bang nhau va deu khong duong"<<endl; 
	  } 
	cout<<"\n THONG TIN VA KET QUA DC IN TRONG duan1.txt"<<endl;
	return 0;
	
}
