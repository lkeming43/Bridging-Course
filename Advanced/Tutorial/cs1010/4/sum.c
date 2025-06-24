#include<stdio.h>

int sumDigits(int n);

int main()
{
    printf("%d", sumDigits(12034));
}

int sumDigits(int n)
{
    if(n == 0) return 0;

    else 
    {
        if(n%10%2) return n%10 + sumDigits(n/10);
        else return 1 + n%10 + sumDigits(n/10);
    }
}