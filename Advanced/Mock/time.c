#include <stdio.h>

int multiply(int a, int b) 
{
    int result = 0;
    int negative = 0;

    if (a < 0) 
    {
        a = -a;
        negative = !negative;
    }

    if (b < 0) 
    {
        b = -b;
        negative = !negative;
    }

    while (b != 0) 
    {
        if (b & 1) 
        {
            result += a;
        }
        a <<= 1;
        b >>= 1;
    }

    return negative ? -result : result;
}

int main() {
    int x, y;
    printf("Enter 2 integers: ");
    scanf("%d %d", &x, &y);
    printf("%d * %d = %d\n", x, y, multiply(x, y));
    return 0;
}
