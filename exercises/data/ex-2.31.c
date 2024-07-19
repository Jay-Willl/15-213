#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int tadd_ok(int x, int y) {
    int sum = x + y;
    return (sum - x == y) && (sum - y == x);
}

int main() {
    int x = -2147483647;
    int y = -2147483647;
    printf("result: %d\n", tadd_ok(x, y));
    printf("sum: %d\n", x + y);
    printf("sum: 0x%x\n", x + y);
    printf("x: 0x%x\n", x);
    printf("y: 0x%x\n", y);
}