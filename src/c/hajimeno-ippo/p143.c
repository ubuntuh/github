#include <stdio.h>
int main() {
    char input[10];
    int result;
    
    fgets(input, 10, stdin);
    printf("in: %sEND\n", input);
    result = fseek(stdin, SEEK_END, 0);
    printf("result = %d\n", result);
    fgets(input, 10, stdin);
    printf("in: %sEND\n", input);
}

