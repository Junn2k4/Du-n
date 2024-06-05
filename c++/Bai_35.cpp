#include<iostream>
using namespace std;

class array
{
	private:
		int *value;
		int n;
	public:
		array()
		{
			n=0;
		}
		
		array(int m)
		{
			n=m;
			value= new int[n];
			for(int i=0;i<n;i++)
				*(value+i)=0;
		}
		
		void huy()
		{
			n=0;
			delete value;
		}	
		void nhap();
		void xuat();	
};


void array::nhap()
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nNhap phan tu a["<<i<<"]: ";
		cin>>*(value+i);	
	}	
}

void array::xuat()
{
	for(int i=0;i<n;i++)
		cout<<*(value + i)<<"\t";
}


main()
{
	array a(4);
	a.nhap();
	a.xuat();
}




