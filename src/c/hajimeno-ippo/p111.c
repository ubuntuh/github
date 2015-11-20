#include <stdio.h>
int main() {
    char target[20] = "count";
    int len;
    for (len = 0; target[len] != 0; len++) {
        ;
    }
    printf("The length of the word %s is %d.\n", target, len);
}

