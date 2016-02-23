#include <cstdio>
int X, Y;
int main() {
    scanf("%d%d", &X, &Y);
    if (X < Y) X = Y;
    printf("%d\n", X);
}
