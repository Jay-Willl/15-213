#include <stdio.h>
#include <stdlib.h>


int is_equal(int x, int y) {
    // !: 位运算
    // ~: 逻辑运算
    int result = !(x ^ y);
    return result;
}


int main() {
    printf("%d", is_equal(1, 2));
}