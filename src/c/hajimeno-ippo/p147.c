#include <stdio.h>

int main() {
    char input[256];
    char cc;
    int i;
    
    for (i = 0; i < 10; i++) {
        printf("#%d: Enter a char (and Enter) ==>", i);
        fgets(input, sizeof(input), stdin);
        cc = input[0];
        printf("  '%c' entered.\n", cc);
    }
}

