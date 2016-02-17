#include <cmath>
#include <cstdio>
int n;
double s[1001];
int main() {
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf", &s[i]);
        }
        double sum = 0;
        for (int i = 1; i <= n; ++i) sum += s[i];
        double mean = sum / n;
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            double deviation = s[i] - mean;
            sum += deviation * deviation;
        }
        double variance = sum / n;
        printf("%lf\n", sqrt(variance));
    }
    return 0;
}
