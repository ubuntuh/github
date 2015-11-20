#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float a, b, c, x1, x2, tmp;
    while (cin >> a >> b >> c) {
        if (a == 0) {
            cerr << "エラー！　最初の係数は 0！";
            cerr << endl;
            continue;
        }
        if ((tmp = b * b - 4 * a * c) < 0) {
            cerr << "エラー！　係数 ";
            cerr << a << "," << b << "," << c;
            cerr << " は複素数の根を持つ" << endl;
            continue;
        }
        tmp = sqrt(tmp);
        x1 = (-b + tmp) / (2 * a);
        x2 = (-b - tmp) / (2 * a);
        cout << "係数 = " << a << "," << b << "," << c;
        cout << "; 根 = " << x1 << "," << x2 << endl;
    }
}

