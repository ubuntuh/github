#include <cstdarg>
#include <cstdio>
#include <string>

namespace {
    bool isDebug = false;
    void setDebugMode(int argc, char** argv) {
        int i;
        for (i = 1; i < argc; i++) {
            if (std::string(argv[i]) == "--debug") {
                isDebug = true;
                break;
            }
        }
    }
    int p(const char* fmt, ...) {
        va_list args;
        int result;
        if (isDebug) {
            va_start(args, fmt);
            result = std::vprintf(fmt, args);
            va_end(args);
            return result;
        } else {
            return 0;
        }
    }
}

void printArray(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        std::printf("%d", array[i]);
        if (i < size - 1) {
            std::printf(" ");
        } else {
            std::printf("\n");
        }
    }
}

int bubbleSort(int* array, int size) {
    bool flag = true;
    int j, temp, numSwap = 0;
    while (flag) {
        flag = false;
        for (j = size - 1; 1 <= j; j--) {
            if (array[j] < array[j - 1]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                numSwap++;
                flag = true;
            }
        }
    }
    return numSwap;
}

int main(int argc, char** argv) {
    int *array, i, size;
    int numSwap;
    setDebugMode(argc, argv);
    p("Debug Mode (isDebug == %d)\n", isDebug);
    std::scanf("%d", &size);
    array = new int[size];
    for (i = 0; i < size; i++) {
        std::scanf("%d", &array[i]);
    }
    numSwap = bubbleSort(array, size);
    printArray(array, size);
    std::printf("%d\n", numSwap);
    return 0;
}
