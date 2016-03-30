#include <cstdio>
#include <cstdlib>
#include <cstring>

int stack[100];
int sp;
void push(int value) {
    stack[sp++] = value;
}
int pop() {
    return stack[--sp];
}
void printStack() {
    for (int i = 0; i < sp; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

bool isOperator(const char* s) {
    if (strcmp(s, "+") == 0) return true;
    if (strcmp(s, "-") == 0) return true;
    if (strcmp(s, "*") == 0) return true;
    return false;
}

int main() {
    char s[10];
    while (scanf("%s", s) != EOF) {
        if (isOperator(s)) {
            int right = pop();
            int left = pop();
            // printf("l, r = %d, %d\n", left, right);
            if (strcmp(s, "+") == 0) push(left + right);
            if (strcmp(s, "-") == 0) push(left - right);
            if (strcmp(s, "*") == 0) push(left * right);
        } else {
            push(atoi(s));
        }
        // printStack();
    }
    printf("%d\n", pop());
    return 0;
}
