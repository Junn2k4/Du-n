#include <bits/stdc++.h>
using namespace std;
class gianhang;
class hang
{
	protected:
		char mahang[30];
		char loai[20];
		int nam;
		char hangsx[20];
	public:
		void nhap();
		void xuat();
};
class hop:public hang
{
	private:
		char kieudang[20];
		char chatlieu[20];
		int thetich;
		char ghichu[20];
	public:
		void nhap();
		void xuat();
	friend void sx(gianhang &a);
};
class gianhang
{
	private:
		char magian[20];
		char tengian[20];
		int dientich;
		hop *x;
		int n;
	public:
		void nhap();
		void xuat();
	friend void sua(gianhang &a);
	friend void sx(gianhang &a);
};
void hang::nhap()
{
	cout<<"\n nhap ma hang:";		fflush(stdin);		gets(mahang);
	cout<<"\n nhap loai hang:";		fflush(stdin);		gets(loai);
	cout<<"\n nhap nam san xuat";	cin>>nam;
	cout<<"\n nhap hang san xuat:";	fflush(stdin);		gets(hangsx);
	}
void hang::xuat()
{
	cout<<setw(15)<<mahang<<setw(15)<<loai<<setw(15)<<nam<<setw(15)<<hangsx;
}
void hop::nhap()
{
	hang::nhap();
	cout<<"\n nhap kieu dang:";		fflush(stdin);		gets(kieudang);
	cout<<"\n nhap chat lieu:";		fflush(stdin);		gets(chatlieu);
	cout<<"\n nhap the tich:";		cin>>thetich;
	cout<<"\n nhap ghi chu:";		fflush(stdin);		gets(ghichu);
	
}
void hop::xuat()
{
	hang::xuat();
	cout<<setw(15)<<kieudang<<setw(15)<<chatlieu<<setw(10)<<thetich<<setw(10)<<ghichu<<endl;
}
void gianhang::nhap()
{
	cout<<"\n nhap ma gian hang:";		fflush(stdin);		gets(magian);
	cout<<"\n nhap ten gian hang:";		fflush(stdin);		gets(tengian);
	cout<<"\n nhap dien tich:";			cin>>dientich;
	cout<<"\n nhap so luong hop:";		cin>>n;
	x =new hop[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Hop thu "<<i+1<<":"<<endl;
		x[i].nhap();
	}
}
void gianhang::xuat()
{
	cout<<setw(25)<<"Ma Gian Hang:"<<magian<<endl;
	cout<<setw(25)<<"Ten Gian Hang:"<<tengian<<endl;	
	cout<<setw(25)<<"Dien Tich:"<<endl;
	cout<<setw(20)<<"Ma Hang"<<setw(15)<<"Loai"<<setw(15)<<"Nam"<<setw(15)<<"Hangsx";
	cout<<setw(15)<<"Kieu Dang"<<setw(15)<<"Chat Lieu"<<setw(10)<<"The Tich"<<setw(10)<<"Ghi Chu"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<setw(5)<<i+1;
		x[i].xuat();
	}
}
void sua(gianhang &a)
{
	strcpy(a.tengian,"DONHUA");
}
void sx(gianhang &a)
{
	for(int i=0;i<a.n-1;i++)
	{
		for(int j=i+1;j<a.n;j++)
		{
			if (a.x[i].thetich<a.x[j].thetich)
			{
				hop tmp=a.x[i];
				a.x[i]=a.x[j];
				a.x[j]=tmp;
			}
		}
	}
}
main()
{
	gianhang a;
	a.nhap();
	cout<<"\n Thong tin gian hang"<<endl;
	a.xuat();
	sua(a);
	cout<<"\n Thong tin gian hang sau khi sua:"<<endl;
	a.xuat();
	sx(a);
	cout<<"\n THONG TIN GIAN HANG SAU KHI SAP XEP"<<endl;
	a.xuat();
		return 0;
}
/*
ABC
DUAN
50
3
ACX
NHUA
2022
DAX
Thon
silicon
40
Dep
ACX
nhom
2024
DAX
ao
sat
50
Dep
ACX
NHUA
2000
DAA
Thon
DOng
500
Ole
*/
