#include <stdio.h>
int main() {
    int round = 1;
    int score = 0;
    printf("---- WORD #%d ------ score %d ----\n", 1, 0);
    while (round <= 10) {
        printf("---- WORD #%d ------ score %d ----\n", round, score);
        round++;
    }
    for (round = 1; round <= 10; round++) {
        printf("---- WORD #%d ------ score %d ----\n", round, score);
    }
}

