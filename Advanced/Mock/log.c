#include<stdio.h>

int log2_power_of_two(unsigned int n) {
    int result = 0;
    if (n & 0xFFFF0000) result += 16, n >>= 16;
    if (n & 0x0000FF00) result += 8,  n >>= 8;
    if (n & 0x000000F0) result += 4,  n >>= 4;
    if (n & 0x0000000C) result += 2,  n >>= 2;
    if (n & 0x00000002) result += 1;
    return result;
}


int main()
{
    unsigned num;
    printf("Enter a num: ");
    scanf("%u", &num);

    num = log2_power_of_two(num);

    printf("\n%u",num);

    return 0;
}