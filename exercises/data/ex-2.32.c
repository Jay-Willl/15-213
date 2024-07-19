#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int tadd_ok(int x, int y) {
    // printf("y: %d\n", y);
    int res = x + y;
    if ((x > 0 && y > 0 && res <=0) || (x < 0 && y < 0 && res >= 0)) {
        return 0;
    }
    return 1;
}

int tsub_ok(int x, int y) {
    int res = x - y;
    if ((x >= 0 && y < 0 && res < 0) || (x <= 0 && y > 0 && res > 0)) {
        return 0;
    }
    return 1;
}

int tsub_ok_exp(int x, int y) {
    if (y == INT_MIN) {
        return -tadd_ok(x, -y);  // -y in [2^(w-1)-1, 2^(w-1)]
    } else {
        return tadd_ok(x, -y);  // -y in [-2^(w-1), 2^(w-1)-1]
    }
}

void print_info(int x, int y) {
    printf("x: %d | ", x);
    printf("y: %d\n", y);
    printf("in long: %ld | ", (long)x - (long)y);
    printf("in int: %d\n", x - y);
    printf("tsub_ok(x,y): %d | ", tsub_ok(x, y));
    printf("tadd_ok(x,-y): %d\n", tadd_ok(x, -y));
    printf("\n");
}

void check_result() {
    int range [] = {INT_MIN, -1, 0, 1, INT_MAX};
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (tsub_ok(range[i], range[j]) == tsub_ok_exp(range[i], range[j])) {
                continue;
            } else {
                print_info(range[i], range[j]);
            }
        }
    }
    printf("results are the same");
}

// return 0: no good
// return 1: good
int main() {
    // printf("expected\n");
    // printf("%d\n", tsub_ok(1, INT_MIN));
    // printf("%d\n", tsub_ok(0, INT_MIN));
    // printf("%d\n", tsub_ok(-1, INT_MIN));

    // printf("tadd_ok(x, -y)\n");
    // printf("%d\n", tadd_ok(1, -INT_MIN));
    // printf("%d\n", tadd_ok(0, -INT_MIN));
    // printf("%d\n", tadd_ok(-1, -INT_MIN));

    check_result();
}