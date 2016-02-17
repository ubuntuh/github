#include <cstdio>
void f1(void) { printf("f1\n"); }
void f2(void) { printf("f2\n"); }
void f3(void) { printf("f3\n"); }
void recursion(int i) {
    printf("recursion #%d - &argument = %p\n", i, (void*) &i);
    if (--i) recursion(i);
}
int main(int argc, char **argv) {
    printf("sizeof(char)          = %ld\n", sizeof(char));
    printf("sizeof(short int)     = %ld\n", sizeof(short int));
    printf("sizeof(int)           = %ld\n", sizeof(int));
    printf("sizeof(long int)      = %ld\n", sizeof(long int));
    printf("sizeof(long long int) = %ld\n", sizeof(long long int));
    printf("sizeof(float)         = %ld\n", sizeof(float));
    printf("sizeof(double)        = %ld\n", sizeof(double));
    printf("sizeof(long double)   = %ld\n", sizeof(long double));
    int v1 = 1;
    int v2 = 2;
    int v3 = 3;
    printf("int v1; &v1 = %p\n", (void*) &v1);
    printf("int v2; &v2 = %p\n", (void*) &v2);
    printf("int v3; &v3 = %p\n", (void*) &v3);
    printf("int main(int, char**); main = %p\n", (void*) main);
    printf("void f1(void); f1 = %p\n", (void*) f1);
    printf("void f2(void); f2 = %p\n", (void*) f2);
    printf("void f3(void); f3 = %p\n", (void*) f3);
    recursion(3);
}
