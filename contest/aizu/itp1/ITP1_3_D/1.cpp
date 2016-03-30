#include <cstdio>
int a, b, c, answer;
int main() {
    scanf("%d %d %d", &a, &b, &c);
    for (int i = a; i <= b; ++i) {
        if (c % i == 0) ++answer;
    }
    printf("%d\n", answer);
    return 0;
}
