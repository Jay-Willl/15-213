#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int uadd_ok(unsigned x, unsigned y) {
    printf("length of unsigned: %lu\n", sizeof(unsigned));
    printf("length of int: %lu\n", sizeof(int));
    unsigned res = x + y;
    printf("res: %lu\n", res);
    if (res < x || res < y) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    uadd_ok((unsigned)1, (unsigned)2);
    printf("result: %d", uadd_ok(2147483647, 2147483647));
}