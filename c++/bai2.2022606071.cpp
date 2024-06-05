#include <bits/stdc++.h>
using namespace std;
class LOPHOC;
class NGUOI
{

	protected:
		char hoten[30];
		int ngaysinh;
		char quequan[20];
	public:
		void nhap();
		void xuat();
};
class SINHVIEN:public NGUOI
{

	private:
		char MASV[30];
		char nganh[20];
		int khoahoc;
	public:
		void nhap();
		void xuat();
	friend class LOPHOC;
	friend void dem(LOPHOC &a);
	friend void sx(LOPHOC &a);
};
class LOPHOC
{

	private:
		char MALH[30];
		char TenLH[20];
		int  ngaymo;
		SINHVIEN *x;
		int n;
		char GIAOVIEN[30];
	public:
		void nhap();
		void xuat();
	friend void dem(LOPHOC &a);
	friend void sx(LOPHOC &a);
};
void NGUOI::nhap()
{
	cout<<"\n nhap ho ten la:";				fflush(stdin);		gets(hoten);
	cout<<"\n nhap ngay sinh la:";			cin>>ngaysinh;
	cout<<"\n nhap que quan la:";			fflush(stdin);		gets(quequan);
}
void NGUOI::xuat()
{
	cout<<setw(15)<<hoten<<setw(15)<<ngaysinh<<setw(15)<<quequan;
}
void SINHVIEN::nhap()
{
	NGUOI::nhap();
	cout<<"\n Nhap Ma sinh vien la:";		fflush(stdin);		gets(MASV);
	cout<<"\n Nhap nganh la:";				fflush(stdin);		gets(nganh);
	cout<<"\n nhap khoa hoc la:";			cin>>khoahoc;
}
void SINHVIEN::xuat()
{
	NGUOI::xuat();
	cout<<setw(15)<<MASV<<setw(15)<<nganh<<setw(15)<<khoahoc<<endl;
}
void LOPHOC::nhap()
{
	cout<<"\n Nhap MALH la:";				fflush(stdin);		gets(MALH);
	cout<<"\n Nhap TenLH la:";				fflush(stdin);		gets(TenLH);
	cout<<"\n Nhap ngay mo la:";			cin>>ngaymo;
	cout<<"\n Mhap so luong sinh vien la:"; cin>>n;
	x=new SINHVIEN[30];
	for (int i=0;i<n;i++)
		{
			cout<<"\n SINH vien thu:"<<i+1<<endl;
			x[i].nhap();
		}
	cout<<"\n Nhap giao vien la:";			fflush(stdin);		gets(GIAOVIEN);
}
void dem(LOPHOC &a)
{
	int dem=0;
	for(int i=0;i<a.n;i++)
		{
			if (a.x[i].khoahoc==11)
			{
				dem+=1;
			}
		}
		
		{
			if(dem>0)
				cout<<"\n lop hoc co so sinh vien khoa 11 la:"<<dem;
			else
				cout<<"\n khong co sinh vien khoa 11"<<endl;
		    }
}
void sx(LOPHOC &a)
{
	for(int i=0;i<a.n;i++)
	  {
	  	for(int j=i+1;j<a.n;j++)
	  	  if(a.x[i].khoahoc>a.x[j].khoahoc)
	  	  {
	  	  	SINHVIEN tg= a.x[i];
	  	  	a.x[i] = a.x[j];
	  	  	a.x[j] = tg;
			}
	  }
}
void LOPHOC::xuat()
{
	cout<<"\n MALH:"<<MALH<<endl;
	cout<<"\n TenLH:"<<TenLH<<endl;
	cout<<"\n NGAYMO:"<<ngaymo<<endl;
	cout<<"\n so luong sinh vien:"<<n<<endl;
	cout<<setw(15)<<"ho ten"<<setw(15)<<"ngay sinh"<<setw(15)<<"que quan";
	cout<<setw(15)<<"MASV"<<setw(15)<<"nganh"<<setw(15)<<"khoa hoc"<<endl;
	for (int i=0;i<n;i++)
	{
		x[i].xuat();
	}
	cout<<"\n Giao vien:"<<GIAOVIEN<<endl;
	
}
main()
{
	LOPHOC a;
	a.nhap();
	cout<<"\n ==========danh sach lop vua nhap============="<<endl;
	a.xuat();
	dem(a);
	cout<<"\n============danh sach sap xep tang dan theo khoa hoc========="<<endl;
	sx(a);
	a.xuat();
	return 0;
}

