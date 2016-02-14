#include <cstdio>
int r, c, array[101 + 1][101 + 1];
int main() {
    scanf("%d %d", &r, &c);
    for (int ri = 1; ri <= r; ++ri) {
        for (int ci = 1; ci <= c; ++ci) {
            int value;
            scanf("%d", &value);
            printf("%d ", value);
            array[ri][c + 1] += value;
            array[r + 1][ci] += value;
            array[r + 1][c + 1] += value;
            if (ci == c) {
                printf("%d", array[ri][c + 1]);
            }
        }
        printf("\n");
    }
    for (int ci = 1; ci <= c + 1; ++ci) {
        printf("%d", array[r + 1][ci]);
        if (ci != c + 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    return 0;
}
