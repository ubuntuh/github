#include <cstdio>
#include <cstring>
#define HASH_SIZE 1000000
char command[7 + 1], key[12 + 1], keys[HASH_SIZE][12 + 1];
int n;
void printData() {
    puts("data =");
    for (int i = 0; i < HASH_SIZE; ++i) {
        if (keys[i][0] != '\0') printf("    array[%d] = %s\n", i, keys[i]);
    }
}
int hash(char *str) {
    unsigned int value = 0;
    for (int i = 0;; ++i) {
        if (str[i] == '\0') return value % HASH_SIZE;
        value += str[i] * (i * 12345);
    }
}
int rehash(int h) {
    return (h + 54321) % HASH_SIZE;
}
void insert(char *str) {
    int value = hash(str);
    while (keys[value][0] != '\0') {
        value = rehash(value);
    }
    strcpy(keys[value], str);
    // printData();
}
bool find(char *str) {
    int value = hash(str);
    while (1) {
        if (keys[value][0] == '\0') return false;
        if (! strcmp(keys[value], str)) {
            return true;
        }
        value = rehash(value);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s%s", command, key);
        // printf("command, key = %s, %s\n", command, key);
        if (command[0] == 'i') insert(key);
        else if (command[0] == 'f') {
            bool result = find(key);
            if (result) puts("yes");
            else puts("no");
        } else {
            puts("Error: command not defined.");
        }
    }
    return 0;
}
