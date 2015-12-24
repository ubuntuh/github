#include <cstdio>

int main(int argc, char** argv) {
    int i;
    std::printf("argc: %d\n", argc);
    for (i = 0; i < argc; i++) {
        std::printf("argv[%d]: %s\n", i, argv[i]);
    }
    return 0;
}
