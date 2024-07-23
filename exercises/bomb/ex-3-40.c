#include <stdio.h>

#define N 3

typedef int fix_matrix [N][N];

void fix_set_diag (fix_matrix A, int val) {
    long i;
    for (i = 0; i < N; i++) {
        A[i][i] = val;
    }

    return;
}


void fix_set_diag_opt (fix_matrix A, int val) {
    long i = 0;
    int *Aptr = &A[0][0];
    int *Aend = &A[N][N];
    do {
        *Aptr = val;
        Aptr += (N + 1);
    } while (Aptr != Aend);

    return;
}

void print_fix_matrix(fix_matrix A) {
    int *Aptr = &A[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *Aptr);
            Aptr += 1;
        }
        printf("\n");
    }
    printf("\n");

    return;
}

int main () {
    fix_matrix A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_fix_matrix(A);
    fix_set_diag(A, 10);
    print_fix_matrix(A);
    fix_set_diag_opt(A, 20);
    print_fix_matrix(A);
}

