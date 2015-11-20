#include <stdio.h>
#include <string.h>
int main() {
    char target[20] = "count";
    char show[20];
    int i, len;
    len = strlen(target);
    memset(show, '_', len);
    show[len] = 0;
    printf("target: %s\n", target);
    printf("show:   %s\n", show);
}

