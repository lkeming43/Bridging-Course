#include<stdio.h>

int recur (int this1)
{
    static int sum=0;
    int remainder;

    if(this1==0) return 0;
    else
    {
        remainder = this1%10;
        sum = sum*10 + remainder;
        recur(this1/10);
    }

    return sum;
}

int main(void)
{
    int num,result;
    printf("Enter an integer ");
    scanf("%d",&num);

    result = recur(num);
    printf("\nReverse number is %d",result);

    return 0;
}
