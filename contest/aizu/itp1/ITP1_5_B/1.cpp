#include <cstdio>
int H, W;
int main() {
    while (1) {
        scanf("%d %d", &H, &W);
        if (H == 0 && W == 0) break;
        for (int h = 1; h <= H; ++h) {
            for (int w = 1; w <= W; ++w) {
                if (1 < h && h < H && 1 < w && w < W) {
                    printf(".");
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
