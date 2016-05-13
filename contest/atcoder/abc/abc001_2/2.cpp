#include <cstdio>
double km;
int m, VV;
int main() {
    scanf("%d", &m);
    km = m / 1000.;
    if (km < 0.1) {
        VV = 0;
    } else if (0.1 <= km && km <= 5) {
        VV = km * 10;
    } else if (6 <= km && km <= 30) {
        VV = km + 50;
    } else if (35 <= km && km <= 70) {
        VV = (km - 30) / 5 + 80;
    } else if (70 < km) {
        VV = 89;
    }
    printf("%02d\n", VV);
    return 0;
}

