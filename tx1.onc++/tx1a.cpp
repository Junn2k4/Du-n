#include<bits/stdc++.h>
using namespace std;
class hang{
	char tenhang[20];
	float dongia;
	int soluong;
	public:
		void nhap();
		void xuat();
		float thanhtien(){
			return soluong*dongia;
		}
		friend void bn1(hang x[20],int n);
		friend void bn2(hang x[20],int n);
};
void hang::nhap(){
	cout<<"nhap ten hang";fflush(stdin);gets(tenhang);
	cout<<"nhap don gia";cin>>dongia;
	cout<<"nhap so luong";cin>>soluong;
	
}
void hang::xuat(){
	
	cout<<tenhang<<setw(15)<<dongia<<setw(15)<<soluong<<setw(15)<<thanhtien()<<endl;
	
}
void bn1(hang x[20],int n){
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if (x[i].thanhtien()>x[j].thanhtien()){
				hang tg=x[j];
				x[j]=x[i];
				x[i]=tg;
				
			}
		}
	}
}
void bn2(hang x[20],int n){
	for (int i=0;i<n;i++){
		if (strcmp(x[i].tenhang,"Quat")==0){
			x[i].dongia=20;
		}
	}
}
class phieu{
	char maphieu[20];
	char ngaylap[20];
	char mncc[20];
	char tenncc[20];
	char diachi[30];
	hang x[20];
	int n;
	public:
		void nhap();
		void xuat();
};
void phieu::nhap(){
	cout<<"nhap ma phieu";fflush(stdin);gets(maphieu);
	cout<<"nhap ngay lap";fflush(stdin);gets(ngaylap);
	cout<<"nhap ma nha cung cap";fflush(stdin);gets(mncc);
	cout<<"nhap ten nha cung cap";fflush(stdin);gets(tenncc);
	cout<<"nhap dia chi";fflush(stdin);gets(diachi);
	cout<<"nhap so hang";cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"nhap thong tin cua hang thu"<<i+1<<endl;
		x[i].nhap();
		
	}
}
void phieu::xuat(){
	cout<<"ma phieu: "<<maphieu<<setw(15)<<"ngay lap: "<<ngaylap<<endl;
	cout<<"ma NCC: "<<mncc<<setw(15)<<"ten NCC: "<<tenncc<<endl;
	cout<<"dia chi: "<<diachi<<endl;
	cout<<"ten hang"<<setw(15)<<"don gia"<<setw(15)<<"so luong"<<setw(15)<<"thanh tien"<<endl;
	float tong=0;
	for(int i=0;i<n;i++){
		
		x[i].xuat();
		tong=tong+x[i].thanhtien();
	}
	cout<<setw(40)<<"cong thanh tien: "<<tong<<endl;
	bn1(x,n);
	cout<<"phieu sau khi sap xep"<<endl;
	cout<<"ma phieu: "<<maphieu<<setw(15)<<"ngay lap: "<<ngaylap<<endl;
	cout<<"ma NCC: "<<mncc<<setw(15)<<"ten NCC: "<<tenncc<<endl;
	cout<<"dia chi: "<<diachi<<endl;
	cout<<"ten hang"<<setw(15)<<"don gia"<<setw(15)<<"so luong"<<setw(15)<<"thanh tien"<<endl;
	for(int i=0;i<n;i++){
		
		x[i].xuat();
		tong=tong+x[i].thanhtien();
	}
	cout<<setw(40)<<"cong thanh tien: "<<tong<<endl;
	bn2(x,n);
	cout<<"phieu sau khi sua"<<endl;
	cout<<"ma phieu: "<<maphieu<<setw(15)<<"ngay lap: "<<ngaylap<<endl;
	cout<<"ma NCC: "<<mncc<<setw(15)<<"ten NCC: "<<tenncc<<endl;
	cout<<"dia chi: "<<diachi<<endl;
	cout<<"ten hang"<<setw(15)<<"don gia"<<setw(15)<<"so luong"<<setw(15)<<"thanh tien"<<endl;
	float tong1=0;
	for(int i=0;i<n;i++){
		
		x[i].xuat();
		tong1=tong1+x[i].thanhtien();
	}
	cout<<setw(40)<<"cong thanh tien: "<<tong1<<endl;
	
	
	
	
}

int main(){
	phieu x;
	x.nhap();
	x.xuat();
	
	
}
