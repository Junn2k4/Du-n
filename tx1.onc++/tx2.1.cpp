#include<bits/stdc++.h>
using namespace std;

class SV
{
	private:
		char Hoten[20];
		int MSV;
		float Diem;
	public:
		SV();
		SV(char *a,int b,float c);
		friend istream& operator>>(istream &in, SV &d);
		friend ostream& operator<<(ostream &out, SV d);
		friend bool operator +(SV m,SV n);
		friend bool operator -(SV m,SV n);	
};

SV::SV()
{
	strcpy(Hoten,"Tran Van A");
	MSV=2022601122;
	Diem=10;
}

SV::SV(char *a,int b,float c)
{
	strcpy(Hoten,a);
	MSV=b;
	Diem=c;
}

istream& operator>>(istream &in, SV &d)
{
	cout<<"\n Nhap Ho ten: ";		fflush(stdin);		gets(d.Hoten);
	cout<<"\n Nhap MSV: ";			in>>d.MSV;
	cout<<"\n Nhap Diem: ";			in>>d.Diem;	
	return in;
}

ostream& operator<<(ostream &out, SV d)
{
	out<<"\n Thong tin sinh vien: "<<endl;
	out<<"Ho ten: "<<d.Hoten<<endl;
	out<<"MSV: "<<d.MSV<<endl;
	out<<"Diem: "<<d.Diem<<endl;
	return out;
}

bool operator +(SV m,SV n)
{
	if(strcmp(m.Hoten,n.Hoten)==0 && m.Diem==n.Diem)
		return true;
	return false;
}

bool operator -(SV m,SV n)
{
	if(strcmp(m.Hoten,"Nguyen Lan Anh")==0 || strcmp(n.Hoten,"Nguyen Lan Anh")==0)
		return true;
	return false;
}


int main()
{
	ofstream file("Ketqua.txt",ios::out);
	SV e;
	cout<<e<<endl;
	SV g("Nguyen Van B",20224455,9.5);
	cout<<g<<endl;
	SV k,l;
	cin>>k;
	cout<<k<<endl;
	cin>>l;
	cout<<l<<endl;
	if(e+l)
	{
		cout<<"2 sinh vien co thong tin cung nhau: "<<endl;
		file<<"2 sinh vien co thong tin cung nhau: "<<endl;
	}
	else
	{
		cout<<"2 sinh vien khong co thong tin cung nhau: "<<endl;
		file<<"2 sinh vien khong co thong tin cung nhau: "<<endl;
	}
	if(e-g || e-g||e-k||e-l||g-k||g-l||k-l)
	{
		cout<<"Co sinh vien ten Nguyen Lan Anh "<<endl;
		file<<"Co sinh vien ten Nguyen Lan Anh "<<endl;
	}
	else
	{
		cout<<"Khong co sinh vien ten Nguyen Lan Anh "<<endl;
		file<<"Khong co sinh vien ten Nguyen Lan Anh "<<endl;
	}
	return 0;
}
