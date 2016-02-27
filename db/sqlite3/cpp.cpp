// g++ example.cpp -lsqlite3
#include <cstdio>
#include <sqlite3.h>

int callback(void *arg1, int argc, char **argv, char **ss) {
    for (int i = 0; i < argc; ++i) {
        printf("%s = %s\n", ss[i], argv[i]);
    }
    return 0;
}

int main() {
    sqlite3 *db;
    char *errmsg;
    int result;
    result = sqlite3_open("test.sqlite3", &db);
    if (result) {
        printf("%s", sqlite3_errmsg(db));
    } else {
        char sql[] = "select * from t1";
        result = sqlite3_exec(db, sql, callback, 0, &errmsg);
    }
    sqlite3_close(db);
    return 0;
}
