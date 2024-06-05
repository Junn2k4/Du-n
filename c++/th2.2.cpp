#include <bits/stdc++.h>
using namespace std;
class hang
{
	private:
		char mahang[20];
		char tenhang[30];
		int dongia;
	public:
		void nhap();
		void xuat();
	
 } ;
class phieu
{
	private:
		char maphieu[20];
		hang x[20];
		int n;
	public:
		void nhap();
		void xuat(); 
 }; 
void hang::nhap()
{
	cout<<"\n nhap ma hang:";		fflush(stdin);		gets(mahang);
	cout<<"\n nhap ten hang:";		fflush(stdin);		gets(tenhang);
	cout<<"\n nhap don gia:";		cin>>dongia;
	 }
void hang::xuat()
{
	cout<<setw(15)<<mahang<<setw(15)<<tenhang<<setw(15)<<dongia<<endl; 
 } 
void phieu::nhap()
{
	cout<<"\n nhap ma phieu:";		fflush(stdin);		gets(maphieu);
	cout<<"\n nhap so luong hang:";	cin>>n;
	for(int i=0;i<n;i++)
		{
			x[i].nhap(); 
		 } 
 } 
void phieu::xuat() 
{
	cout<<"\n Ma phieu:"<<maphieu<<endl;
	cout<<setw(15)<<"Ma hang"<<setw(15)<<"Ten hang"<<setw(15)<<"Don gia"<<endl; 
	for(int i=0;i<n;i++)
	{
		x[i].xuat(); 
	 } 
}
main()
{
	phieu a;
	a.nhap();
	cout<<"\n======================PHIEU================="<<endl;
	a.xuat();
			return 0; 
 } 
 
