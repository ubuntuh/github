#include <cstdio>
long getFactorial(int index) {
    if (index == 0 || index == 1) return 1;
    return index * getFactorial(index - 1);
}
int main() {
    int NMax = 6;
    for (int N = 1; N <= NMax; ++N) {
        for (int K = 1; K <= N; ++K) {
            printf("N = %d, K = %d\n", N, K);
            long expr1 = getFactorial(N) / K % getFactorial(N - 1);
            long expr2 = (N % K) * getFactorial(N - 1) / K;
            printf("expr1, expr2 = %ld, %ld", expr1, expr2);
            if (expr1 == expr2) printf(" (true)\n");
            else printf(" (false)\n");
        }
    }
    return 0;
}
