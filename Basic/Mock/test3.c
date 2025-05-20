#include<stdio.h>

int main()
{
    int num,num1,check,digit;
    printf("\nEnter a positive integer: ");
    scanf("%d", &num);
    check = 0;
    num1 = num;

    while(num > 0)
    {
        digit = num%10;
        num = num / 10;
        check = check + digit*digit*digit;
    }

    if(check == num1) printf("\n%d is an Armstrong number.", num1);
    else printf("\n%d is not an Armstrong number. ", num1);

    return 0;
}
