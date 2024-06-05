#include <iostream>
#include <fstream>
using namespace std;
class mang
{
	private:
		float value[30];
		int n;
	public:
		friend istream& operator>>(istream&a,mang &b);
		friend ostream& operator<<(ostream&a,mang b);
		mang operator ++();
		mang operator --();
		void hoanvi(int a, int b);
 } ;
istream& operator>>(istream&a,mang &b)
{
	cout<<"\n nhap mang la:";
	a>>b.n;
	for( int i=0;i<b.n;i++)
	{
		cout<<"\n nhap phan tu a["<<i<<"]:";
		a>>b.value[i];
	}
	return a;
}
ostream& operator<<(ostream&a,mang b)
{
	for(int i=0;i<b.n;i++)
		a<<"\t"<<b.value[i];
	return a;
}
void mang::hoanvi(int a, int b)
{
	float tmp=value[a];
	value[a]=value[b];
	value[b]=tmp;
}
mang mang::operator ++()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(value[i]>value[j])
				hoanvi(i,j);
		}
	}
}
mang mang::operator --()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(value[i]<value[j])
				hoanvi(i,j);
		}
	}
}
main()
{
	ofstream file("MANG.txt",ios::out);
	mang a;
	cin>>a;
	cout<<a;
	cout<<"\n mang sap xep tang dan:";
	++a;
	cout<<a<<endl;
	cout<<"\n mang sap xep giam dan:";
	--a;
	cout<<a<<endl;
	file<<"\n mang la:";
	file<<a;
	file<<"\n mang sap xep tang dan:";
	file<<++a;
	file<<a<<endl;
	file<<"\n mang sap xep giam dan:";
	file<<--a;
		file<<a<<endl;
	return 0;
	
}
