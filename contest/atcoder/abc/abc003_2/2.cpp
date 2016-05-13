// Accepted.
#include <cstdio>
#include <cstring>
char S[11], T[11];
bool isAtCoder(char c) {
    switch (c) {
    case 'a':
    case 't':
    case 'c':
    case 'o':
    case 'd':
    case 'e':
    case 'r': return true;
    }
    return false;
}
bool cmp() {
    for (int i = 0;; ++i) {
        if (S[i] == '\0' && T[i] == '\0') {
            return true;
        } else if (S[i] == '\0' || T[i] == '\0') {
            return false;
        }
        if (S[i] == T[i]) {

        } else if (S[i] == '@' && T[i] == '@') {

        } else if (S[i] == '@' && isAtCoder(T[i])) {

        } else if (T[i] == '@' && isAtCoder(S[i])) {

        } else return false;
    }
}
int main() {
    scanf("%s%s", S, T);
    if (cmp()) puts("You can win");
    else puts("You will lose");
    return 0;
}
