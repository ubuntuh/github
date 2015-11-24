#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

static void help() {
    printf("a  change access time\n");
    printf("f  new file name\n");
    printf("m  change modification time\n");
    printf("o  change owner\n");
    printf("p  change permissions\n");
    printf("q  quit\n");
    printf("s  display status\n");
    printf("!  execute UNIX command\n");
    printf("?  display command summary\n");
}
static void syserrmsg(char *msg) {
    extern int errno, sys_nerr;
//    extern char *sys_errlist[];

    fprintf(stderr, "ERROR: %s (%d", msg, errno);
    if (errno > 0 && errno < sys_nerr)
        fprintf(stderr, "; %s)\n", sys_errlist[errno]);
    else
        fprintf(stderr, ")\n");
}
static void dspstatus(struct stat *sbp) {
//    BOOLEAN isdevice = FALSE;
    int isdevice = 0;
    struct passwd *pw, *getpwuid();
    struct group *gr, *getgrgid();
    char *name, *asctime();
    struct tm * localtime();

    if ((sbp->st_mode & S_IFMT) == S_IFDIR)
        printf("Directory\n");
    else if ((sbp->st_mode & S_IFMT) == S_IFBLK) {
        printf("Block special file\n");
        isdevice = 1;
    } else if ((sbp->st_mode & S_IFMT) == S_IFCHR) {
        printf("Character special file\n");
        isdevice = 1;
    } else if ((sbp->st_mode & S_IFMT) == S_IFREG)
        printf("Ordinary file\n");
    else if ((sbp->st_mode & S_IFMT) == S_IFIFO)
        printf("FIFO\n");
    if (isdevice)
        printf("Device number: %d, %d\n", (sbp->st_rdev >> 8) & 0377, sbp->st_rdev & 0377);
    printf("Resides on devide: %d, %d\n", (sbp->st_rdev >> 8) & 0377, sbp->st_dev & 0377);
    printf("I-node: %d; Links: %d; Size: %d\n", sbp->st_ino, sbp->st_nlink, sbp->st_size);
    if ((pw = getpwuid(sbp->st_uid)) == NULL)
        name = "???";
    else
        name = pw->pw_name;
    printf("Owner ID: %d; Name: %s\n", sbp->st_uid, name);
    if ((gr = getgrgid(sbp->st_gid)) == NULL)
        name = "???";
    else
        name = gr->gr_name;
    printf("Group ID: %d; Name: %s\n", sbp->st_gid, name);
    if ((sbp->st_mode & S_ISUID) == S_ISUID)
        printf("Set-user-ID\n");
    if ((sbp->st_mode & S_ISGID) == S_ISGID)
        printf("Set-group-ID\n");
    if ((sbp->st_mode & S_ISVTX) == S_ISVTX)
        printf("Save swapped text after use\n");
    printf("Permissions: %o\n", sbp->st_mode & 0777);
    printf("Last access:            %s", asctime(localtime(&sbp->st_atime)));
    printf("Last modification:      %s", asctime(localtime(&sbp->st_mtime)));
    printf("Last status change:     %s", asctime(localtime(&sbp->st_ctime)));
}
static void status(char *path) {
    struct stat sb;

    if (stat(path, &sb) == -1) {
        syserrmsg("stat");
        return;
    }
    printf("\nFile \"%s\"\n", path);
    dspstatus(&sb);
}
static void prompt(char *msg, char *result) {
    printf("\n%s? ", msg);
    if (gets(result) == NULL)
        exit(0);
}
static void chtime(char *path, char which) {
    char atime[20];
    long seconds, timecvt();
    struct stat sb;
    struct utimbuf {
        time_t actime;
        time_t modtime;
    } tb;
    if (stat(path, &sb) == -1) {
        syserrmsg("stat");
        return;
    }
    prompt("Time (YYMMDDhhmmss)", atime);
//    if ((seconds = timecvt(atime)) <= 0)
//        return;
    switch (which) {
    case 'a':
        tb.actime = seconds;
        tb.modtime = sb.st_mtime;
        break;
    case 'm':
        tb.actime = sb.st_atime;
        tb.modtime = seconds;
    }
    if (utime(path, &tb) == -1)
        syserrmsg("utime");
}
static void chowner(char *path) {
    char oname[20], gname[20];
    int owner, group;
    struct passwd *pw, *getpwnam();
    struct group *gr, *getgrnam();

    prompt("Owner name", oname);
    if ((pw = getpwnam(oname)) == NULL) {
        printf("Unknown name\n");
        return;
    }
    owner = pw->pw_uid;
    prompt("Group name", gname);
    if ((gr = getgrnam(gname)) == NULL) {
        printf("Unknown name\n");
        return;
    }
    group = gr->gr_gid;
    if (chown(path, owner, group) == -1)
        syserrmsg("chown");
}
static void chperms(char *path) {
    char smode[20];
    int mode;

    prompt("Mode (up to 4 octal digits)", smode);
    if (sscanf(smode, "%o", &mode) != 1) {
        printf("Invalid mode\n");
        return;
    }
    if (chmod(path, mode) == -1)
        syserrmsg("chown");
}
static void mainloop() {
    char path[50], cmd[10], shcmd[100];
    while (1) {
        prompt("Command", cmd);
        if (strlen(cmd) > 1)
            cmd[0] = '\1';
        switch (cmd[0]) {
        case '\0':
        case 'q':
            exit(0);
        case 'a':
        case 'm':
            chtime(path, cmd[0]);
            continue;
        case 'f':
            prompt("File", path);
            if (access(path, 0) == -1) {
                printf("%s nonexistent\n", path);
                continue;
            }
            status(path);
            continue;
        case 'o':
            chowner(path);
            continue;
        case 'p':
            chperms(path);
            continue;
        case 's':
            status(path);
            continue;
        case '!':
            prompt("Shell command", shcmd);
            system(shcmd);
            continue;
        case '?':
            help();
            continue;
        default:
            printf("Unknown command; use ? for help");
            continue;
        }
    }
}
int main() {
    setbuf(stdout, NULL);
    help();
    mainloop();
}

