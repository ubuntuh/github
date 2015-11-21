#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fd;
    char input[256];
    char words[14374][20];
    char hints[14374][90];
    int line, i, j;
    
    fd = fopen("dict.sjis", "r");
    if (fd == NULL) {
        printf("File not found. Program terminated.\n");
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
    for (i = 0; i < line; i++) {
        printf("%d: %s ==> %s\n", i, words[i], hints[i]);
    }
}

