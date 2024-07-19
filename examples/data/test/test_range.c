#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <inttypes.h>

int main() {
    // printf("Minimum value for signed char: %d\n", SCHAR_MIN);
    // printf("Maximum value for signed char: %d\n", SCHAR_MAX);
    // printf("Minimum value for unsigned char: %d\n", 0);
    // printf("Maximum value for unsigned char: %u\n", UCHAR_MAX);
    // printf("Minimum value for int: %d\n", INT_MIN);
    // printf("Maximum value for int: %d\n", INT_MAX);

    // uint32_t n1 = 1;
    // int64_t n2 = 12345671234567LL;
    // printf("n1: %"PRIu32"\n", n1);
    // printf("n2: %"PRId64"\n", n2);


    // test calculate MIN
    int r1 = -1 + INT_MIN;  // flow
    int r2 = + INT_MIN;  // normal
    int r3 = 1 + INT_MIN;  // normal
    int p1 = -1 - INT_MIN;  //  normal
    int p2 = - INT_MIN;  // flow
    int p3 = 1 - INT_MIN;  // flow
    
    printf("%d\n", r1);
    printf("r1 in hex: %x\n", r1);
    printf("%d\n", r2);
    printf("r2 in hex: %x\n", r2);
    printf("%d\n", r3);
    printf("r3 in hex: %x\n", r3);
    printf("\n");
    printf("%d\n", p1);
    printf("p1 in hex: %x\n", p1);
    printf("%d\n", p2);
    printf("p2 in hex: %x\n", p2);
    printf("%d\n", p3);
    printf("p3 in hex: %x\n", p3);
    
    return 0;
}