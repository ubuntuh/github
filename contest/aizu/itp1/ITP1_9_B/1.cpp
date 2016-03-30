#include <cstdio>
#include <cstring>
char s[201], s2[201];
int h, length, numShuffle;
int main() {
    while (1) {
        scanf("%s", s);
        if (! strcmp(s, "-")) break;
        length = strlen(s);
        s2[length] = '\0';
        scanf("%d", &numShuffle);
        for (int i = 0; i <= numShuffle - 1; ++i) {
            scanf("%d", &h);
            strncpy(s2, &s[h], length - h);
            strncpy(&s2[length - h], s, h);
            strcpy(s, s2);
        }
        printf("%s\n", s);
    }
    return 0;
}
