#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fd;
    char input[256];
    int count = 0;
    int len, maxlen = 0;
    
    fd = fopen("dict.sjis", "r");
    if (fd == NULL) {
        printf("File not found. Program terminated.");
        exit(1);
    }
    fgets(input, sizeof(input), fd);
    len = strlen(input);
    if (maxlen < len) {
        maxlen = len;
    }
    while (fgets(input, sizeof(input), fd) != NULL) {
        len = strlen(input);
        if (maxlen < len) {
            maxlen = len;
        }
        printf("%s", input);
        count++;
    }
    fclose(fd);
    printf("--- words=%d, maxlen=%d\n", count, maxlen);
}

