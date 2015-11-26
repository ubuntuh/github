#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "defs.h"

#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int callOpen(char *path, int flags);
int callClose(int fd);

int main() {
    int fd;
    
    fd = callOpen("temp", 2);
    if (fd != -1) {
        callClose(fd);
    }
    return 0;
}
int callOpen(char *path, int flags) {
    int result;
    
    printf("Calling: int open(char *path, int flags)\n");
    printf("  ファイルを開きます。\n");
    printf("  parameter path: 開くファイルのパスです。\n");
    printf("  parameter flags: 読み書きのフラグです。0 の場合には読み出し専用、1 の場合には書き込み専用、2 の場合には読み書き可能として開かれます。\n");
    printf("  returns: ファイル記述子です。ただし、エラーである場合には -1 を返します。\n");
    printf("  argument path = %s\n", path);
    printf("  argument flags = %d\n", flags);
    result = open(path, flags);
    printf("  returned: %d\n", result);
    return result;
}
int callClose(int fd) {
    int result;
    
    printf("Calling: int close(int fd)\n");
    printf("  ファイルを閉じます。\n");
    printf("  parameter fd: 閉じるファイルのファイル記述子です。\n");
    printf("  returns: 成功した場合には 0、エラーである場合には -1 を返します。\n");
    printf("  argument fd = %d\n", fd);
    /* warning: implicit declaration of function ‘close’ */
    result = close(fd);    
    printf("  returned: %d\n", result);
    return result;
}

