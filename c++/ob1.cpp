#include <bits/stdc++.h>
using namespace std;
class ncc
{
	private:
		char mancc[30];
		char tenncc[20]; 
		char diachi[30]; 
	public:
		void nhap();
		void xuat();
		 
};
class hang
{
	private:
		char tenhang[30];
		int dongia;
		int slg;
	public:
		void nhap();
		void xuat() ;
	friend class phieu; 
		 
 }; 
class phieu
{ 
	private:
		char maphieu[30];
		int ngay;
		ncc x;
		hang y[30];
		int n ;
	public:
		void nhap();
		void xuat();
		 
	
 } ;
 void ncc::nhap()
 {
 	cout<<"\n nhap ma ncc la:";					fflush(stdin);			gets(mancc);
	cout<<"\n nhap ten ncc la:";				fflush(stdin);			gets(tenncc);
	cout<<"\n nhap dia chi la:";				fflush(stdin);			gets(diachi);
  } 
 void ncc::xuat()
 {
 	cout<<setw(15)<<"Ma ncc:"<<mancc<<setw(20)<<"Ten ncc:"<<tenncc<<endl;
	cout<<setw(15)<<"Dia chi:"<<diachi<<endl; 
  } 
 void hang::nhap()
 {
 	cout<<"\n nhap ten hang la:";				fflush(stdin);			gets(tenhang);
 	cout<<"\n nhap don gia la:";				cin>>dongia;
	cout<<"\n nhap so luong la :";				cin>>slg;
		 
  } 
void hang::xuat()
{
	cout<<setw(15)<<tenhang<<setw(15)<<dongia<<setw(15)<<slg<<setw(15)<<dongia*slg<<endl; 
 } 
 void phieu::nhap()
 {
 	cout<<"\n nhap ma phieu la:";				fflush(stdin);			gets(maphieu);
	cout<<"\n nhap ngay lap la:";				cin>>ngay;
	 x.nhap();
	cout<<"\n nhap so luong hang la:";			cin>>n;
		for(int i=0;i<n;i++)	
		y[i].nhap() ;
          	 
  } 
void phieu::xuat()
{
	cout<<"\n" ;
	cout<<setw(15)<<"Ma phieu:"<<maphieu<<setw(20)<<"Ngay lap:"<<ngay<<endl;
	x.xuat();
	cout<<setw(15)<<"Ten hang"<<setw(15)<<"don gia"<<setw(15)<<"so luong"<<setw(15)<<"thanh tien"<<endl;
		for(int i;i<n;i++)
		
	  			 y[i].xuat();
	    	 
	float tong=0;
	for (int i=0;i<n;i++)
	{
		tong=tong+ y[i].dongia * y[i].slg; 
	 } 
	 cout<<setw(40)<<"tong thanh tien"<<tong<<endl; 
 } 
 main()
 {
 	phieu a;
	 a.nhap();
	 cout<<"\n =======================Phieu nhap hang=========================";
	 a.xuat(); 

	
	return 0; 
  } 

