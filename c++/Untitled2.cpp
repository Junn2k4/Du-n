#include <iostream>
#include <fstream> // Thý vi?n ð? s? d?ng file
using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;

public:
    // Constructor m?c ð?nh và constructor có tham s?
    PhanSo(int tu = 0, int mau = 1) : tuSo(tu), mauSo(mau) {}

    // Phýõng th?c tính tích c?a hai phân s?
    PhanSo operator*(const PhanSo& other) const {
        return PhanSo(tuSo * other.tuSo, mauSo * other.mauSo);
    }

    // Phýõng th?c tính giá tr? c?a phân s?
    double getValue() const {
        return static_cast<double>(tuSo) / mauSo;
    }

    // Hàm nh?p thông tin c?a phân s?
    friend istream& operator>>(istream& is, PhanSo& ps) {
        cout << "Nhap tu so: ";
        is >> ps.tuSo;
        cout << "Nhap mau so: ";
        is >> ps.mauSo;
        return is;
    }

    // Hàm xu?t thông tin c?a phân s?
    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        os << ps.tuSo << "/" << ps.mauSo;
        return os;
    }
};

int main() {
    PhanSo ps1, ps2, psKetQua;

    // Nh?p thông tin cho hai phân s?
    cout << "Nhap thong tin cho phan so thu nhat:\n";
    cin >> ps1;
    cout << "Nhap thong tin cho phan so thu hai:\n";
    cin >> ps2;

    // Tính tích c?a hai phân s?
    psKetQua = ps1 * ps2;

    // M? t?p PHANSO.txt ð? ghi k?t qu?
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

