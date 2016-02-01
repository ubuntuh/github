#include <stdio.h>

int main() {
    printf("Standard Predefined Macros = ...\n");
    printf("    Current Input File __FILE__ = %s\n", __FILE__);
    printf("    Current Input Line __LINE__ = %d\n", __LINE__);
    printf("    Preprocessing Date __DATE__ = %s\n", __DATE__);
    printf("    Preprocessing Time __TIME__ = %s\n", __TIME__);
}
