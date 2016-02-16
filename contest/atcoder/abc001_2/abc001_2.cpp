#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int m; // 視程
    cin >> m;
    double km; // 視程を km 単位で表した値
    km = m / (double)1000;
    int v; // 通報式の整数表現
    if (km < 0.1) {
        v = 0;
    } else if (0.1 <= km && km <= 5) {
        v = km * 10;
    } else if (6 <= km && km <= 30) {
        v = km + 50;
    } else if (35 <= km && km <= 70) {
        v = (km - 30) / 5 + 80;
    } else if (70 < km) {
        v = 89;
    } else {
        // illegal input.
    }
    printf("%02d\n", v);
    return 0;
}

