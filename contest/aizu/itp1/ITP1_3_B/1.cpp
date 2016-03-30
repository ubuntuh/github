#include <cstdio>
int main() {
    int x;
    int i = 1;
    while (1) {
        scanf("%d", &x);
        if (x == 0) break;
        printf("Case %d: %d\n", i, x);
        ++i;
    }
    return 0;
}
