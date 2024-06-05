#include <iostream>
#include <fstream> // Th� vi?n �? s? d?ng file
using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Constructor m?c �?nh v� constructor c� tham s?
    PhanSo(int tu = 0, int mau = 1) : tuSo(tu), mauSo(mau) {}

    // Ph��ng th?c t�nh t�ch c?a hai ph�n s?
    PhanSo operator*(const PhanSo& other) const {
        return PhanSo(tuSo * other.tuSo, mauSo * other.mauSo);
    }

    // Ph��ng th?c t�nh gi� tr? c?a ph�n s?
    double getValue() const {
        return static_cast<double>(tuSo) / mauSo;
    }

    // H�m nh?p th�ng tin c?a ph�n s?
    friend istream& operator>>(istream& is, PhanSo& ps) {
        cout << "Nhap tu so: ";
        is >> ps.tuSo;
        cout << "Nhap mau so: ";
        is >> ps.mauSo;
        return is;
    }

    // H�m xu?t th�ng tin c?a ph�n s?
    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        os << ps.tuSo << "/" << ps.mauSo;
        return os;
    }
};

int main() {
    PhanSo ps1, ps2, psKetQua;

    // Nh?p th�ng tin cho hai ph�n s?
    cout << "Nhap thong tin cho phan so thu nhat:\n";
    cin >> ps1;
    cout << "Nhap thong tin cho phan so thu hai:\n";
    cin >> ps2;

    // T�nh t�ch c?a hai ph�n s?
    psKetQua = ps1 * ps2;

    // M? t?p PHANSO.txt �? ghi k?t qu?
    ofstream outFile("PHANSO.txt");
    if (outFile.is_open()) {
        outFile << "Ket qua tich cua hai phan so: " << psKetQua << endl;
        outFile.close();
        cout << "Da ghi ket qua vao file PHANSO.txt.\n";
    } else {
        cout << "Khong the mo file de ghi ket qua.\n";
    }

    return 0;
}

