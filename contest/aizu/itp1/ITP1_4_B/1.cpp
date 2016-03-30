#include <cmath>
#include <cstdio>
double r;
int main() {
    scanf("%lf", &r);
    double area = M_PI * r * r;
    double circumference = 2 * M_PI * r;
    printf ("%f %f\n", area, circumference);
    return 0;
}
