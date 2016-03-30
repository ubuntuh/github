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
            result = vprintf(fmt, args);
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

void insertionSort(int* array, int size) {
    int i, j, value;
    printArray(array, size);
    for (i = 1; i < size; i++) {
        value = array[i];
        // value を array[0] から array[i - 1] の中で適切な位置に移動します。
        p("i: %d; value: %d\n", i, value);
        j = i - 1;
        while (0 <= j && value < array[j]) {
            p("j: %d\n", j);
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = value;
        printArray(array, size);
    }
}

int main(int argc, char** argv) {
    int *array, i, size;
    setDebugMode(argc, argv);
    p("Debug Mode (isDebug == %d)\n", isDebug);
    std::scanf("%d", &size);
    p("size: %d\n", size);
    array = new int[size];
    for (i = 0; i < size; i++) {
        std::scanf("%d", &array[i]);
    }
    p("data: ");
    for (i = 0; i < size; i++) {
        p("%d ", array[i]);
    }
    p("\n");
    insertionSort(array, size);
    return 0;
}
