#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x = i;
        if (x % 3 == 0) {
            printf(" %d", i);
        } else {
            do {
                if (x % 10 == 3) {
                    printf(" %d", i);
                    break;
                }
                x /= 10;
            } while (x);
        }
    }
    printf("\n");
}
