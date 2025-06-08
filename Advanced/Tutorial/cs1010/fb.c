#include <stdio.h>

int fib(int n) {
    printf("%d ", n);
    return (n <= 1 ? n : fib(n - 1) + fib(n - 2));
}

int main() {
    int n = 4;
    int result = fib(n);
    printf("\nFibonacci(%d) = %d\n", n, result);
    return 0;
}
