// C や C++ で assertion を行うために assert.h (cassert) がある。
// include してマクロを定義する前に NDEBUG を定義すると、リリースビルドとなり、assertion コードは無いのと同じになる。
// #define NDEBUG
#include <assert.h>
#include <stdio.h>
int main() {
    printf("input := ");
    int input;
    scanf("%d", &input);
    assert(1 <= input && input <= 10);
    printf("input = %d\n", input);
    return 0;
}
