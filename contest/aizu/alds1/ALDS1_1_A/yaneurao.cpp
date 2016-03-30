// http://d.hatena.ne.jp/yaneurao/20091126
// 広く知られているinsertion sortのコードは駄目すぎる
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
using namespace std;

long getTime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec * 1000000 + t.tv_usec;
}

#define SIZE 10000

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d)", i, array[i]);
        if (i < size - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
}

void wikipediaJp(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int tmp = array[i];
        int j;
        for (j = i; j > 0 && array[j - 1] > tmp; j--) {
            array[j] = array[j - 1];
        }
        array[j] = tmp;
    }
}

void wikipediaEn(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = tmp;
    }
}

void wikipediaFr(int* array, int size) {
    int i, p, j, x;
    for (i = 1; i < size; i++) {
        x = array[i];
        p = i - 1;
        while (array[p] > x && p-- > 0) {}
        p++;
        for (j = i - 1; j >= p; j--) {
            array[j + 1] = array[j];
        }
        array[p] = x;
    }
}

void yaneuraoInsertionSort1(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int tmp = array[i];
        if (array[i - 1] > tmp) {
            int j = i;
            do {
                array[j] = array[j - 1];
                --j;
            } while (j > 0 && array[j - 1] > tmp);
            array[j] = tmp;
        }
    }
}

void yaneuraoInsertionSort2(int* array, int size) {
    array[0] = INT_MIN; // sentinel value
    // 実験を簡単にするため、本来許されないが、array[0] にあった値を捨てた。
    for (int i = 2; i < size; i++) {
        int tmp = array[i];
        if (array[i - 1] > tmp) {
            int j = i;
            do {
                array[j] = array[j - 1];
                --j;
            } while (array[j - 1] > tmp);
            array[j] = tmp;
        }
    }
}

void init(int* array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
}

int main() {
    long before, after;
    int array[SIZE];

    bool sorted = true;
    init(array, SIZE);
    before = getTime();
    wikipediaJp(array, SIZE);
    after = getTime();
    printf("%ld usec (wikipediaJp)\n", after - before);
    if (sorted) {
        before = getTime();
        wikipediaJp(array, SIZE);
        after = getTime();
        printf("    %ld usec (for sorted input)\n", after - before);
    }

    init(array, SIZE);
    before = getTime();
    wikipediaEn(array, SIZE);
    after = getTime();
    printf("%ld usec (wikipediaEn)\n", after - before);
    if (sorted) {
        before = getTime();
        wikipediaEn(array, SIZE);
        after = getTime();
        printf("    %ld usec (for sorted input)\n", after - before);
    }
    
    init(array, SIZE);
    before = getTime();
    wikipediaFr(array, SIZE);
    after = getTime();
    printf("%ld usec (wikipediaFr)\n", after - before);
    if (sorted) {
        before = getTime();
        wikipediaFr(array, SIZE);
        after = getTime();
        printf("    %ld usec (for sorted input)\n", after - before);
    }
    
    init(array, SIZE);
    before = getTime();
    yaneuraoInsertionSort1(array, SIZE);
    after = getTime();
    printf("%ld usec (yaneuraoInsertionSort1)\n", after - before);
    if (sorted) {
        before = getTime();
        yaneuraoInsertionSort1(array, SIZE);
        after = getTime();
        printf("    %ld usec (for sorted input)\n", after - before);
    }

    init(array, SIZE);
    before = getTime();
    yaneuraoInsertionSort2(array, SIZE);
    after = getTime();
    printf("%ld usec (yaneuraoInsertionSort2)\n", after - before);
    if (sorted) {
        before = getTime();
        yaneuraoInsertionSort2(array, SIZE);
        after = getTime();
        printf("    %ld usec (for sorted input)\n", after - before);
    }
}
