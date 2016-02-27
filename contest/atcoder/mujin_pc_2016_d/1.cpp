#include <cstdio>
int N, Q, l, r;
char S[100001];
int main() {
    scanf("%d%s%d", &N, S, &Q);
    for (int q = 1; q <= Q; ++q) {
        scanf("%d%d", &l, &r);
        while (l < r) {
            ...
        }
    }
    return 0;
}
