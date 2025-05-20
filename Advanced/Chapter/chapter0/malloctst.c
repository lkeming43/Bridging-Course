#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char *this1;        // 字符指针（用于存储字符串）
    int *this2;         // 整数指针（用于存储整数）
    int size;           // 整数的大小
    
    // 动态分配15个字节的内存（足够存储字符串 "a234567890123b" 和一个空字符终止符）
    this1 = (char *) malloc(15);
    // 将字符串复制到分配的内存中
    strcpy(this1, "a234567890123b");
    
    // 打印字符串和它的地址
    printf("\nString = %s, Address = %p\n", this1, (void *)this1);

    // 获取整数的大小
    size = sizeof(int);
    
    // 动态分配3个整数的内存
    this2 = (int *) malloc(size * 3);
    
    // 给这3个整数赋值
    this2[0] = 55;
    this2[1] = 66;
    this2[2] = 77;
    
    // 打印整数和它们的地址
    printf("Integer = %d, Address = %p\n", this2[0], (void *)&this2[0]);
    printf("Integer = %d, Address = %p\n", this2[1], (void *)&this2[1]);
    printf("Integer = %d, Address = %p\n", this2[2], (void *)&this2[2]);

    // 释放动态分配的内存
    free(this1);
    free(this2);

    return 0;
}
