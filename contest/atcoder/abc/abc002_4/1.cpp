#include <cstdio>
int N, M, x, y, relations[13][13];
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &x, &y);
        relations[x][y] = 1;
        relations[y][x] = 1;
    }
    // ...
    return 0;
}
