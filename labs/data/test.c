#include <stdio.h>

int main() {
    int c = 0x80000000;
    int d = 0;
    printf("%x\n", c);
    printf("%x\n", !!c);
    printf("%x\n", !!c << 31 >> 31);
    printf("%x\n", c + d);
}