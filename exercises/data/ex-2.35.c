#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int tmult_ok(int x, int y) {
    int p = x * y;
    return !x || p/x == y;
}

int tmult_ok_2(int x, int y) {
    int64_t res_64 = (int64_t)x * (int64_t)y;
    return (int32_t)res_64 ==  res_64;
}

int main() {
    printf("%d", tmult_ok_2(21, 21));
}