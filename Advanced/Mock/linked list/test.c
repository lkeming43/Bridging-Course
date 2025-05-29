
#include <stdio.h>

// 实现 a + b（只用 bitwise）
int add(int a, int b) {
    if ((a & b) == 0)
        return a ^ b;
    else 
        return add((a & b) << 1, a ^ b);
}

// 实现 a - b（即 a + (-b)）
int subtract(int a, int b) {
    return add(a, add(~b, 1));  // a + (~b + 1)
}

int main() {
    int x = 15, y = 9;
    printf("%d - %d = %d\n", x, y, subtract(x, y));

    x = 7, y = 20;
    printf("%d - %d = %d\n", x, y, subtract(x, y));

    return 0;
}
