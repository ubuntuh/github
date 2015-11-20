#include <stdio.h>
#include <string.h>
int main() {
    char target[20] = "count";
    int len;
    len = strlen(target);
    printf("The length of the word %s is %d.\n", target, len);
}

