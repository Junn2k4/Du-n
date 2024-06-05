#include <bits/stdc++.h> 
using namespace std;
class maytinh; 
class nsx
{
	private:
		char tennsx[30];
		char diachi[30];
	public:
		void nhap();
		void xuat();
	 
 };
class may
{
	protected:
		char nhanhieu[30];
		nsx x;
		float giathanh;
	public:
		void nhap();
		void xuat();	 
	friend void sx(maytinh *a,int n); 
	friend void hienthi(maytinh *a,int n); 
 }; 
class maytinh:public may
{
	private:
		int tocdo,dlram,dlhdd;
	public:
		void nhap();
		void xuat(); 
 }; 
void nsx::nhap()
{
	cout<<"\n nhap ten nha san xuat:";		fflush(stdin);			gets(tennsx);
	cout<<"\n nhap dia chi  nha san xuat:";		fflush(stdin);			gets(diachi);
 } 
void nsx::xuat()
{
	cout<<setw(15)<<tennsx<<setw(15)<<diachi; 
} 
void may::nhap()
{
	cout<<"\n nhap ten nhan hieu:";		fflush(stdin);			gets(nhanhieu);
	x.nhap();
	cout<<"\n nhap gia thanh :";		cin>>giathanh; 
 } 
void may::xuat()
{
	cout<<setw(15)<<nhanhieu;
	x.xuat();
	cout<<setw(15)<<giathanh; 
 } 
void maytinh::nhap()
{
	may::nhap();
	cout<<"\n nhap toc do :";		cin>>tocdo;
	cout<<"\n nhap dl ram:";		cin>>dlram; 
 	cout<<"\n nhap dl hdd :";		cin>>dlhdd; 
 } 
void maytinh::xuat()
{
	may::xuat(); 
	cout<<setw(15)<<tocdo<<setw(15)<<dlram<<setw(15)<<dlhdd<<endl; 
 } 

void sx(maytinh *a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		
			if (a[i].giathanh>a[j].giathanh)
		 	{
		 		maytinh tp=a[i];
				 	a[i]=a[j];
				 	a[j]=tp ;
			 }
	 } 
 } 
}
void hienthi(maytinh *a,int n)
{
	for (int i=0;i<n;i++)
	{
		if(strcmp(a[i].nhanhieu,"HP")==0)
		a[i].xuat(); 
	 } 
 } 
main()
{
	int n;
	maytinh *x;
	x=new maytinh[30]; 
	do{
		cout<<"\n nhap so luong may tinh (2<=n<=30):";
		cin>>n;
		if(n<2 || n>30)
		{
			cout<<"\n NHap sai so luong .Vui long nhap lai"; 
		 } 
	} 
	while(n<2||n>30);
		for (int i=0;i<n;i++)
		{
			cout<<"May thu:"<<i+1<<endl; 
			x[i].nhap();
			 
		 } 
	cout<<setw(20)<<"nhanhieu";
	cout<<setw(15)<<"tennsx"<<setw(15)<<"diachi";
	cout<<setw(15)<<"giathanh"; 
	cout<<setw(15)<<"tocdo"<<setw(15)<<"dlram"<<setw(15)<<"dlhdd"<<endl;  
	for (int i=0;i<n;i++)
	{
		cout<<setw(5)<<i+1;
		x[i].xuat(); 
	 } 
	 cout<<"\n=========Hien thi nhan HP======="<<endl;
	 hienthi(x,n);
	 cout<<"------------Sau khi sap xep theo GIA THANH----------------"<<endl; 
	 sx(x,n);
	 for (int i;i<n;i++)
	 {
	  
	 x[i].xuat(); 
	}
	 
	return 0; 
 } 
