#include <bits/stdc++.h>
using namespace std;
class phieu;
class ncc
{
	private:
		char nc[20];
		char tenncc[20];
		char diachi[30];
		int sdt;
	public:
		void nhap();
		void xuat();
};
class hang
{
	private:
		char masp[30];
		char tensp[30];
		int slg,dgia;
	public:
		void nhap();
		void xuat();
	friend class phieu;	
	friend void dem(phieu &a);
	friend void sx(phieu &a);
};
class phieu
{
	private:
		char maphieu[30];
		int ngay;
		ncc x;
		int n;
		hang y[30];
	public:
		void nhap();
		void xuat();
	friend void dem(phieu &a);
	friend void sx(phieu &a);
};
void ncc::nhap()
{
	cout<<"\n nhap nha cung cap:";		fflush(stdin);		gets(nc);
	cout<<"\n nhap ten nha cung cap";	fflush(stdin);		gets(tenncc);
	cout<<"\n nhap dia chi:";			fflush(stdin);		gets(diachi);
	cout<<"\n nhap sdt:";				cin>>sdt;
}
void ncc::xuat()
{
	cout<<setw(15)<<"Ma nha cung cap:"<<nc<<setw(35)<<"Ten nha cung cap:"<<tenncc<<endl;
	cout<<setw(15)<<"Dia chi:"<<diachi<<setw(35)<<"SDT:"<<sdt<<endl;
}
void hang::nhap()
{
	cout<<"\n nhap ma san pham:";		fflush(stdin);		gets(masp);
	cout<<"\n nhap ten san pham:";		fflush(stdin);		gets(tensp);
	cout<<"\n nhap so luong:";			cin>>slg;
	cout<<"\n nhap don gia:";			cin>>dgia;
}
void hang::xuat()
{
	cout<<setw(15)<<masp<<setw(15)<<tensp<<setw(15)<<slg<<setw(15)<<dgia<<setw(15)<<slg*dgia<<endl;
}
void phieu::nhap()
{
	cout<<"\n nhap ma phieu:";			fflush(stdin);			gets(maphieu);
	cout<<"\n nhap ngay lap:";			cin>>ngay;
	x.nhap();
	cout<<"\n nhap so luong san pham:";			cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n san pham thu:"<<i+1<<endl;
			y[i].nhap();
	}
}
void phieu::xuat()
{
	cout<<setw(15)<<"Ma phieu:"<<maphieu<<setw(35)<<"Ngay lap:"<<ngay<<endl;
	x.xuat();
	cout<<setw(15)<<"Ma SP"<<setw(15)<<"Ten san pham"<<setw(15)<<"So luong"<<setw(15)<<"Don gia"<<setw(15)<<"Thanh tien"<<endl;
	for(int i=0;i<n;i++)
	{
		y[i].xuat();
	}
	float t=0,tt=0;
	for(int i=0;i<n;i++)
	{
		t=t+ y[i].slg*y[i].dgia;
		tt=tt+t;
	}
	cout<<setw(75)<<"Tong:"<<tt<<endl;
	
}
void dem(phieu &a)
{
	for(int i;i<a.n;i++)
	{
		if(a.y[i].slg<80)
			a.y[i].xuat();
	}
}
void sx(phieu &a)
{
	for (int i=0;i<a.n-1;i++)
	{
		for(int j=i+1;j<a.n;j++)
			if(a.y[i].dgia>a.y[j].dgia)
			{
				hang tmp=a.y[i];
				a.y[i]=a.y[j];
				a.y[j]=tmp;
			}
	}
}
main()
{
	phieu a;
	a.nhap();
	cout<<"Dai hoc Victory"<<endl;
	cout<<"\n===============PHIEU NHAP VAN PHONG PHAM=================="<<endl;
	a.xuat();
	cout<<"\t\t\t\t\tHieu Truong\t\t\t\t\t\t\t\tPhong tai chinh\t\t\t\t\t\t\t\t\Nguoi lap"<<endl;
	cout<<"\n Danh sach san pham nho hon 80:"<<endl;
	dem(a);
	cout<<"\n===============PHIEU NHAP VAN PHONG PHAM SAU KHI SUA=================="<<endl;
	sx(a);
	a.xuat();
	cout<<"\t\t\tHieu Truong\t\t\t\tPhong tai chinh\t\tt\t\t\Nguoi lap"<<endl;
	
	return 0;
}
