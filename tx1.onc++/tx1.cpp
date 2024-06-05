#include<bits/stdc++.h>
using namespace std;
class maytinh;
class nsx{
	char tennsx[20];
	char diachi[20];
	public:
		void nhap();
		void xuat();
		friend void bn1(maytinh x[20],int n);
};
void nsx::nhap(){
	cout<<"nhap ten  nha san xuat";fflush(stdin);gets(tennsx);
	cout<<"nhap dia chi nha san xuat";fflush(stdin);gets(diachi);
}
void nsx::xuat(){
	cout<<tennsx<<setw(15)<<diachi<<setw(20);
}
class maytinh;
class may{
	protected:
		char nhanhieu[20];
		nsx x;
		float giathanh;
		
	public:
		void nhap();
		void xuat();
		friend void bn1(maytinh x[20],int n);
		friend void bn2(maytinh x[20],int n);
};
void may::nhap(){
	x.nhap();
	cout<<"nhap nhan hieu: ";fflush(stdin);gets(nhanhieu);
	cout<<"nhap gia thanh";cin>>giathanh;
	
}
void may::xuat(){
	x.xuat();
	cout<<nhanhieu<<setw(15)<<giathanh<<setw(15);
}
class maytinh:public may{
	int tocdo;
	int dlram;
	int dlhdd;
	public:
		void nhap();
		void xuat();
};
void maytinh::nhap(){
	may::nhap();
	cout<<"nhap toc do ";cin>>tocdo;
	cout<<"nhap dung luong ram ";cin>>dlram;
	cout<<"nhap dung luong hdd ";cin>>dlhdd;
	
}
void maytinh::xuat(){
	may::xuat();
	
	cout<<tocdo<<setw(15)<<dlram<<setw(10)<<dlhdd<<endl;
}
void bn1(maytinh x[20],int n){
	for(int i=0;i<n;i++){
		if(strcmp(x[i].x.tennsx,"fpt")==0){
			x[i].xuat();
		}
		
	}
}
void bn2(maytinh x[20],int n){
	for(int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (x[i].giathanh>x[j].giathanh){
				maytinh tg=x[i];
				x[i]=x[j];
				x[j]=tg;
				
			}
		}
	}
}
void chen( maytinh x[20],int &n,maytinh &ai,int k)
{
	do
	{
		cout<<"\n Nhap vi tri chen:";		cin>>k;
		
	}
	while(k<0||k>n);
	cout<<"\n NHap mon moi:"<<endl;
	ai.nhap();
	for (int i=0;i<n;i++)
	{
		x[i]=x[i-1];
	}
	x[k]=ai;
	n++;
}
int main(){
	maytinh x[20];
	int n;
	cout<<"nhap so luong may tinh";cin>>n;
	while (n<=2||n>=30){
		cout<<"nhap lai so luong";
		cin>>n;
	}
	for (int i=0;i<n;i++){
		cout<<"nhap thoong tin cua may tinh thu"<<i+1<<endl;
		x[i].nhap();
		
	}
	cout<<"ten nsx"<<setw(15)<<"dia chi "<<setw(15)<<"nhan hieu"<<setw(15)<<"gia thanh"<<setw(15)<<"toc do"<<setw(15)<<"dl ram"<<setw(15)<<"dl hdd"<<endl;
	for (int i=0;i<n;i++){
		x[i].xuat();
		
	}
	cout<<"thong tin cua may tinh co nhan hieu fpt "<<endl;
	cout<<"ten nsx"<<setw(15)<<"dia chi "<<setw(15)<<"nhan hieu"<<setw(15)<<"gia thanh"<<setw(15)<<"toc do"<<setw(15)<<"dl ram"<<setw(15)<<"dl hdd"<<endl;
	bn1(x,n);
	cout<<"sap xep theo chieu tang dan cua gia thanh"<<endl;
	bn2(x,n);
	cout<<"ten nsx"<<setw(15)<<"dia chi "<<setw(15)<<"nhan hieu"<<setw(15)<<"gia thanh"<<setw(15)<<"toc do"<<setw(15)<<"dl ram"<<setw(15)<<"dl hdd"<<endl;
	for (int i=0;i<n;i++){
		x[i].xuat();
	chen(x,n,&ai,k);	
	cout<<"ten nsx"<<setw(15)<<"dia chi "<<setw(15)<<"nhan hieu"<<setw(15)<<"gia thanh"<<setw(15)<<"toc do"<<setw(15)<<"dl ram"<<setw(15)<<"dl hdd"<<endl;
	for (int i=0;i<n;i++){
		x[i].xuat();
	}
	
	
}
	return 0;
}
