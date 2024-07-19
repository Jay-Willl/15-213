#include <stdio.h>
#include <limits.h>

int main() {
    unsigned u = 4294967295u;
    int tu = (int) u;
    int itu = u;

    printf("u: %u\n", u);
    printf("tu: %d\n", tu);
    printf("itu: %u\n", itu);
    printf("itu: %d\n", itu);

    int x = -1;
    unsigned y = 2147483648;
    printf("x = %u = %d\n", x, x);
    printf("y = %u = %d\n", y, y);

    int r1 = (-2147483647-1 == 2147483648U);
    int r2 = (-2147483647-1 < 2147483747);
    int r3 = (-2147483647-1U < 2147483747);
    printf("r1: %d\n", r1);
    printf("r2: %d\n", r2); 
    printf("r3: %d\n", r3); 

    short sx = -1;
    unsigned uy = sx;

    printf("uy: %u\n", uy);
}