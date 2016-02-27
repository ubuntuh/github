// Accepted.
#include <cstdio>
int main() {
    char c;
    scanf("%c", &c);
    switch (c) {
    case 'O':
    case 'P':
    case 'K':
    case 'L':
        puts("Right");
        return 0;
    }
    puts("Left");
    return 0;
}
