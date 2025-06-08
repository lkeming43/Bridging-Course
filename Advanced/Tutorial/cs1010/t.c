#include <stdio.h>

int main() {
    int a[] = {0, 1, 2, 3};
    int *p[] = {a, a + 1, a + 2, a + 3};  // p是指针数组，每个元素是int*
    int **ptr = p;                        // ptr指向p的第一个元素（int*）

    ptr++;  // 指向p[1]
    printf("%d %d %d\n", ptr - p, *ptr - a, **ptr);
    // 输出: 1 1 1
    // ptr-p=1，*ptr=a+1，*ptr - a=1，**ptr=*(a+1)=1

    (*ptr)++;  // (*ptr) 指向的int指针 +1，原来是a+1，现在变a+2
    printf("%d %d %d\n", ptr - p, *ptr - a, **ptr);
    // 输出: 1 2 2
    // ptr-p仍是1，*ptr变成a+2，*ptr - a=2，**ptr=2

    *++ptr;  // ptr指向p[2]
    printf("%d %d %d\n", ptr - p, *ptr - a, **ptr);
    // 输出: 2 2 2
    // ptr-p=2，*ptr=a+2，*ptr - a=2，**ptr=2

    return 0;
}
