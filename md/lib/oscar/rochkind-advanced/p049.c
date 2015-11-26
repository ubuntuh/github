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

int callUnlink(char *path);

int main() {
    callUnlink("temp");
    return 0;
}
int callUnlink(char *path) {
    int result;
    
    printf("Calling: int unlink(char *path)\n");
    printf("  与えられたパスから i ノードへのリンクを除去します。結果的に、当該 i ノードのリンクカウントが 0 になった場合、そのファイルは削除されます。\n");
    printf("  parameter path: 削除するファイルのパスです。\n");
    printf("  returns: 成功した場合は 0、エラーである場合には -1 を返します。\n");
    printf("  argument path = %s\n", path);
    /* warning: implicit declaration of function ‘unlink’ */
    result = unlink(path);
    printf("  returned: %d\n", result);
    return result;
}

