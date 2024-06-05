#include <bits/stdc++.h>
using namespace std;
class phieu;
class sinhvien
{
	private:
		char masv[30];
		char tensv[30];
		char lop[10];
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
		sinhvien x;
		mon *y;
		int n;
	public:
		void nhap();
		void xuat();	
	friend void diem(phieu &a);
	friend void chen(phieu &a);
};
void sinhvien::nhap()
{
	cout<<"\n nhap ma sinh vien:";			fflush(stdin);		gets(masv);
	cout<<"\n nhap ten sinh vien:";			fflush(stdin);		gets(tensv);
	cout<<"\n nhap lop:";					fflush(stdin);		gets(lop);
	cout<<"\n nhap khoa:";					cin>>khoa;
	
}
void sinhvien::xuat()
{
	cout<<setw(15)<<"Ma sinh vien:"<<masv<<setw(20)<<"Ten sinh vien:"<<tensv<<endl;
	cout<<setw(15)<<"Lop:"<<lop<<setw(20)<<"Khoa:"<<khoa<<endl;
}
void mon::nhap()
{
	cout<<"\n nhap ten mon:";			fflush(stdin);		gets(tenmon);
	cout<<"\n nhap so trinh:";			cin>>sotrinh;
	cout<<"\n nhap diem:";				cin>>diem;
}
void mon::xuat()
{
	cout<<setw(20)<<tenmon<<setw(20)<<sotrinh<<setw(20)<<diem<<endl;
}
void phieu::nhap()
{
	x.nhap();
	cout<<"\n nhap so luong mon hoc:";	cin>>n;
	y=new mon[30];
	for(int i=0;i<n;i++)
		{
			y[i].nhap();
		}

}
void phieu::xuat()
{
	x.xuat();
	cout<<"\n Bang diem:"<<endl;
	cout<<setw(20)<<"Ten mon"<<setw(20)<<"So trinh"<<setw(20)<<"Diem"<<endl;
	for(int i=0;i<n;i++)
		{
			y[i].xuat();
		}
	float tong=0;
	for (int i=0;i<n;i++)
		{
			tong=tong+y[i].diem;
		}
	cout<<"\n Diem trung binh:"<<tong<<endl;
}

void diem(phieu &a)
{
	bool dem = false;
	for (int i = 0; i < a.n; i++)
	{
		if (a.y[i].sotrinh > 3)
		 {
		 	dem = true;
			a.y[i].xuat();
		cout << "\n Mon hoc co so trinh lon hon 3 la:" << endl;
		}
	}
	if (!dem)
	{
		cout << "\n Khong co mon co so trinh lon hon 3!" << endl;
	}
}

void chen(phieu &a)
{
	int k;
	do
	{
		cout<<"\n Nhap vi tri chen:";		cin>>k;
		
	}
	while(k<0||k>a.n);
	mon n1;
	cout<<"\n NHap mon moi:"<<endl;
	n1.nhap();
	for (int i=0;i<a.n;i++)
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
	cout<<"\n =====================PHIEU BAO DIEM=========================="<<endl;
	a.xuat();
//	cout<<"\n Mon hoc co so trinh lon hon 3:"<<endl;
	diem(a);
	chen(a);
	cout<<"\n ====================PHIEU DAO DIEM SAU KHI SUA==================="<<endl;
	a.xuat();
			return 0;
 } 
