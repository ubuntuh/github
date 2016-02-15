#include <cstdio>
#include <cstring>
char s[101], p[101];
int main() {
    scanf("%s", s);
    scanf("%s", p);
    int sLength = strlen(s);
    int pLength = strlen(p);
    for (int i = 0; i <= sLength - 1; ++i) {
        for (int j = 0; j <= pLength - 1; ++j) {
            if (s[(i + j) % sLength] != p[j]) break;
            if (j == pLength - 1) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
