#include <cstdio>
int main() {
    char c;
    while (scanf("%c", &c) != EOF) {
        switch (c) {
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o': break;
        default: printf("%c", c);
        }
    }
    return 0;
}
