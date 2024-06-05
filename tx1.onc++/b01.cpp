#include <bits/stdc++.h>
using namespace std;
class phieu;
class sv
{
	private:
		char masv[20];
		char tensv[30];
		char lop[30];
		int khoa;
	public:
		void nhap();
		void xuat();		
};
class mon
{
	private:
		char tenmon[30];
		int sotrinh,diem;
	public:
		void nhap();
		void xuat();
	friend class phieu;
	friend void diem(phieu &a);	
	friend void chen(phieu &a);
};
class phieu
{
	private:
		sv x;
		mon y[30];
		int n;
	public:
		void nhap();
		void xuat();
	friend void diem(phieu &a);
	friend void chen(phieu &a);
};
void sv::nhap()
{
	cout<<"\n nhap ma sinh vien:";				fflush(stdin);		gets(masv);
	cout<<"\n nhap ten sinh vien:";				fflush(stdin);		gets(tensv);
	cout<<"\n nhap lop:";						fflush(stdin);		gets(lop);
	cout<<"\n nhap khoa:";						cin>>khoa;

}
void sv::xuat()
{
	cout<<setw(15)<<"Ma sinh vien:"<<setw(15)<<"Ten sinh vien:"<<tensv<<endl;
	cout<<setw(15)<<"Lop:"<<lop<<setw(15)<<"Khoa:"<<khoa<<endl;
}
void mon::nhap()
{
	cout<<"\n nhap ten mon:";					fflush(stdin);		gets(tenmon);
	cout<<"\n nhap so trinh:";					cin>>sotrinh;
	cout<<"\n nhap diem:";						cin>>diem;


}
void mon::xuat()
{
	cout<<setw(20)<<tenmon<<setw(20)<<sotrinh<<setw(20)<<diem<<endl;
}
void phieu::nhap()
{
	x.nhap();
	cout<<"\n nhap so luong mon:";		cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n Mon thu:"<<i+1<<endl;
			y[i].nhap();
	}
}
void phieu::xuat()
{
	x.xuat();
	cout<<setw(15)<<"Bang Diem:"<<endl;
	cout<<setw(20)<<"tenmon"<<setw(20)<<"sotrinh"<<setw(20)<<"diem"<<endl;
	for(int i=0;i<n;i++)
	{
		y[i].xuat();
	}
	float t=0,tt=0,tb=0;
	for(int i=0;i<n;i++)
	{
	
		tt=t+y[i].sotrinh;
		tb=tb+y[i].sotrinh*y[i].diem;
		t=tb/tt;
	}
	cout<<setw(25)<<"Diem trung binh:"<<t<<endl;
}
void diem(phieu &a)
{
	bool dem=false;
	for (int i=0;i<a.n;i++)
		{
			if(a.y[i].sotrinh>3)
			{
				if(!dem)
				{
					cout<<"\n Mon co so trinh lon hon 3 la:"<<endl;
					dem=true;
				}
			a.y[i].xuat();	
			}
		}
	if(!dem)
	{
		cout<<"\n khong co mon nao co so trinh hon 3!"<<endl;
	}
}
void chen(phieu &a)
{
	int k;
	do
	{
		cout<<"\n nhap vi tri chen:";
		cin>>k;
	}
	while(k<0 ||k>a.n);
	mon n1;
	n1.nhap();
	for(int i=a.n;i>k;i--)
	{
		a.y[i]=a.y[i-1];
	}
	a.y[k]=n1;
	a.n++;
}
main()
{
	phieu a;
	a.nhap();
	cout<<"\n=========PHIEU BAO DIEM============="<<endl;
	a.xuat();
	cout<<"\n=========MON CO SO TRINh >3=========="<<endl;
	diem(a);
	cout<<"\n=========PHIEU SAU KHI CHEN=========="<<endl;
	chen(a);
		return 0;
}
