/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

#define L (32 / sizeof(int))


int is_transpose(int M, int N, int A[N][M], int B[M][N]);
void trans(int M, int N, int A[N][M], int B[M][N]);
void trans_XxY(int M, int N, int A[N][M], int B[M][N], size_t X, size_t Y);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 8, 8);
}


char trans_desc[] = "cache ignorant implementation";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    
}

void trans_XxY(int M, int N, int A[N][M], int B[M][N], size_t X, size_t Y)
{
    size_t i, j, subi, subj;
    int tmp;

    for (i = 0; i < N; i += X) {
        for (j = 0; j < M; j += Y) {
            for (subi = i; subi < i + X; subi++) {
                for (subj = j; subj < j + Y; subj++) {
                    tmp = A[subi][subj];
                    B[subj][subi] = tmp;
                }
            }
        }
    }

    for (; i < N; i++) {
        for (; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }
}

char trans_2x2_desc[] = "Transpose | block size 2 * 2";
void trans_2x2(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 2, 2);
}

char trans_4x2_desc[] = "Transpose | block size 4 * 2";
void trans_4x2(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 4, 2);
}

char trans_2x4_desc[] = "Transpose | block size 2 * 4";
void trans_2x4(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 2, 4);
}

char trans_4x4_desc[] = "Transpose | block size 4 * 4";
void trans_4x4(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 4, 4);
}

char trans_8x4_desc[] = "Transpose | block size 8 * 4";
void trans_8x4(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 8, 4);
}

char trans_4x8_desc[] = "Transpose | block size 4 * 8";
void trans_4x8(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 4, 8);
}

char trans_8x8_desc[] = "Transpose | block size 8 * 8";
void trans_8x8(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 8, 8);
}

char trans_16x8_desc[] = "Transpose | block size 16 * 8";
void trans_16x8(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 16, 8);
}

char trans_8x16_desc[] = "Transpose | block size 8 * 16";
void trans_8x16(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 8, 16);
}

char trans_16x16_desc[] = "Transpose | block size 16 * 16";
void trans_16x16(int M, int N, int A[N][M], int B[M][N])
{
    trans_XxY(M, N, A, B, 16, 16);
}
/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    registerTransFunction(trans, trans_desc); 
    registerTransFunction(trans_2x2, trans_2x2_desc);
    registerTransFunction(trans_4x2, trans_4x2_desc);
    registerTransFunction(trans_2x4, trans_2x4_desc);
    registerTransFunction(trans_4x4, trans_4x4_desc);
    registerTransFunction(trans_8x4, trans_8x4_desc);
    registerTransFunction(trans_4x8, trans_4x8_desc);
    registerTransFunction(trans_8x8, trans_8x8_desc);
    registerTransFunction(trans_16x8, trans_16x8_desc);
    registerTransFunction(trans_8x16, trans_8x16_desc);
    registerTransFunction(trans_16x16, trans_16x16_desc);



}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

