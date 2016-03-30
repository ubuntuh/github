#include <cstdio>
int a, b, d, r;
double f;
int main() {
    scanf("%d %d", &a, &b);
    d = a / b;
    r = a % b;
    f = (double) a / b;
    printf("%d %d %f\n", d, r, f);
    return 0;
}
