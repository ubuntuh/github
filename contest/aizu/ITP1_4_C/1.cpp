#include <cstdio>
int a, b, answer;
char op;
int main() {
    while (1) {
        scanf("%d %c %d", &a, &op, &b);
        if (op == '?') break;
        if (op == '+') answer = a + b;
        else if (op == '-') answer = a - b;
        else if (op == '*') answer = a * b;
        else answer = a / b;
        printf("%d\n", answer);
    }
    return 0;
}
