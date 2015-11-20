#include <stdio.h>
#include <string.h>

int main() {
    int try;
    int len, i, match;
    char target[20] = "dictionary";
    char show[20], alphas[27];
    char cc, input[256];
    
    try = 0;
    len = strlen(target);
    memset(show, '_', len);
    show[len] = 0;
    memset(alphas, '*', 26);
    alphas[26] = 0;
    
    while (try < 7) {
        printf("  %s   [%s] ---> ", show, alphas);
        fgets(input, sizeof(input), stdin);
        cc = input[0];
        if ('A' <= cc && cc <= 'Z') {
            cc += 32;
        }
        if (cc < 'a' || 'z' < cc) {
            printf("    Must be an alphabet.\n");
        } else if (alphas[cc-'a'] != '*') {
            printf("    letter already used.\n");
        } else {
            alphas[cc-'a'] = cc;
            match = 0;
            for (i = 0; i < len; i++) {
                if (target[i] == cc) {
                    show[i] = cc;
                    match = 1;
                }
            }
            if (match == 0) {
                try++;
                printf("    %d try to go.\n", 7 - try);
            }
            match = 1;
            for (i = 0; i < len; i++) {
                if (show[i] == '_') {
                    match = 0;
                }
            }
            if (match == 1) {
                break;
            }
        }
    }
}

