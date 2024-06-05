#include <bits/stdc++.h>
using namespace std;
class matran
{
private:
    int a[10][10], b[10][10];
    int m, n;
public:
	void nhap()
	{
		cout<<"Nhap so hang va so cot cua 2 ma tran: "<<endl;
		cout<<"Nhap so hang: "; cin>>m;
		cout<<"Nhap so cot: "; cin>>n;
	}
	
    void nhapm1() 
    {
        cout<<"Nhap ma tran 1:"<<endl;
        for (int i=0; i<m;i++)
            for (int j=0;j<n;j++)
            {
            	cout<<"A["<<i<<"]["<<j<<"] = ";
                cin >> a[i][j];
        	}
    }
    
    void nhapm2() 
    {
        cout<<"Nhap ma tran 2:"<<endl;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
            	cout<<"A["<<i<<"]["<<j<<"] = ";
                cin>>b[i][j];
        	}
    }
    
    void xuatm1() 
    {
        cout << "\nMa tran 1 la:" << endl;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
                cout<<"\t"<<a[i][j];
            cout<<endl;
        }
    }
    void xuatm2() 
    {
        cout<<"\nMa tran 2 la: "<<endl;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
                cout<<"\t"<<b[i][j];
            cout<<endl;
        }
    }
    void tong() 
    {
        cout<<"\nMa tran tong 1 + 2: "<<endl;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
                cout<<"\t"<<a[i][j] + b[i][j];
            cout << endl;
        }
    }
    
    void hieu() 
    {
        cout<<"Ma tran hieu 1 - 2:"<< endl;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
                cout << "\t"<<a[i][j] - b[i][j];
            cout << endl;
        }
    }
    
    void tongcacpt() 
    {
        cout <<"\nTong phan tu tung cot cua ma tran1 la:" << endl;
        int tong=0;
        for (int i=0;i<n;i++)
        {
            tong = 0; 
            for (int j = 0; j < m; j++)
                tong += a[j][i];
            cout <<"\t"<< tong;
        }
    }
    
    void timmax() 
    {
        int max = b[0][0]; 
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                if (max<b[i][j]) 
                    max=b[i][j];
        cout<<"\nMax cua ma tran 2 la: "<<max<<endl;
    }
};

main()
{
    matran m;
    m.nhap();
    m.nhapm1();
    m.nhapm2();
    m.xuatm1();
    m.xuatm2();
    m.tong();
    m.hieu();
    m.tongcacpt();
    m.timmax();
}




