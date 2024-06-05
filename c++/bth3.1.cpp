#include <iostream>
#include <iomanip> 
using namespace std;
class sinhvien 
{
	private:
		char masv[30];
		char hoten[20];
		int diemtoan,diemly,diemhoa;
	public:
		void nhap();
		void xuat();
	friend void sx(sinhvien *a,int n);
		 
};
void sinhvien::nhap()
{
	cout<<"\n nhap masinh vien:";		fflush(stdin);		gets(masv);
	cout<<"\n nhap ho ten:";			fflush(stdin);		gets(hoten);
	cout<<"\n nhap diem toan:"; 		cin>>diemtoan; 
	cout<<"\n nhap diem ly:"; 		cin>>diemly; 
	cout<<"\n nhap diem hoa:"; 		cin>>diemhoa; 
}
void sinhvien::xuat()
{
	cout<<setw(15)<<masv<<setw(15)<<hoten<<setw(15)<<diemtoan<<setw(15)<<diemly<<setw(15)<<diemhoa<<setw(15)<<diemtoan+diemly+diemhoa<<endl;
	 
 } 
void sx(sinhvien *a,int n)
{

	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i].diemtoan+a[i].diemly+a[i].diemhoa>a[j].diemtoan+a[j].diemly+a[j].diemhoa)
			{
				sinhvien tg=a[i];
					 	a[i]=a[j];
						a[j]=tg ;
			}
			 
 } 
 main()
 {
 	sinhvien *a;
 	int n;
	cout<<"nhap so luong sinh vien:";		cin>>n; 
	a=new sinhvien[n]; 
	for (int i=0;i<n;i++) 
		a[i].nhap();
		sx(a,n);
	cout<<setw(15)<<"masv"<<setw(15)<<"hoten"<<setw(15)<<"diemtoan"<<setw(15)<<"diemly"<<setw(15)<<"diemhoa"<<setw(15)<<"tong diem"<<endl;
	for (int i=0;i<n;i++)
	a[i].xuat();
		 	return 0; 
	  
  } 
