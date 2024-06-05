#include<bits/stdc++.h>
using namespace std;
class  nv
{
	private:
		char nvkk[20];
		char cv[20];
	public:
		void nhap();
		void xuat();
};		
void nv::nhap()
{
	cout<<"\n Nhap Ten nhan vien kiem ke: ";		fflush(stdin);		gets(nvkk);
	cout<<"\n Nhap chuc vu: ";		fflush(stdin);		gets(cv);
}
void nv::xuat()
{
	cout<<setw(15)<<" Nhan vien kiem ke: "<<nvkk;
	cout<<setw(30)<<" Chuc vu: "<<cv<<endl;	
}
class phieu;
class phong
{
	private:
		char kktp[20];
		char mp[20];
		char trp[20];
	public:
		void nhap();
		void xuat();

};

void phong::nhap()				
{
	cout<<"\n Nhap kiem ke tai phong: ";		fflush(stdin);			gets(kktp);
	cout<<"\n Nhap ma phong: ";		fflush(stdin);			gets(mp);
	cout<<"\n Nhap truong phong: ";		fflush(stdin);			gets(trp);
}
void phong::xuat()
{
	cout<<setw(15)<<"Kiem ke tai phong: "<<kktp;
	cout<<setw(30)<<"Ma phong: "<<mp;
	cout<<setw(15)<<"Truong phong: "<<trp<<endl;
}
class phieu;
class ts
{
	private:
		char tents[20];
		int sl;
		char tt[20];
	public:
		void nhap();
		void xuat();
		friend class phieu;
		friend void sua(phieu & c);
		friend void sapxep(phieu & c);
		friend void xoa(phieu & c);
};
void ts::nhap()
{
	cout<<"\n Nhap ten tai san: ";		fflush(stdin);		gets(tents);
	cout<<"\n Nhap so luong: ";							cin>>sl;
	cout<<"\n Nhap tinh trang: ";		fflush(stdin);		gets(tt);
}
void ts::xuat()
{
	cout<<setw(15)<<tents<<setw(15)<<sl<<setw(15)<<tt<<endl;
}
class phieu
{
	private:
		char mph[20];
		char nkk[20];
		nv x;
		phong y;
		ts z[50];
		int n;
	public:
		void nhap();
		void xuat();
		friend void sua(phieu & c);
		friend void sapxep(phieu & c);
		friend void xoa(phieu & c);
};
void phieu::nhap()
{
	cout<<"\n Nhap ma phieu: ";		fflush(stdin);		gets(mph);
	cout<<"\n Nhap ngay kiem ke: ";		fflush(stdin);	gets(nkk);
	x.nhap();
	y.nhap();
	cout<<"\n Nhap so luong tai san: ";		cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<"\n Nhap tai san "<<i+1<<endl;
		z[i].nhap();
		cout<<endl;
	}
}
void phieu::xuat()
{
	cout<<setw(15)<<"Ma phieu: "<<mph;
	cout<<setw(30)<<"Ngay lap: "<<nkk<<endl;
	x.xuat();
	y.xuat();
	cout<<setw(15)<<"Ten tai san";
	cout<<setw(15)<<"So luong";
	cout<<setw(15)<<"Tinh trang"<<endl;
	for (int i=0;i<n;i++)
	{
		z[i].xuat();
	}
	cout<<"So tai san da kiem ke: "<<n;
	float t=0;
	for (int i=0;i<n;i++)
	{
		t+=z[i].sl;
	}
	cout<<setw(30)<<"Tong so luong: "<<t<<endl;
}
void sua(phieu & c)
{
	for (int i=0;i<c.n;i++)
	{
		if (strcmp(c.z[i].tents,"May vi tinh")==0)
		{
			c.z[i].sl=20;
		}
	}
}
void sapxep(phieu & c)
{
	for (int i=0;i<c.n-1;i++)
	{
		for (int j=i+1;j<c.n;j++)
		{
			if (c.z[j].sl<c.z[i].sl)
			{
				ts tg=c.z[i];
				c.z[i]=c.z[j];
				c.z[j]=tg;
				
				
			}
		}
	}
}
void xoa(phieu & c)
{
 	int k;
 	do{
 		cout<<"\n Nhap vi tri can xoa";		cin>>k;
	 }
	while(k<0 || k>c.n);
	
	for (int i=k;i<c.n;i++)
	{
		c.z[i]=c.z[i+1];	
	}
	c.n--;
}
main()
{
	phieu a;
	a.nhap();
	a.xuat();
	cout<<"\t\t\t\t\t THONG TIN SAU KHI SUA"<<endl;
	sua(a);
	a.xuat();
	sapxep(a);
	cout<<"\t\t\t\t\t THONG TIN SAU KHI SUA"<<endl;
	a.xuat();
	xoa(a);
	cout<<"\t\t\t\t\t THONG TIN SAU KHI xoa"<<endl;
	a.xuat();
}
