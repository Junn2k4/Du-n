#include <iostream>
#include <iomanip>
using namespace std;
class phieu;
class sv
{

	private:
		char masv[30];
		char ten[30];
		char lop[30];
		int khoa;
	public:
		void nhap();
		void xuat();
	};
class mon
{

	private:
		char tenmon[30];
		int sotrinh, diem;
	public:
		void nhap();
		void xuat();
	friend class phieu;
	friend void diem(phieu &a);
	friend void chen(phieu &a);
	};
class phieu
{

	private:
		sv x;
		mon y[30];
		int n;
	public:
		void nhap();
		void xuat();
	friend void diem(phieu &a);
	friend void chen(phieu &a);
	};
void sv::nhap()
{
	cout<<"\n nhap Ma sinh vien:";		fflush(stdin);		gets(masv);
	cout<<"\n nhap ten sinh vien:";		fflush(stdin);		gets(ten);
	cout<<"\n nhap lop:";				fflush(stdin);		gets(lop);
	cout<<"\n Nhap khoa:";				cin>>khoa;
	
}
void sv::xuat()
{
	cout<<setw(15)<<"Ma sinh vien:"<<masv<<setw(20)<<"Ten sinh vien:"<<ten<<endl;
	cout<<setw(15)<<"Lop:"<<lop<<setw(20)<<"Khoa:"<<khoa<<endl;
}
void mon::nhap()
{
	cout<<"\n nhap ten mon:";			fflush(stdin);		gets(tenmon);
	cout<<"\n nhap so trinh:";			cin>>sotrinh;
	cout<<"\n nhap diem:";				cin>>diem;
}
void mon::xuat()
{
	cout<<setw(15)<<tenmon<<setw(15)<<sotrinh<<setw(15)<<diem<<endl;
}

void phieu::nhap() {
    x.nhap();

    do {
        cout << "Nhap so luong mon (2 <= n <= 30): ";
        cin >> n;
        if (n < 2 || n > 30) 
		{
            cout << "So luong mon hoc khong hop le. Vui long nhap lai.\n";
        }
    }
	 while (n < 2 || n > 30);

    for (int i = 0; i < n; i++) 
	{
        cout << "\nNhap thong tin mon hoc thu " << i + 1 << ":\n";
        y[i].nhap();
    }
}
void phieu::xuat()
{
	x.xuat();
	cout<<"Bang diem:"<<endl;
	cout<<setw(15)<<"Ten mon"<<setw(15)<<"So trinh"<<setw(15)<<"Diem"<<endl;
	for (int i=0;i<n;i++)
	{
		y[i].xuat();
	}
	float tong=0,tb=0,t=0;
	for (int i=0;i<n;i++)
	{
		t=t+y[i].sotrinh;
		tong=tong+y[i].sotrinh*y[i].diem;
		tb=tong/t;
	}
	cout<<setw(40)<<"Diem trung binh:"<<tb<<endl;
		
}

void diem(phieu &a) 
{
    bool dem = false; 
    for (int i = 0; i < a.n; i++) 
	{
        if (a.y[i].sotrinh > 3)
		 {
            if (!dem)
			 {
                cout << "\nMon co so trinh lon 3:" << endl;
                dem = true;
            }
            a.y[i].xuat();
        }
    }
    if (!dem) {
        cout << "\nKhong co mon nao co so trinh lon hon 3!" << endl;
    }
}
                       
void chen(phieu &a)
{
	int k;
	do
	{
		cout<<"\n nhap vi tri xoa:";			cin>>k;
		
	}
	while(k<0||k>a.n);
	
	for(int i=k;i<a.n;i++)
	{
		a.y[i]=a.y[i+1];
		
	}
	a.n--;
}
main()
{
	phieu a;
	a.nhap();
	cout<<"\n================PHIEU BAO DIEM======================"<<endl;
	a.xuat();
	cout<<"\n------------------------------------------"<<endl;
	diem(a);
	cout<<"\n------------------------------------------"<<endl;
	chen(a);
	cout<<"\n================PHIEU BAO DIEM======================"<<endl;
	a.xuat();
		return 0;
}

