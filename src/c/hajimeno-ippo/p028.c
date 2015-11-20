#include <stdio.h>

int main() {
    int i;
    char w[16] = "Welcome to GCC!";
    for (i = 0; i < 10; i++) {
        printf("%2d %s\n", i, w);
    }
}

