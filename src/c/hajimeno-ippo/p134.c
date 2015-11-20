#include <stdio.h>
#include <string.h>
int main() {
    char input[6] = "abcdx";
    char target[20] = "count";
    char show[20], alphas[27];
    char cc;
    int len;
    int i, j;
    len = strlen(target);
    memset(show, '_', len);
    show[len] = 0;
    memset(alphas, '*', 26);
    alphas[26] = 0;
    for (i = 0; input[i] != 0; i++) {
        cc = input[i];
        printf("  %s   [%s] ---> %c\n", show, alphas, cc);
        alphas[cc-'a'] = cc;
        for (j = 0; j < len; j++) {
            if (cc == target[j]) {
                show[j] = cc;
            }
        }
    }
}

