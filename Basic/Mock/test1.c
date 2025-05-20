#include<stdio.h>
#include<math.h>

int main()
{
    int num, base, digit, new, times;
    printf("Enter the base-10 number to be converted: ");
    scanf("%d", &num);
    printf("\nEnter the base to be converted to: ");
    scanf("%d", &base);
    times = 0;
    new = 0;

    while(num != 0)
    {
        digit = num % base;
        num = num / base;
        new = new + digit*pow(10,times);
        times++;
    }

    printf("\n%d <base-10> = %d <base-%d>", num, new, base);

    return 0;
}