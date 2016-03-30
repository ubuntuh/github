#include <cstdio>
char c, cs[256];
int main() {
    while (scanf("%c", &c) != EOF) {
        ++cs[c];
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        cs[i + 'a' - 'A'] += cs[i];
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        printf("%c : %d\n", i, cs[i]);
    }
    return 0;
}
