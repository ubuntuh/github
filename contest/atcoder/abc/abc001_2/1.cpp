#include <cstdio>
int m;
int main() {
    scanf("%d", &m);
    if (m <= 99) puts("00");
    else if (100 <= m && m <= 999) printf("0%d\n", m / 100);
    else if (1000 <= m && m <= 5000) printf("%d\n", m / 100);
    else if (6000 <= m && m <= 30000) printf("%d\n", m / 1000 + 50);
    else if (35000 <= m && m <= 70000) printf("%d\n", (m / 1000 - 30) / 5 * 80);
    else puts("89");
}
