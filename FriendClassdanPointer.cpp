#include <iostream>
#include <cmath>
using namespace std;

class BelahKetupat; // forward declaration

class LayangLayang {
private:
    double d1, d2; // diagonal
    double s1, s2; // sisi

public:
    void input() {
        cout << "\n== Input Layang-Layang ==" << endl;
        cout << "Masukkan diagonal 1: ";
        cin >> d1;
        cout << "Masukkan diagonal 2: ";
        cin >> d2;
        cout << "Masukkan sisi 1: ";
        cin >> s1;
        cout << "Masukkan sisi 2: ";
        cin >> s2;
    }

    double luas() {
        return 0.5 * d1 * d2;
    }

    double keliling() {
        return 2 * (s1 + s2);
    }

    void output() {
        cout << "\n== Layang-Layang ==" << endl;
        cout << "Luas     : " << luas() << endl;
        cout << "Keliling : " << keliling() << endl;
    }

    // friend function dari BelahKetupat
    friend double kelilingBelahKetupat(BelahKetupat b);
};

class BelahKetupat {
private:
    double d1, d2; // diagonal
    double s;      // sisi

public:
    void input() {
        cout << "\n== Input Belah Ketupat ==" << endl;
        cout << "Masukkan diagonal 1: ";
        cin >> d1;
        cout << "Masukkan diagonal 2: ";
        cin >> d2;
        cout << "Masukkan sisi: ";
        cin >> s;
    }

    double luas() {
        return 0.5 * d1 * d2;
    }

    void output() {
        cout << "\n== Belah Ketupat ==" << endl;
        cout << "Luas     : " << luas() << endl;
        cout << "Keliling : " << kelilingBelahKetupat(*this) << endl;
    }

    // kasih akses ke friend function
    friend double kelilingBelahKetupat(BelahKetupat b);
};

// friend function (akses private BelahKetupat & LayangLayang)
double kelilingBelahKetupat(BelahKetupat b) {
    return 4 * b.s;
}

int main() {
    LayangLayang l;
    BelahKetupat b;

    l.input();
    l.output();

    b.input();
    b.output();

    return 0;
}