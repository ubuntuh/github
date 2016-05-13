#include <cmath>
#include <cstdio>
int xa, ya, xb, yb, xc, yc;
double length(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
double heronsFormula(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    double a = length(xb, yb, xc, yc);
    double b = length(xc, yc, xa, ya);
    double c = length(xa, ya, xb, yb);
    printf("%f\n", heronsFormula(a, b, c));
    return 0;
}
