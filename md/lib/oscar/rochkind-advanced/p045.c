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

#define BUFSIZE 512

void copy(char *from, char *to);
void syserr(char *msg);

int main(int argc, char *argv[]) {
    if (argc == 3)
        copy(argv[1], argv[2]);
    else
        printf("Failed. argc /= 3\n");
    return 0;
}
void copy(char *from, char *to) {
    int fromfd, tofd, nread;
    char buf[BUFSIZE];

    if ((fromfd = open(from, 0)) == -1)
        syserr(from);
    if ((tofd = creat(to, 0666)) == -1)
        syserr(to);
    while ((nread = read(fromfd, buf, sizeof(buf))) > 0)
        if (write(tofd, buf, nread) != nread)
            syserr("write");
    if (nread == -1)
        syserr("read");
    if (close(fromfd) == -1 || close(tofd) == -1)
        syserr("close");
}
void syserr(char *msg) {
    extern int errno, sys_nerr;
    extern const char *const sys_errlist[];

    fprintf(stderr, "ERROR: %s (%d", msg, errno);
    if (errno > 0 && errno < sys_nerr)
        fprintf(stderr, "; %s)\n", sys_errlist[errno]);
    else
        fprintf(stderr, ")\n");
    exit(1);
}

