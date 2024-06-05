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
		friend ostream& operator<<(ostream&c,mang b);
		void operator++();
		void operator--();
		void hoanvi(int a,int b);
};
istream& operator >>(istream&a,mang &b)
{
	cout<<"\n nhap kich thuoc cua mang:";
	a>>b.n;
	for( int i=0;i<b.n;i++)
	{
		cout<<"\n phan tu a["<<i<<"] :";
		a>>b.value[i];
	}
	return a;

}
ostream& operator<< (ostream&c,mang b)
{
	for(int i=0;i<b.n;i++)
	c<<"\t"<<b.value[i];
	return c;
}
void mang::hoanvi(int  a,int b)
{
	float  tmp=value[a];
	value[a]=value[b];
	value[b]=tmp;
}
void mang::operator++()
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
void mang::operator--()
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
	ofstream file("DUAN.txt");
	mang a;
	cout<<"\n nhap mang:"<<endl;
	cin>>a;
	file<<"Mang sap xep tang dan la:";
	++a;
	file<<a<<endl; 
	file<<"Mang sap xep giam dan la:";
	--a;
	file<<a<<endl; 
	file.close();
	cout<<"\n KET QUA DC IN TRONG DUAN.txt"<<endl;
	return 0;
}
