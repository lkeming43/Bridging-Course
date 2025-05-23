#include<stdio.h>

void swap(int *a, int *b);

int main()
{
    int a, b;
    printf("Enter 2 numbers to swap: ");
    scanf("%d%d", &a, &b);

    printf("\n%d %d", a, b);
    swap(&a,&b);
    printf("\n%d %d", a, b);

    return 0;
}

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}