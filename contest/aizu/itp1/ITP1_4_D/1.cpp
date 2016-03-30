#include <climits>
#include <cstdio>
int n; // [1, 10,000]
int a;
int min = INT_MAX;
int max = INT_MIN;
long sum;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if (a < min) min = a;
        if (max < a) max = a;
        sum += a;
    }
    printf("%d %d %ld\n", min, max, sum);
    return 0;
}
