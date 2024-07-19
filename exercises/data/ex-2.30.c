#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int tadd_ok(int x, int y) {
    printf("length of int: %lu\n", sizeof(int));
    int res = x + y;
    if ((x > 0 && y > 0 && res <=0) || (x < 0 && y < 0 && res >= 0)) {
        return 0;
    }
    return 1;
}

int main() {
    printf("result: %d", tadd_ok(-2147483647, 2147483647));
}