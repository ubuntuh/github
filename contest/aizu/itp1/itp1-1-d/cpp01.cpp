#include <cstdio>

int main() {
    // S :: [0, 86400)
    // 86400 = 24 * 60 * 60
    int S;
    scanf("%d", &S);
    int s = S % 60;
    int M = S / 60;
    int m = M % 60;
    int H = M / 60;
    int h = H % 60;
    printf("%d:%d:%d\n", h, m, s);
    return 0;
}
