#include <cstdio>
int N; // 4 <= N <= 100
int main() {
    scanf("%d", &N);
    int sum = 0;
    for (int i = 1; i <= N; ++i) sum += i;
    printf("%f\n", sum / (double) N * 10000);
    return 0;
}
