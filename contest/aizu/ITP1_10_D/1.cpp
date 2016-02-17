#include <cmath>
#include <cstdio>
#include <cstdlib>
int n, x[101], y[101];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &y[i]);
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += abs(x[i] - y[i]);
    }
    double p1Distance = sum;
    printf("%lf\n", p1Distance);
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += pow(abs(x[i] - y[i]), 2);
    }
    double p2Distance = pow(sum, 1 / 2.);
    printf("%lf\n", p2Distance);
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += pow(abs(x[i] - y[i]), 3);
    }
    double p3Distance = pow(sum, 1 / 3.);
    printf("%lf\n", p3Distance);
    double max = 0;
    for (int i = 1; i <= n; ++i) {
        double value = abs(x[i] - y[i]);
        if (max < value) max = value;
    }
    double pooDistance = max;
    printf("%lf\n", pooDistance);    
    return 0;
}
