#include <stdio.h>
#include <stdlib.h> 

// char array | 8 MB | 
char big_array[1l << 23];
// char array | 256 MB |
char huge_array[1l << 28];

// global int
int global_int = 1;

// function
int useless () {
    return 1;
}

int main() {
    // local int
    int local = 1;
    void *p1, *p2, *p3;

    // array on heap | 256 MB |
    p1 = malloc(1l << 28);

    // array on heap | 256 B |
    p2 = malloc(1l << 8);

    // array on heap | 1 GB |
    p3 = malloc(1l << 30);

    printf("big_array address:  %p, size: %lu MB\n", (void*)big_array, sizeof(big_array) >> 20);
    printf("huge_array address: %p, size: %lu MB\n", (void*)huge_array, sizeof(huge_array) >> 20);
    printf("global_int address: %p, value: %d\n", (void*)&global_int, global_int);
    printf("function address:   %p\n", (void*)useless);
    printf("local int address:  %p, value: %d\n", (void*)&local, local);

    if (p1) {
        printf("Heap array p1 address: %p, size: 256 MB\n", p1);
    } else {
        printf("Failed to allocate memory for p1\n");
    }

    if (p2) {
        printf("Heap array p2 address: %p, size: 256 B\n", p2);
    } else {
        printf("Failed to allocate memory for p2\n");
    }

    if (p3) {
        printf("Heap array p3 address: %p, size: 1 GB\n", p3);
    } else {
        printf("Failed to allocate memory for p3\n");
    }

    // Free the allocated memory
    free(p1);
    free(p2);
    free(p3);

    return 0;
}