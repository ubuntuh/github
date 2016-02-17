#include <cmath>
#include <cstdio>
double a, b, c, C, h, L, S;
int main() {
    scanf("%lf%lf%lf", &a, &b, &C);
    double CRad = C * 2 * M_PI / 360;
    h = b * sin(CRad);
    S = a * h / 2;
    c = sqrt(a * a + b * b - 2 * a * b * cos(CRad));
    L = a + b + c;
    printf("%lf\n", S);
    printf("%lf\n", L);
    printf("%lf\n", h);
    return 0;
}
