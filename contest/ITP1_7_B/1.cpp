#include <cstdio>
int n, x, answer;
int main() {
    while (1) {
        scanf("%d %d", &n, &x);
        if (n == 0 && x == 0) break;
        answer = 0;
        for (int i = 1; i <= n - 2; ++i) {
            for (int j = i + 1; j <= n - 1; ++j) {
                for (int k = j + 1; k <= n; ++k) {
                    if (i + j + k == x) {
                        // printf("%d + %d + %d\n", i, j, k);
                        ++answer;
                    }
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
