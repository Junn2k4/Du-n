#include<iostream>
#include<fstream>
using namespace std;

class mang
{
	private:
		float *value;
		int n;
	public:
		friend istream& operator>>(istream &a, mang&b);
		friend ostream& operator<<(ostream&c,mang b);
		void operator++();
		void operator--();
		void hoanvi(float *a, float *b);
};

istream& operator>>(istream &a, mang&b)
{
	cout<<"\nNhap kich thuoc mang: ";		a>>b.n;
	b.value=new float[b.n];
	
	for(int i=0;i<b.n;i++)
	{
		cout<<"\nNhap phan tu a ["<<i<<"]= ";
		a>>b.value[i];
	}
	return a;
}

ostream& operator<<(ostream&c,mang b)
{
	for(int i=0;i<b.n;i++)
		c<<"\t"<<b.value[i];
	return c;
}

void mang::hoanvi(float *a, float *b)
{
	float tg=*a;
	*a=*b;
	*b=tg;
}
	
void mang::operator++()
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(value[i] > value[j])
				hoanvi(&value[i],&value[j]);
}

void mang::operator--()
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(value[i] < value[j])
				hoanvi(&value[i],&value[j]);
}
	
main()
{
	mang a;
	fstream b("MANG.txt",ios::out);
	cin>>a;
	cout<<"\nMang vua nhap la: "<<endl;
	cout<<a;
	
	cout<<"\nMang sap xep tang dan la: "; ++a;
	cout<<a;
	b<<"\nMang sap xep tang dan la: "<<a<<endl;
	
	cout<<"\nMang sap xep giam dan la: "; --a;
	cout<<a;
	b<<"\nMang sap xep giam dan la: "<<a;

}
