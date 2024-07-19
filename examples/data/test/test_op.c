#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
    int tmax = ~(0x1 << 31);
    printf("tmax: %x\n", tmax);
    printf("is equal: %d\n", tmax == INT_MAX);

    int flow = 0x0 - 0x1;
    printf("flow: %x\n", flow);

    int result = INT_MAX - INT_MIN;
    printf("result: %x\n", result);

    long result2 = (long)INT_MIN - (long)INT_MAX;
    printf("result2: %lx\n", result2);


}