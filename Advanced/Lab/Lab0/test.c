#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *a = (int *)malloc(sizeof(int));
    int b = 20;

    *a = 20;

    printf("%d", a);
    printf("\n%d", *a);

    free(a);

    return 0;
}