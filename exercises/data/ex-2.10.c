#include <stdio.h>
#include <stdlib.h>

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    printf("%d ", *x);
    printf("%d\n", *y);
    *x = *x ^ *y;
    printf("%d ", *x);
    printf("%d\n", *y);
    *y = *x ^ *y;
    printf("%d ", *x);
    printf("%d", *y);
}


int main() {
    int x = 1;
    int y = 2;
    inplace_swap(&x, &y);
}


