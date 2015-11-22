#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DICT "dict.sjis"
#define WORDS 2
#define ENG_LENGTH 20
#define JAP_LENGTH 90
#define ALPHABETS 26
#define LOOP 10
#define MAX_TRY 7

int main() {
    FILE *fd;
    int score = 0;
    int round;
    int try;
    int num_words;

    char words[WORDS][ENG_LENGTH];
    char hints[WORDS][JAP_LENGTH];
    char alphas[ALPHABETS+1];
    char show[ENG_LENGTH];

    int i, j;
    int line, len;
    char input[256];
    int match;
    char cc;

    fd = fopen(DICT, "r");
    if (fd == NULL) {
        printf("File could not be opened: %s\n", DICT);
        exit(1);
    }

    fgets(input, sizeof(input), fd);

    line = 0;
    while (fgets(input, sizeof(input), fd) != NULL) {
        for (i = 0; input[i] != ' '; i++) {
            words[line][i] = input[i];
        }
        words[line][i] = 0;
        for (j = i + 1; input[j] != '\n'; j++) {
            hints[line][j-i-1] = input[j];
        }
        hints[line][j-i-1] = 0;
        line++;
    }
    fclose(fd);
    num_words = line;
    srand(time(NULL));
    printf("Welcome to hangman.\n");
    printf("Enter '0' to quit.\n");
    for (round = 1; round <= LOOP; round++) {
        line = rand() % num_words;
        len = strlen(words[line]);
        printf("\n---- WORD #%d ------ score %d ----\n", round, score);
        printf("HINTS: %s   (%d letters)\n", hints[line], len);
        memset(alphas, '*', ALPHABETS);
        alphas[ALPHABETS] = 0;
        memset(show, '_', len);
        show[len] = 0;

        try = 0;
        while (try < MAX_TRY) {
            printf("  %s   [%s] ---> ", show, alphas);
            fgets(input, sizeof(input), stdin);
            cc = input[0];
            if (cc == '0') {
                exit(0);
            }
            if ('A' <= cc && cc <= 'Z') {
                cc = cc + 32;
            }
            if (cc < 'a' || 'z' < cc) {
                printf("    Must be alphabet\n");
            } else if (alphas[cc - 'a'] != '*') {
                printf("    letter already used.\n");
            } else {
                alphas[cc - 'a'] = cc;
                match = 0;
                for (i = 0; i < len; i++) {
                    if (words[line][i] == cc) {
                        match = 1;
                        show[i] = cc;
                    }
                }
                if (match == 0) {
                    try++;
                    printf("    %d try to go\n", MAX_TRY - try);
                }
                match = 1;
                for (i = 0; i < len; i++) {
                    if (show[i] == '_') {
                        match = 0;
                        break;
                    }
                }
                if (match == 1) {
                    break;
                }
            }
        }
        if (try == MAX_TRY) {
            printf("    Missed: %s\n", words[line]);
        } else {
            printf("    Got it!!\n");
            score++;
        }
    }
    printf("\n======== Game Over =========\n");
    printf("Score: %d of %d\n", score, try);
}


