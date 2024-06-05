#include<bits/stdc++.h>
using namespace std;

class NCC
{
	private:
		char MaNCC[20];
		char TenNCC[20];
		char Diachi[30];
	public:
		void nhap();
		void xuat();	
};

void NCC::nhap()
{
	cout<<"\n Nhap Ma NCC: ";		fflush(stdin);		gets(MaNCC);
	cout<<"\n Nhap Ten NCC: ";		fflush(stdin);		gets(TenNCC);
	cout<<"\n Nhap Dia chi: ";		fflush(stdin);		gets(Diachi);
}

void NCC::xuat()
{
	cout<<"Ma NCC: "<<MaNCC<<"Ten NCC: "<<TenNCC<<endl;
	cout<<"Dia chi: "<<Diachi<<endl;
}

class Phieu;
class Hang
{
	private:
		char Tenhang[20];
		int Dg,Sl;
	public:
		void nhap();
		void xuat();
	friend class Phieu;	
	friend void sapxep(Phieu &c);
	friend void sua(Phieu &c);
	friend void tim(Phieu &c);
	friend void chen(Phieu &c);
	friend void xoa(Phieu &c);
};

void Hang::nhap()
{
	cout<<"\n Nhap Ten hang: ";		fflush(stdin);		gets(Tenhang);
	cout<<"\n Nhap Don gia: ";		cin>>Dg;
	cout<<"\n Nhap So luong: ";		cin>>Sl;
}
void Hang::xuat()
{
	cout<<Tenhang<<setw(15)<<Dg<<setw(15)<<Sl<<setw(15)<<Dg*Sl<<endl;
}

class Phieu
{
	private:
		char Maphieu[20];
		char Ngaylap[20];
		NCC x;
		Hang y[50];
		int n;
	public:
		void nhap();
		void xuat();
	friend void sapxep(Phieu &c);
	friend void sua(Phieu &c);	
	friend void tim(Phieu &c);
	friend void chen(Phieu &c);
	 friend void xoa(Phieu &c);
};

void Phieu::nhap()
{
	cout<<"\n Nhap Ma phieu: ";		fflush(stdin);		gets(Maphieu);
	cout<<"\n Nhap Ngay lap: ";		fflush(stdin);		gets(Ngaylap);
	x.nhap();
	cout<<"\n Nhap so luong hang: ";		cin>>n;
	for(int i=0;i<n;i++)
	{
		y[i].nhap();
		cout<<endl;
	}
}

void Phieu::xuat()
{
	cout<<"Ma phieu: "<<Maphieu<<"Ngay lap: "<<Ngaylap<<endl;
	x.xuat();
	cout<<"Tenhang"<<setw(15)<<"Don gia"<<setw(15)<<"So luong"<<setw(15)<<"Thanh tien"<<endl;
	for(int i=0;i<n;i++)
	{
		y[i].xuat();
		cout<<endl;
	}
	
	float Congthanhtien=0;
	for(int i=0;i<n;i++)
	{
		Congthanhtien +=y[i].Dg*y[i].Sl;
	}
	cout<<"\t\t\t Cong thanh tien"<<Congthanhtien<<endl;
}

void sapxep(Phieu &c)
{
	for(int i=0;i<c.n-1;i++)
	{
		for (int j=i+1;j<c.n;j++)
		{
			if(c.y[j].Dg*c.y[j].Sl<c.y[i].Dg*c.y[i].Sl)
			{
				Hang tg=c.y[i];
				c.y[i]=c.y[j];
				c.y[j]=tg;
			}
		}
	}
}

void sua(Phieu &c)
{
	for(int i=0;i<c.n;i++)
	{
			if(strcmp(c.y[i].Tenhang,"Quat")==0)
			{
				c.y[i].Dg=30;
			}
	}
}

void tim(Phieu &c)
{
	for(int i=0;i<c.n;i++)
	{
		if(c.y[i].Dg==20)
		{
			
			c.y[i].xuat();
		}
		else
		{
			cout<<"\n Khong co don gia nao 20"<<endl;
		}
	}
	
}
void chen(Phieu &c)
{
	int k;
	do{
		cout<<"\n Nhap vi tri can chen: ";		cin>>k;
	}while(k<0 || k>c.n);
	
	Hang a1;
	a1.nhap();
	for(int i=c.n;i>k;i--)
	{
		c.y[i]=c.y[i-1];
	}
	c.y[k]=a1;
	c.n++;
}
void xoa(Phieu &c)
{
	int k;
	do{
		cout<<"\n Nhap vi tri can xoa: ";		cin>>k;
	}while(k<0 ||k>c.n);
	
	for(int i=k;i<c.n;i++)
	{
		c.y[i]=c.y[i+1];
	}
	
	c.n--;
}
main()
{
	Phieu a;
	a.nhap();
	a.xuat();
	sapxep(a);
	a.xuat();
	sua(a);
	a.xuat();
	tim(a);
	chen(a);
	a.xuat();
	xoa(a);
	a.xuat();
}

