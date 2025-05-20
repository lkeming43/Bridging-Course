#include<stdio.h>

int main()
{
    int count = 0;
    int i;
    int mask = 1;
    int num;

    printf("Enter a number to check: ");
    scanf("%d", &num);

    while(num > 0)
    {
        count++;
        num = num & (num - 1);
    }

    printf("\nThere are %d '1' in this integer.", count);

    return 0;
}