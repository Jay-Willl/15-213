#include <stdio.h>
#include <stdlib.h>

void inplace_swap(int *x, int *y) {
    if (*x == *y) {
        return;
    }
    *y = *x ^ *y;
    printf("%d ", *x);
    printf("%d | ", *y);
    *x = *x ^ *y;
    printf("%d ", *x);
    printf("%d | ", *y);
    *y = *x ^ *y;
    printf("%d ", *x);
    printf("%d\n", *y);
}

void reverse_array(int a[], int cnt) {
    for (int i = 0; i < cnt; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int first, last;
    for (first = 0, last = cnt - 1;
            first <= last;
            first++, last--) {
                printf("%d %d: ", a[first], a[last]);
                inplace_swap(&a[first], &a[last]);
            }

    for (int i = 0; i < cnt; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverse_array(arr, 5);
}