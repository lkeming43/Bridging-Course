#include<stdio.h>

int main()
{
    int num, count = 0;
    int mask = 1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while(num>0)
    {
        if((num & mask) == 0) count++;
        num = num >> 1;
    }

    if((count & 1) == 1) printf("\nNumber of 0-bits is odd.");

    else printf("\nNumber of 0-bits is even.");



    return 0;
}