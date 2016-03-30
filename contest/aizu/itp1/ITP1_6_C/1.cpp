#include <cstdio>
int A[4 + 1][3 + 1][10 + 1], n, b, f, r, v;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d %d", &b, &f, &r, &v);
        A[b][f][r] += v;
    }
    for (b = 1; b <= 4; ++b) {
        for (f = 1; f <= 3; ++f) {
            for (r = 1; r <= 10; ++r) {
                printf(" %d", A[b][f][r]);
            }
            printf("\n");
        }
        if (b != 4) printf("####################\n");
    }
    return 0;
}
