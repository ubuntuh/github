#include <stdio.h>

int main(void) {
    int x;
    int no = 7;

    printf("0〜9の整数を当ててください。\n\n");
    printf("いくつでしょう: ");
    scanf("%d", &x);
    if (x > no)
        printf("\a大きいです。\n");
    else if (x < no)
        printf("\a小さいです。\n");
    else
        printf("正解です。\n");
    return 0;
}

