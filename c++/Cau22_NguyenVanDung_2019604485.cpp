#include<iostream>
#include<iomanip>
using namespace std;

class phieu;

class ncc
{
	private:
		char mancc[15];
		char tenkh[25];
		char dc[25];
	public:
		void nhap();
		void xuat();
};

class sp
{
	private:
		char masp[10];
		char tensp[15];
		int sl;
		float dg;
	public:
		void nhap();
		void xuat();
		friend void sx(sp a[75], int n);
		friend void hoanvi(sp *a, sp *b); 
		friend void chen(sp a[75], int *n);
};

class phieu
{
	private:
		char maphieu[10];
		char ngay[10];
		ncc x;
		sp y[75];
		int n;
	public:
		void nhap();
		void xuat();
		
};

void ncc::nhap()
{
	cout<<"\nNhap ma nha cung cap: ";		fflush(stdin);		gets(mancc);
	cout<<"\nNhap ten nha cung cap: ";		fflush(stdin);		gets(tenkh);
	cout<<"\nNhap dia chi: ";				fflush(stdin);		gets(dc);
}

void ncc::xuat()
{
	cout<<"Ma nha cung cap: "<<mancc;			cout<<setw(30)<<"Ten KH: "<<tenkh<<endl;
	cout<<"Dia chi: "<<dc;				
}


void sp::nhap()
{
	cout<<"\nNhap ma sach: ";		fflush(stdin);		gets(masp);
	cout<<"\nNhap ten sach: ";		fflush(stdin);		gets(tensp);
	cout<<"\nNhap so luong: ";								cin>>sl;
	cout<<"\nNhap don gia: ";								cin>>dg;
}

void sp::xuat()
{
	cout<<setw(10)<<masp<<setw(20)<<tensp<<setw(10)<<sl<<setw(10)<<dg<<setw(15)<<sl*dg<<endl;
}

void phieu::nhap()
{
	cout<<"\nNhap ma phieu: ";		fflush(stdin);		gets(maphieu);
	cout<<"\nNhap ngay xuat: ";		fflush(stdin);		gets(ngay);
	x.nhap();
	
	cout<<"\nNhap so luong san pham: ";	
	cin>>n;
	
	for(int i=0;i<n;i++)
		y[i].nhap();
}

void phieu::xuat()
{
	cout<<"Ma phieu: "<<maphieu;		cout<<setw(30)<<"Ngay xuat: "<<ngay<<endl;
	x.xuat();
	cout<<"\nThong tin sach xuat: "<<endl;
	cout<<setw(10)<<"MA SACH"<<setw(20)<<"TEN SACH"<<setw(10)<<"SL"<<setw(10)<<"DG"<<setw(15)<<"TT"<<endl;
	for(int i=0;i<n;i++)
		y[i].xuat();
		
	sx(y,n);
	cout<<"\nDanh sach sau khi sap xep tang dan so luong la: "<<endl;
	cout<<setw(10)<<"MA SACH"<<setw(20)<<"TEN SACH"<<setw(10)<<"SL"<<setw(10)<<"DG"<<setw(15)<<"TT"<<endl;
	for(int i=0;i<n;i++)
		y[i].xuat();
		
	chen(y,&n);
	cout<<"\nDanh sach sau khi chen them mot ma sach la: "<<endl;
	cout<<setw(10)<<"MA SACH"<<setw(20)<<"TEN SACH"<<setw(10)<<"SL"<<setw(10)<<"DG"<<setw(15)<<"TT"<<endl;
	for(int i=0;i<n;i++)
		y[i].xuat();
}

void hoanvi(sp *a, sp *b)
{
	sp tg=*a;
	*a=*b;
	*b=tg;
}

void sx(sp a[75], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i].sl > a[j].sl)
				hoanvi(&a[i],&a[j]);
}


void chen(sp a[75], int *n)
{
	int k;
	cout<<"\nNhap vi tri can chen k: ";  cin>>k;
	sp x;
	cout<<"\nNhap thong tin sach can chen"<<endl;
	x.nhap();
	
	for(int i=*n;i>k;i--)
		a[i]=a[i-1];
	a[k]=x;
	(*n)++;
}
main()
{
	phieu a;
	a.nhap();
	cout<<setw(50)<<"PHIEU XUAT SACH"<<endl;
	a.xuat();
}
