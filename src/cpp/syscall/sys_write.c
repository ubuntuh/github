#include <sys/syscall.h>
#include <unistd.h>

int main(int argc, char** argv) {
    const char s[] = "hello, world\n";
    syscall(SYS_write, STDOUT_FILENO, s, sizeof(s) - 1);
    return 0;
}
