#include <bits/stdc++.h>
using namespace std;
class phieu;
class ncc
{
	private:
		char mancc[20];
		char tenncc[30];
		char diachi[20];
		int sdt;
	public:
		void nhap();
		void xuat();
		
};
class hang
{
	private:
		char masp[20];
		char tensp[30];
		int slg;
		int dongia;
	public:
		void nhap();
		void xuat();
	friend class phieu;
	friend void sx(phieu &a);
	friend void dem(phieu a);

};
class phieu
{
	private:
		char maphieu[20];
		int ngay;
		ncc x;
		hang y[30];
		int n;
	public:
		void nhap();
		void xuat();
	friend void sx(phieu &a);
	friend void dem(phieu a);
		
};
void ncc::nhap()
{
	cout<<"\n nhap ma nha cung cap la:";			fflush(stdin);			gets(mancc);
	cout<<"\n nhap ten nha cung cap la:";			fflush(stdin);			gets(tenncc);
	cout<<"\n nhap dia chi la:";					fflush(stdin);			gets(diachi);
	cout<<"\n nhap sdt la:";						cin>>sdt;
	
}
void ncc::xuat()
{
	cout<<setw(15)<<"Ma nha cung cap:"<<mancc<<setw(20)<<"ten nha cung cap:"<<tenncc<<endl;
	cout<<setw(15)<<"Dia chi:"<<diachi<<setw(20)<<"sdt:"<<sdt<<endl;
	
}
void hang::nhap()
{
	cout<<"\n nhap ma san pham la:";				fflush(stdin);			gets(masp);
	cout<<"\n nhap ten san pham la:";				fflush(stdin);			gets(tensp);
	cout<<" \n nhap so luong la:";					cin>>slg;
	cout<<"\n nhap don gia la:";					cin>>dongia;
}
void hang::xuat()
{
	cout<<setw(15)<<masp<<setw(15)<<tensp<<setw(15)<<slg<<setw(15)<<dongia<<setw(15)<<slg*dongia<<endl;
}
void phieu::nhap()
{
	cout<<"\n nhap ma phieu la:";				fflush(stdin);			gets(maphieu);
	cout<<"\n nhap ngay lap la:";				cin>>ngay;
	x.nhap();
	cout<<"\n nhap so luong san pham la:";		cin>>n;
	for(int i=0;i<n;i++)
	{
		y[i].nhap();
	}
}
void phieu::xuat()
{   
	cout<<"\n" ;
	cout<<setw(15)<<"Ma phieu:"<<maphieu<<setw(20)<<"ngay lap:"<<ngay<<endl;
	x.xuat();
	cout<<setw(15)<<"ma sp"<<setw(15)<<"ten sp"<<setw(15)<<"so luong"<<setw(15)<<"don gia"<<setw(15)<<"thanh tien"<<endl;
	for(int i=0;i<n;i++)
	{
		y[i].xuat();
	}
	float tong=0;
	for(int i=0;i<n;i++)
		{
			tong=tong+ y[i].slg*y[i].dongia;
		}
	cout<<"\n tong "<<setw(60)<<tong<<endl;
}
void dem(phieu a)
{
	for (int i=0;i<a.n;i++)
		{
			if(a.y[i].slg<80)
			a.y[i].xuat();
		}
}
void sx(phieu &a)
{
	for(int i=0;i<a.n-1;i++)
	{
		for( int j=i+1;j<a.n;j++)
		if(a.y[i].dongia>a.y[j].dongia)
		{
			hang tg=a.y[i];
			a.y[i]=a.y[j];
			a.y[j]=tg;
		}
	}



		
}

main()
{

	phieu a;
	a.nhap();
	cout<<"Dai hoc Victory";
	cout<<"\n======================Phieu nhap van phong pham=================================="<<endl;
	a.xuat();
	cout<<"\n Cac san pham nho hon80 so luong la:"<<endl;
	dem(a);
	cout<<"Hieu Truong"<<setw(20)<<"Phong tai chinh"<<setw(20)<<"Nguoi lap"<<endl;
	cout<<"\n======================Phieu nhap van phong pham sap xep=========================="<<endl;
	sx(a);
	a.xuat();
	cout<<"Hieu Truong"<<setw(20)<<"Phong tai chinh"<<setw(20)<<"Nguoi lap"<<endl;
	return 0;
}

