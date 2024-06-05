#include <iostream>
#include <fstream>
#include<bits/stdc++.h>

using namespace std;

class hh {
    private:
        int d, r, h;
    public:
        hh();
        hh(int a, int b, int c);
        friend istream &operator>>(istream &a, hh &b);
        friend ostream &operator<<(ostream &a, hh b);
        friend hh operator+(hh d,hh e);
        friend hh operator-(hh d,hh e);
        friend bool operator/(hh d,hh e);
};

hh::hh() {
    d = 3;
    r = 4;
    h = 4;
}

hh::hh(int a, int b, int c) {
    d = a;
    r = b;
    h = c;
}

istream &operator>>(istream &a, hh &b) {
    cout << "\n nhap chieu dai:";
    a >> b.d;
    cout << "\n nhap chieu rong:";
    a >> b.r;
    cout << "\n nhap chieu cao:";
    a >> b.h;
    return a;
}

ostream &operator<<(ostream &a, hh b) {
    a << "\n Chieu dai:" << b.d << endl;
    a << "\n Chieu rong:" << b.r << endl;
    a << "\n Chieu cao:" << b.h << endl;
    return a;
}

hh operator+(hh d,hh e) {
    hh kq;
    kq.d = d.d + e.d;
    kq.r = e.r + d.r;
    kq.h = e.h + d.h;
    return kq;
}

hh operator-(hh d, hh e) {
    hh kq;
    kq.d = d.d - e.d;
    kq.r =  d.r-e.r;
    kq.h = d.h-e.h;
    return kq;
}

bool operator/(hh d,hh e) {
    if (e.d == d.d && e.r == d.r && d.h > 0)
        return true;
    return false;
}

int main() {
    ofstream f("acs.txt", ios::out);
    hh a, b(4, 5, 6), c, d;
    cout << "\n Thong tin hinh hop a:" << endl;
    cout << a << endl;
    cout << "\n Thong tin hinh hop b:" << endl;
    cout << b << endl;
    cout << "\n Thong tin hinh hop c:" << endl;
    cin >> c;
    cout << c << endl;
    cout << "\n Thong tin hinh hop d:" << endl;
    cin >> d;
    cout << d << endl;
    cout << "\n Cong hinh hop a va c:";
    cout << a + c << endl;
    cout << "\n Tru hinh hop d va c:";
    cout << d - c << endl;
    cout << "\n -------------------------" << endl;
    f << "\n Thong tin hinh hop a:" << endl;
    f << a << endl;
    f << "\n Thong tin hinh hop b:" << endl;
    f << b << endl;
    f << "\n Thong tin hinh hop c:" << endl;
    f << c << endl;
    f << "\n Thong tin hinh hop d:" << endl;
    f << d << endl;
    f << "\n Cong hinh hop a va c:";
    f << a + c << endl;
    f << "\n Tru hinh hop d va c:";
    f << d - c << endl;
    if (b / c) {
        cout << "2 Hinh co chieu rong va chieu dai bang nhau va chieu cao >0!" << endl;
        f << "2 Hinh co chieu rong va chieu dai bang nhau va chieu cao >0!" << endl;
    } else {
        cout << "2 Hinh khong co chieu rong va chieu dai bang nhau va chieu cao >0!" << endl;
        f << "2 Hinh khong co chieu rong va chieu dai bang nhau va chieu cao >0!" << endl;
    }
    cout << "\n KET QUA IN VAO asc.txt" << endl;
    return 0;
}

