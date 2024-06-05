#include<iostream>
using namespace std;

void nhap(int a[10][10], int m, int n)
{
   for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
      {
         cout<<"A["<<i<<"]["<<j<<"] = ";
         cin>>a[i][j];
      }
}
 
void xuat(int a[10][10], int m, int n)
{
	for(int i=0;i<m;i++)
   {
		for(int j=0;j<n;j++)
			cout <<a[i][j]<<"\t";
		cout <<"\n";
   }
}

void Tong(int a[10][10], int b[10][10], int c[10][10], int n,int m)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			c[i][j] = a[i][j] + b[i][j];
}
void Hieu(int a[10][10], int b[10][10], int c[10][10], int n,int m)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			c[i][j] = a[i][j] - b[i][j];
}

int Tongchan(int a[10][10], int m, int n)
{
    int sum = 0;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if (a[i][j] %2  == 0)
                sum += a[i][j];
    return sum;
}

int main(){
    int a[10][10], b[10][10],c[10][10];
    int m,n;
    
    cout <<"Nhap so hang n = "; 	cin>>m;
    cout<<"nhap so cot m = ";		cin>>n;
    
    cout <<"\nNhap ma tran thu nhat: "<<endl;
    nhap(a,m,n);
    xuat(a,m,n);
    
    cout<<"\nnhap vao ma tran thu hai: "<<endl;
    nhap(b,m,n);
    xuat(b,m,n);
    
    Tong(a,b,c,n,m);
    cout<<"\nTong hai ma tran la: "<<endl;
    xuat(c, m, n);
    
    Hieu(a,b,c,n,m);
    cout<<"\nHieu hai ma tran la: "<<endl;
    xuat(c, m, n);
    
    cout<<"\nTong chan ma tran thu nhat la: "<<Tongchan(a,m,n);
    
    
}
