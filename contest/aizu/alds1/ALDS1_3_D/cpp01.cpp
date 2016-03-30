#include <cstdio>

int stack[20000];
int position = 0;
void push(int a) {
    stack[position] = a;
    ++position;
}
int pop() {
    --position;
    return stack[position];
}
bool exist() {
    return 1 <= position;
}

struct Pond {
    int start;
    int end;
    int size;
};
Pond stack1[20000];
int position1 = 0;
void push1(Pond pond) {
    stack1[position1] = pond;
    ++position1;
}
Pond pop1() {
    --position1;
    return stack1[position1];
}
bool exist1() {
    return 1 <= position1;
}
void printPond(Pond pond) {
    printf("(start, end, size) = (%d, %d, %d)\n", pond.start, pond.end, pond.size);
}

int main() {
    char c;
    int total = 0;
    for (int i = 0; scanf("%c", &c) != EOF; i++) {
        if (c == '\n') {
            break;
        }
        if (c == '\\') {
            push(i);
        } else if (c == '/') {
            if (exist()) {
                Pond pond;
                pond.start = pop();
                pond.end = i;
                pond.size = pond.end - pond.start;
                total += pond.size;
                while (exist1()) {
                   Pond oldPond = pop1();
                   if (oldPond.end < pond.start) {
                       push1(oldPond);
                       break;
                   }
                   pond.size += oldPond.size;
                }
                push1(pond);
            }
        }
    }
    printf("%d\n", total);
    printf("%d", position1);
    for (int i = 0; i < position1; i++) {
        Pond pond = stack1[i];
        printf(" %d", pond.size);
    }
    printf("\n");
}
