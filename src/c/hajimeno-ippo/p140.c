#include <stdio.h>
int main() {
    char input[10];
    fgets(input, 10, stdin);
    printf("INPUT1: %sEND\n", input);
    fgets(input, 10, stdin);
    printf("INPUT2: %sEND\n", input);
}

