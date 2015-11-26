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

int callCreat(char *path, int perms);

int main() {
    callCreat("temp", 0664);
    return 0;
}
int callCreat(char *path, int perms) {
    int result;

    printf("Calling: int creat(char *path, int perms)\n");
    printf("  ファイルを作成します。\n");
    printf("  parameter path: 作成するファイルのパスです。\n");
    printf("  parameter perms: 作成するファイルのパーミッションです。\n");
    printf("  returns: 作成したファイルのファイル記述子です。ただしエラーの場合には -1 です。\n");
    printf("  argument path = %s\n", path);
    printf("  argument perms = %04o\n", perms);
    result = creat(path, perms);
    printf("  returned: %d\n", result);
    return result;
}

