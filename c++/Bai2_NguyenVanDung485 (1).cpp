#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

class diem
{
	private:
		float x,y,z;
	public:
		diem()
		{
			x=y=z=0;
		}
		diem(float a, float b, float c)
		{
			x=a;
			y=b;
			z=c;
		}
		float operator+(diem a);
		int operator%(diem b);
		friend istream& operator>>(istream& m, diem &n);
		friend ostream& operator<<(ostream& p, diem q);
};

istream& operator>>(istream& m, diem &n)
{
	cout<<"\nNhap x: ";			m>>n.x;
	cout<<"\nNhap y: ";			m>>n.y;
	cout<<"\nNhap z: ";			m>>n.z;	
	return m;	
}

ostream& operator<<(ostream& p, diem q)
{
	p<<"("<<q.x<<" ; "<<q.y<<" ; "<<q.z<<")";
	return p;
}

int diem::operator%(diem b)
{
	if(x==b.x && y==b.y && z==b.z)
		return 1;
	return 0;
}
float diem::operator+(diem a)
{
	float d;
	d=sqrt(pow(x + a.x,2) + pow(y + a.y,2) + pow(z + a.z,2) );
	return d;
}

main()
{
	diem A,B;
	fstream b("DUNG.txt",ios::out);
	
	cout<<"\nNhap diem A: ";
	cin>>A;
	cout<<"A"<<A;
	b<<"A"<<A;
		
	cout<<"\nNhap diem B: ";
	cin>>B;
	cout<<"B"<<B;
	b<<"B"<<B;
	
	int T=A%B;
	if(T==1)
	{
		cout<<"\nHai diem trung nhau";
		b<<"\nHai diem trung nhau";
	}
	else
	{
		cout<<"\nHai diem khac nhau";
		b<<"\nHai diem khac nhau";
	}
		
	cout<<"\nKhoang cach hai diem vua nhap la: "<<A + B;

}
