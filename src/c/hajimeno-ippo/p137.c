#include <stdio.h>
int main() {
    char input[10];
    fgets(input, 10, stdin);
    printf("%s", input);
}

