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

int main(int argc, char** argv) {
    setDebugMode(argc, argv);
    p("Debug Mode (isDebug == %d)\n", isDebug);
}
