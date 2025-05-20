#include<stdio.h>

int fib(int n);

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d",&n);
    printf("\nResult = %d",fib(n));

    return 0;
}

int fib(int n)
{
    int i;
    if(n==1 || n==2) return 1;
       
    else
    {
        return fab(n-1) + fab(n-2);
    }
}