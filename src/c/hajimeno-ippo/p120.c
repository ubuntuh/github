#include <stdio.h>
#include <string.h>
int main() {
    char target[20] = "count";
    char show[20], alphas[27];
    int len;
    
    // loop version
    for (len = 0; target[len] != 0; len++) {
        ;
    }
    printf("target = %s, length = %d\n", target, len);
    
    // strlen version
    len = strlen(target);
    
    memset(show, '_', len);
    show[len] = 0;
    memset(alphas, '*', 26);
    alphas[26] = 0;
    printf("  %s   [%s] ---> \n", show, alphas);
}

