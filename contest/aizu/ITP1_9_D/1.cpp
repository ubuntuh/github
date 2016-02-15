#include <cstdio>
#include <cstring>
char command[11], p[1001], str[1001], temp[1001];
int a, b, q;
void print(void) {
    for (int i = a; i <= b; ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
}
void reverse(void) {
    int j = 0;
    for (int i = b; i >= a; --i) {
        temp[j] = str[i];
        ++j;
    }
    j = 0;
    for (int i = a; i <= b; ++i) {
        str[i] = temp[j];
        ++j;
    }
}
void replace(void) {
    int j = 0;
    for (int i = a; i <= b; ++i) {
        str[i] = p[j];
        ++j;
    }
}
int main() {
    scanf("%s", str);
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%s %d %d", command, &a, &b);
        if (! strcmp(command, "print")) print();
        else if (! strcmp(command, "reverse")) reverse();
        else {
            scanf("%s", p);
            replace();
        }
    }
    return 0;
}
