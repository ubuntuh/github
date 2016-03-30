#include <cstdio>
int n, m;
int A[100 + 1][100 + 1];
int b[100 + 1];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int c = 0;
        for (int j = 1; j <= m; ++j) {
            c += A[i][j] * b[j];
        }
        printf("%d\n", c);
    }
    return 0;
}
