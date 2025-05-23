#include<stdio.h>

int main()
{
    int num,temp;

    printf("Enter a number to check: ");
    scanf("%d", &num);

    temp = num;

    while(num>=128)
    {
        if(num == 128) 
        {
            printf("\n%d is a multiple of 128.", temp);
            break;
        }

        num = num >> 1;

    }

    if(num < 128) printf("\n%d is not a multiple of 128.", temp);

    return 0;
}