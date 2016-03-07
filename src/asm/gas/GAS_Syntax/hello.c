// gcc -S -m32 hello.c
//   -> hello.s
// gcc -m32 hello.s
//   -> a.out

#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
