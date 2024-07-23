#include <stdio.h>
#include <stdlib.h>

struct ELE {
    long v;
    struct ELE *p;
};

/*
ptr in %rdi

fun:
    movl $0, %eax
    jmp .L2
.L3:
    addq (%rdi), %rax
    movq 8(%rdi), %rdi
.L2:
    testq %rdi, %rdi
    jne .L3
    rep; ret
*/
long fun (struct ELE *ptr) {
    long result = 0;
    struct ELE *temp = ptr;
    while (temp != NULL) {
        result += temp->v;
        temp = temp->p;
    }
    
    return result;
}

int main () {
    // 分配内存
    struct ELE *p1 = (struct ELE*)malloc(sizeof(struct ELE));
    struct ELE *p2 = (struct ELE*)malloc(sizeof(struct ELE));
    
    // 检查内存分配是否成功
    if (p1 == NULL || p2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // 初始化结构体成员
    p2->v = 5;
    p2->p = NULL;
    p1->v = 4;
    p1->p = p2;

    // 调用函数并打印结果
    printf("%ld\n", fun(p1));

    // 释放内存
    free(p1);
    free(p2);

    return 0;
}