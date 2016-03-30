#include <cstdio>

int main() {
    int ints[3];
    scanf("%d %d %d", &ints[0], &ints[1], &ints[2]);
    int sorted[3];
    if (ints[0] <= ints[1]) {
        if (ints[0] <= ints[2]) {
            sorted[0] = ints[0];
            if (ints[1] <= ints[2]) {
                sorted[1] = ints[1];
                sorted[2] = ints[2];
            } else {
                sorted[1] = ints[2];
                sorted[2] = ints[1];
            }
        } else {
            sorted[0] = ints[2];
            sorted[1] = ints[0];
            sorted[2] = ints[1];
        }
    } else {
        if (ints[1] <= ints[2]) {
            sorted[0] = ints[1];
            if (ints[0] <= ints[2]) {
                sorted[1] = ints[0];
                sorted[2] = ints[2];
            } else {
                sorted[1] = ints[2];
                sorted[2] = ints[0];
            }
        } else {
            sorted[0] = ints[2];
            sorted[1] = ints[1];
            sorted[2] = ints[0];
        }
    }
    printf("%d %d %d\n", sorted[0], sorted[1], sorted[2]);
    return 0;
}
