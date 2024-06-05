#include <bits/stdc++.h>
using namespace std;

class maytinh;

class nsx {
    char tennsx[20];
    char diachi[20];
public:
    void nhap();
    void xuat();
    friend void bn1(maytinh x[20], int n);
};

void nsx::nhap() {
    cout << "Nhap ten nha san xuat: "; fflush(stdin); gets(tennsx);
    cout << "Nhap dia chi nha san xuat: "; fflush(stdin); gets(diachi);
}

void nsx::xuat() {
    cout << tennsx << setw(15) << diachi << setw(20);
}

class may {
protected:
    char nhanhieu[20];
    nsx x;
    float giathanh;
public:
    void nhap();
    void xuat();
    friend void bn1(maytinh x[20], int n);
    friend void bn2(maytinh x[20], int n);
};

void may::nhap() {
    x.nhap();
    cout << "Nhap nhan hieu: "; fflush(stdin); gets(nhanhieu);
    cout << "Nhap gia thanh: "; cin >> giathanh;
}

void may::xuat() {
    x.xuat();
    cout << nhanhieu << setw(15) << giathanh << setw(15);
}

class maytinh : public may {
    int tocdo;
    int dlram;
    int dlhdd;
public:
    void nhap();
    void xuat();
};

void maytinh::nhap() {
    may::nhap();
    cout << "Nhap toc do: "; cin >> tocdo;
    cout << "Nhap dung luong ram: "; cin >> dlram;
    cout << "Nhap dung luong hdd: "; cin >> dlhdd;
}

void maytinh::xuat() {
    may::xuat();
    cout << tocdo << setw(15) << dlram << setw(10) << dlhdd << endl;
}

void bn1(maytinh x[20], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(x[i].x.tennsx, "fpt") == 0) {
            x[i].xuat();
        }
    }
}

void bn2(maytinh x[20], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i].giathanh > x[j].giathanh) {
                maytinh tg = x[i];
                x[i] = x[j];
                x[j] = tg;
            }
        }
    }
}

void chen(maytinh x[20], int &n) {
    maytinh new_maytinh;
    int pos;
    do {
        cout << "\nNhap vi tri chen: "; cin >> pos;
    } while (pos < 0 || pos > n);
    cout << "\nNhap thong tin may tinh moi de chen:\n";
    new_maytinh.nhap();
    for (int i = n; i > pos; i--) {
        x[i] = x[i - 1];
    }
    x[pos] = new_maytinh;
    n++;
}

void xoa(maytinh x[20], int &n) {
    int pos;
    do {
        cout << "\nNhap vi tri xoa: "; cin >> pos;
    } while (pos < 0 || pos >= n);
    for (int i = pos; i < n - 1; i++) {
        x[i] = x[i + 1];
    }
    n--;
}

int main() {
    maytinh x[20];
    int n;
    cout << "Nhap so luong may tinh: "; cin >> n;
    while (n <= 2 || n >= 30) {
        cout << "Nhap lai so luong: ";
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cua may tinh thu " << i + 1 << endl;
        x[i].nhap();
    }

    cout << "Danh sach may tinh ban dau: " << endl;
    cout << "ten nsx" << setw(15) << "dia chi " << setw(15) << "nhan hieu" << setw(15) << "gia thanh" << setw(15) << "toc do" << setw(15) << "dl ram" << setw(15) << "dl hdd" << endl;
    for (int i = 0; i < n; i++) {
        x[i].xuat();
    }

    cout << "Thong tin cua may tinh co nha san xuat fpt: " << endl;
    cout << "ten nsx" << setw(15) << "dia chi " << setw(15) << "nhan hieu" << setw(15) << "gia thanh" << setw(15) << "toc do" << setw(15) << "dl ram" << setw(15) << "dl hdd" << endl;
    bn1(x, n);

    cout << "Sap xep theo chieu tang dan cua gia thanh: " << endl;
    bn2(x, n);
    cout << "ten nsx" << setw(15) << "dia chi " << setw(15) << "nhan hieu" << setw(15) << "gia thanh" << setw(15) << "toc do" << setw(15) << "dl ram" << setw(15) << "dl hdd" << endl;
    for (int i = 0; i < n; i++) {
        x[i].xuat();
    }

    chen(x, n);
    cout << "Danh sach may tinh sau khi chen: " << endl;
    cout << "ten nsx" << setw(15) << "dia chi " << setw(15) << "nhan hieu" << setw(15) << "gia thanh" << setw(15) << "toc do" << setw(15) << "dl ram" << setw(15) << "dl hdd" << endl;
    for (int i = 0; i < n; i++) {
        x[i].xuat();
    }

    xoa(x, n);
    cout << "Danh sach may tinh sau khi xoa: " << endl;
    cout << "ten nsx" << setw(15) << "dia chi " << setw(15) << "nhan hieu" << setw(15) << "gia thanh" << setw(15) << "toc do" << setw(15) << "dl ram" << setw(15) << "dl"<<endl; 
		for (int i = 0; i < n; i++) {
        x[i].xuat();
    }
		return 0;
}
