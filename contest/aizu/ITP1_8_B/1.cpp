#include <cstdio>
char c;
int answer;
int main() {
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') {
            if (answer == 0) break;
            printf("%d\n", answer);
            answer = 0;
        } else {
            answer += c - '0';
        }
    }
    return 0;
}
