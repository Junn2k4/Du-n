#include <iostream>
#include <fstream>
using namespace std;
class tg
{
	private:
		int a,b,c;
	public:
		tg();
		tg(int m,int n, int p);
		friend istream &operator >>(istream &a,tg &b);
		friend ostream &operator <<(ostream &a,tg b);
		tg operator +(tg d);
		tg operator -(tg d);
		bool operator /(tg d);
			
};
tg::tg()
{
	a=5;
	b=3;
	c=6;
}
tg::tg(int m,int n,int p)
{
	a=m;
	b=n;
	c=p;
}
istream &operator >>(istream &a,tg &b)
{
	cout<<"\n nhap canh a:";		a>>b.a;
	cout<<"\n nhap canh b:";		a>>b.b;
	cout<<"\n nhap canh c:";		a>>b.c;
	return a;
}
ostream &operator <<(ostream &a,tg b)
{
	a<<"\n Canh a:"<<b.a<<endl;
	a<<"\n Canh b:"<<b.b<<endl;
	a<<"\n Canh c:"<<b.c<<endl;
	return a;
}
tg tg::operator +(tg d)
{
	tg kq;
	kq.a=a+d.a;
	kq.b=b+d.b;
	kq.c=c+d.c;
	return kq;
}
tg tg::operator -(tg d)
{
	tg kq;
	kq.a=a-d.a;
	kq.b=b-d.b;
	kq.c=c-d.c;
	return kq;
}
bool tg::operator /(tg d)
{
	if(a==d.a &&b==d.b && c==d.c && (a,b,c)>0)
		return true;
	return false;
}
main()
{
	ofstream f("t.txt",ios::out);
	tg a,b(5,7,8),c,d;
	cout<<"\n Thong tin tam giac a:"<<endl;
	cout<<a<<endl;
	cout<<"\n Thong tin tam giac b:"<<endl;
	cout<<b<<endl;
	cout<<"\n Thong tin tam giac c:"<<endl;
	cin>>c;
	cout<<c<<endl;
	cout<<"\n Thong tin tam giac d:"<<endl;
	cin>>d;
	cout<<d<<endl;
	cout<<"\n Cong tam a va c:"<<a+c<<endl;
	cout<<"\n Tru tam d va c:"<<d+c<<endl;
	cout<<"\n------------------------"<<endl;
	f<<"\n Thong tin tam giac a:"<<endl;
	f<<a<<endl;
	f<<"\n Thong tin tam giac b:"<<endl;
	f<<b<<endl;
	f<<"\n Thong tin tam giac c:"<<endl;
	f<<c<<endl;
	f<<"\n Thong tin tam giac d:"<<endl;
	f<<d<<endl;
	f<<"\n Cong tam a va c:"<<a+c<<endl;
	f<<"\n Tru tam d va c:"<<d+c<<endl;
	if (b / c) 
	{
        cout << "2 Hinh TAM GIAC bang nhau" << endl;
        f << "2 Hinh TAM GIAC bang nhau!" << endl;
    }
	 else
	  {
        cout << "2 Hinh TAM GIAC khong bang nhau!" << endl;
        f << "2 Hinh TAM GIAC khong bang nhau" << endl;
    }
    cout << "\n KET QUA IN VAO asc.txt" << endl;
	return 0;
	
}
