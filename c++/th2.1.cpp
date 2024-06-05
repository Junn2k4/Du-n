#include <bits/stdc++.h>
using namespace std;
class date
{
	private:
		int d,m,y;
	public:
		void nhap();		
		void xuat();
	};
class nhansu
{
	private:
		char manhansu[30];
		char hoten[30];
		date x;
	public:
		void nhap();
		void xuat(); 
		 
 } ;
void date::nhap()
{
	cout<<"\n nhap ngay:";		cin>>d;
	cout<<"\n nhap thang:";		cin>>m;
	cout<<"\n nhap nam:";		cin>>y;
 
 }
void date::xuat()
{
	cout<<"\n Date:"<<d<<"/"<<m<<"/"<<y<<endl; 
 }
void nhansu::nhap()
{
	cout<<"\n nhap ma nhan su:";		fflush(stdin);	gets(manhansu);
	cout<<"\n nhap ho va ten :";		fflush(stdin);	gets(hoten);
	x.nhap();
 } 
void nhansu::xuat()
{
	cout<<"\n Ma nhan su:"<<manhansu;
	cout<<"\n Ho va ten:"<<hoten<<endl;
	x.xuat();
 } 
main()
{
	nhansu a;
	a.nhap();
	cout<<"\n ==============THONG TIN NHAN SU============="<<endl; 
	a.xuat();
	return 0; 
  }  
 
