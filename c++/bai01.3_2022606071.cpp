#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class phieu;
class nv
{
	private:
		char nvien[30];
		char chucvu[30];
	public:
		void nhap();
		void xuat();
};
class phong
{
	private:
		char phongg[30];
		char maphong[30];
		char truongphong[30];
	public:
		void nhap();
		void xuat();
};
class taisan
{
	private:
		char taisann[30];
		int slg;
		char tinhtrang[30];
	public:
		void nhap();
		void xuat();
	friend class phieu;
	friend void sx(phieu &a);
	friend void sua(phieu &a);
};
class phieu
{
	private:
		char maphieu[30];
		int ngay;
		nv x;
		phong y;
		taisan z[30];
		int n;
	public:
		void nhap();
		void xuat();
	friend void sx(phieu &a);
	friend void sua(phieu &a);
};
void nv::nhap()
{
	cout<<"\n nhap nhan vien kiem ke:";				fflush(stdin);			gets(nvien);
	cout<<"\n nhap chuc vu:";						fflush(stdin);			gets(chucvu);
}
void nv::xuat()
{
	cout<<setw(15)<<"Nhan vien kiem ke:"<<nvien<<setw(30)<<"Chuc vu:"<<chucvu<<endl;
}
void phong::nhap()
{
	cout<<"\n Kiem ke tai phong:";					fflush(stdin);			gets(phongg);
	cout<<"\n Ma phong:";							fflush(stdin);			gets(maphong);
	cout<<"\n Truong phong:";						fflush(stdin);			gets(truongphong);
}
void phong::xuat()
{
	cout<<setw(15)<<"Kiem ke tai phong:"<<phongg<<setw(30)<<"Ma phong:"<<maphong<<endl;
	cout<<setw(15)<<"Truong phong:"<<truongphong<<endl;
}
void taisan::nhap()
{
	cout<<"\n nhap ten tai san:";					fflush(stdin);			gets(taisann);
	cout<<"\n nhap so luong";						cin>>slg;
	cout<<"\n nhap tinh trang:";					fflush(stdin);			gets(tinhtrang);
	
}
void taisan::xuat()
{
	cout<<setw(15)<<taisann<<setw(30)<<slg<<setw(30)<<tinhtrang<<endl;
}
void phieu::nhap()
{
	cout<<"\n nhap ma phieu:";						fflush(stdin);			gets(maphieu);
	cout<<"\n nhap ngay kiem ke:";					cin>>ngay;
	x.nhap();
	y.nhap();
	cout<<"\n nhap so luong tai san:";				cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<"\n Tai san thu:"<<i+1<<endl;
		z[i].nhap();
	}
}
void phieu::xuat()
{
	cout<<setw(15)<<"Ma phieu:"<<maphieu<<setw(50)<<"Ngay kiem ke:"<<ngay<<endl;
	x.xuat();
	y.xuat();
	cout<<setw(15)<<"Tai san"<<setw(30)<<"So luong"<<setw(30)<<"Tinh trang"<<endl;
	for (int i=0;i<n;i++)
	{
		z[i].xuat();
	}
	float tong=0;
	for(int i=0;i<n;i++)
	{
		tong=tong+z[i].slg;
	}
	cout<<"\n";
	cout<<setw(15)<<"So tai san kiem ke:"<<n<<setw(15)<<"Tong so luong:"<<tong<<endl;
}
void sx(phieu &a)
{
	for(int i=0;i<a.n-1;i++)
	{
		for(int j=i+1;j<a.n;j++)
		{
			if(a.z[i].slg>a.z[j].slg)
			{
				taisan tg =a.z[i];
				a.z[i]=a.z[j];
				a.z[j]=tg;
			}
		}
	}
}
void sua(phieu &a)
{
	for (int i=0;i<a.n;i++)
	{
		if(strcmp(a.z[i].taisann,"May vi tinh")==0)
		a.z[i].slg=20;
	}
}
main()
{
	phieu a;
	a.nhap();
	cout<<"\n===============PHIEU KIEM KE TAI SAN====================="<<endl;
	a.xuat();
	cout<<"\n-----------------------------------------"<<endl;
	sua(a);
	a.xuat();
	cout<<"\n-----------------------------------------------"<<endl;
	cout<<"\n===============PHIEU SAU KHI SUA========================="<<endl;
	sx(a);
	a.xuat();
		return 0;
}
