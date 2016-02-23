#include <cstdio>
#include <cstring>
#define HASH_SIZE 1046527
char command[7 + 1], key[12 + 1], keys[HASH_SIZE][12 + 1];
int n;
int getChar(char c) {
    switch (c) {
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
    }
}
long getKey(char *str) {
    long sum = 0, pow = 1;
    for (int i = 0;; ++i) {
        if (str[i] == '\0') return sum;
        sum += pow * getChar(str[i]);
        pow *= 4;
    }
}
int h1(int key) { return key % HASH_SIZE; }
int h2(int key) { return 1 + (key % (HASH_SIZE - 1)); }
int h(int key, int jump) {
    return (h1(key) + jump * h2(key)) % HASH_SIZE;
}
void printData() {
    puts("data =");
    for (int i = 0; i < HASH_SIZE; ++i) {
        if (keys[i][0] != '\0') printf("    array[%d] = %s\n", i, keys[i]);
    }
}
void insert(char *str) {
    long key;
    key = getKey(str);
    for (int i = 0;; ++i) {
        int value = h(key, i);
        if (keys[value][0] == '\0') {
            strcpy(keys[value], str);
            return;
        } else if (! strcmp(keys[value], str)) return;
    }
}
bool find(char *str) {
    long key;
    key = getKey(str);
    for (int i = 0;; ++i) {
        int value = h(key, i);
        if (keys[value][0] == '\0') return false;
        if (! strcmp(keys[value], str)) {
            return true;
        }
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
