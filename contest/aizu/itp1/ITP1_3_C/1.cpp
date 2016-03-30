#include <cstdio>
int x, y, temp;
int main() {
    while (1) {
        scanf("%d %d", &x, &y);
        if (x == 0 && y == 0) break;
        if (y < x) {
            temp = x;
            x = y;
            y = temp;
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}
