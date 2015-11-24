#include <stdio.h>

int romanize(int i, int j, char c) {
    while (i >= j) {
        putchar(c);
        i = i - j;
    }
    return i;
}
int main() {
    int a = 1776;

    a = romanize(a, 1000, 'm');
    a = romanize(a, 500, 'd');
    a = romanize(a, 100, 'c');
    a = romanize(a, 50, 'l');
    a = romanize(a, 10, 'x');
    a = romanize(a, 5, 'v');
    romanize(a, 1, 'i');
    putchar('\n');
}

