// 4 つのテストで WA。
// これだと例えば S = "a"、T = "t" の時、"You can win" という間違った出力を出す。
#include <cstdio>
#include <cstring>
char S[11], T[11];
void replace(char *s) {
    for (int i = 0;; ++i) {
        char c = s[i];
        if (c == '\0') return;
        switch (c) {
        case 'a':
        case 't':
        case 'c':
        case 'o':
        case 'd':
        case 'e':
        case 'r':
            s[i] = '@';
        }
    }
}
int main() {
    scanf("%s%s", S, T);
    replace(S);
    replace(T);
    if (strcmp(S, T)) puts("You will lose");
    else puts("You can win");
    return 0;
}
