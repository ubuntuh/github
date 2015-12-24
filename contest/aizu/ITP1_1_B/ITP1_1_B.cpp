#include <cmath>
#include <cstdio>

static int getValue(int x);

int main(int argc, char *argv[]) {
    int x;
    std::scanf("%d", &x);
    std::printf("%d\n", getValue(x));
    return 0;
}

static int getValue(int x) {
    return std::pow(x, 3);
}
