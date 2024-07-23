#include <stdio.h>

#define N 3
typedef int fix_matrix [N][N];

int fix_prod_ele (fix_matrix A, fix_matrix B, long i, long k) {
    long j;
    int result = 0;

    for (j = 0; j < N; j++) {
        result += A[i][j] * B[j][k];
    }

    return result;
}


// optimized version of fix_prod_ele
// optimize address 
// optimize loop statement
int fix_prod_ele_opt (fix_matrix A, fix_matrix B, long i, long k) {
    long j = 0;
    long result = 0;

    int * Aptr = &A[i][0];
    int * Bptr = &B[0][k];
    int * Bend = &B[N][k];

    do {
        result += *Aptr * *Bptr;
        Aptr += 1;
        Bptr += N;
    } while (Bptr != Bend);
    
    return result;
}

int main() {
    fix_matrix A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    fix_matrix B = {3, 3, 3, 3, 3, 3, 3, 3, 3};

    printf("%d\n", fix_prod_ele(A, B, 0, 0));
    printf("%d\n", fix_prod_ele_opt(A, B, 0, 0));
}