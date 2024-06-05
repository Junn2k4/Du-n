#include <iostream>
#include <iomanip> 
using namespace std;
class quanly
{
	private:
		char maql[20],hoten[30];
	public:
		void nhap();
		void xuat();
		
 } ;
class may
{
	private:
		char mamay[20],kieumay[20],tinhtrang[20];
	public:
		void nhap();
		void xuat();
	friend class phongmay; 
		 
 }; 
class phongmay
{
	private:
		char maphong[20];
		char tenphong[20];
		int dientich;
		quanly x;
		may *y;
		int n;
	public:
		void nhap();
		void xuat(); 
 } ;
void quanly::nhap()
{
	cout<<"\n nhap ma quan ly:";			fflush(stdin);		gets(maql);
	cout<<"\n nhap ho ten:";				fflush(stdin);		gets(hoten);
	 
 } 
void quanly::xuat() 
{
	cout<<setw(15)<<"\n Ma quan ly:"<<maql<<setw(15)<<"\n Ho ten:"<<hoten<<endl;
}
void may::nhap()
{
	cout<<"\n nhap Ma may:";				fflush(stdin);		gets(mamay);
	cout<<"\n nhap Kieu may:";				fflush(stdin);		gets(kieumay);
	cout<<"\n nhap Tinh trang:";				fflush(stdin);		gets(tinhtrang); 	
 } 
void may::xuat()
{
	cout<<setw(15)<<mamay<<setw(15)<<kieumay<<setw(15)<<tinhtrang<<endl; 
 } 
void phongmay::nhap()
{
	cout<<"\n nhap ma phong:";				fflush(stdin);		gets(maphong);
	cout<<"\n nhap ten phong:";				fflush(stdin);		gets(tenphong);
	cout<<"\n nhap dien tich:";				cin>>dientich;
	x.nhap();
	cout<<"\n nhap so luong may:";			cin>>n; 
	y=new may[30];
	for (int i=0;i<n;i++)
		{
			cout<<"\n May thu:"<<i+1<<endl; 
			y[i].nhap(); 
		 } 
 }
void phongmay::xuat()
{
	cout<<"\n Ma Phong:"<<maphong;
	cout<<"\n Ten Phong:"<<tenphong;
	cout<<"\n Dien Tich:"<<dientich<<endl;
	x.xuat();
	cout<<setw(20)<<"Ma May"<<setw(15)<<"Kieu May"<<setw(15)<<"Tinh Trang"<<endl; 
	for (int i=0;i<n;i++)
	{
		cout<<setw(5)<<i+1; 
		y[i].xuat(); 
		
	 } 
 }
main()
{
	phongmay a;
	a.nhap();
	cout<<"\n=================THONG TIN 1 PHONG MAY================="<<endl;
	a.xuat();
			return 0; 
 } 
