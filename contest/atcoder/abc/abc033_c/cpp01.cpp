#include <cstdio>

int answer;
char ch;
bool hasZeroFactor = false;

int main() {
    while (scanf("%c", &ch) != EOF) {
        if (ch == '0') {
            hasZeroFactor = true;
        }
        if (ch == '+' || ch == '\n') {
            if (!hasZeroFactor) {
                ++answer;
            }
            hasZeroFactor = false;
        }
    }
    printf("%d\n", answer);
    return 0;
}
