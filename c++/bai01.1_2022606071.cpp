#include <iostream>
#include <iomanip>
using namespace std;
class ncc
{

	private:
		char mancc[20];
		char tenncc[30];
		char diachi[30];
	public:
		void nhap();
		void xuat();
	};
class hang
{

	private:
		char tenhang[30];
		float dongia;
		int slg;
	public:
		void nhap();
		void xuat();
	friend class phieu;
	};
class phieu
{
	private:
		char maphieu[20];
		int ngay;
		ncc x;
		int n;
		hang y[30];
	public:
		void nhap();
		void xuat();
};
void ncc::nhap()
{
	cout<<"\n nhap ma nha cung cap:";		fflush(stdin);		gets(mancc);
	cout<<"\n nhap ten nha cung cap:";		fflush(stdin);		gets(tenncc);
	cout<<"\n nhap dia chi nha cung cap:";	fflush(stdin);		gets(diachi);
	
}
void ncc::xuat()
{
	cout<<setw(15)<<"Ma NCC:"<<mancc<<setw(20)<<"Ten NCC:"<<tenncc<<endl;
	cout<<setw(15)<<"Dia chi:"<<diachi<<endl;
	
}
void hang::nhap()
{
	cout<<"\n nhap ten hang:";				fflush(stdin);		gets(tenhang);
	cout<<"\n nhap don gia:";				cin>>dongia;
	cout<<"\n nhap so luong:";				cin>>slg;
	
}
void hang::xuat()
{
	cout<<setw(15)<<tenhang<<setw(15)<<dongia<<setw(15)<<slg<<setw(15)<<dongia*slg<<endl;
}
void phieu::nhap()
{
	cout<<"\n nhap ma phieu:";				fflush(stdin);		gets(maphieu);
	cout<<"\n nhap ngay lap:";				cin>>ngay;
	x.nhap();
	cout<<"\n nhap so luong hang:";			cin>>n;
	for(int i=0;i<n;i++)
		{
			y[i].nhap();
		}

}
void phieu::xuat()
{
	cout<<setw(15)<<"Ma phieu:"<<maphieu<<setw(20)<<"Ngay lap:"<<ngay<<endl;
	x.xuat();
	cout<<setw(15)<<"Ten hang"<<setw(15)<<"Don gia"<<setw(15)<<"So luong"<<setw(15)<<"Thanh tien"<<endl;	
	for( int i=0;i<n;i++)
	{
		y[i].xuat();
	}
	float tong=0;
	for(int i=0;i<n;i++)
		{
			tong=tong +y[i].dongia*y[i].slg;
		}
	cout<<setw(50)<<"Cong thanh tien:"<<tong<<endl;
}
main()
{
	phieu a;
	a.nhap();
	cout<<"\n==================PHIEU NHAP HANG===================="<<endl;
	a.xuat();
		return 0;
}
