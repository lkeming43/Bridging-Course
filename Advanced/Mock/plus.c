#include<stdio.h>

int main()
{
    int a, b, carry = 0;
    int result = 0;
    int bit = 1;

    printf("Enter 2 integers: ");
    scanf("%d%d", &a, &b);

    while(a != 0 || b != 0 || carry != 0)
    {
        int abit = a & 1;
        int bbit = b & 1;

        int sum = abit ^ bbit ^ carry;
        carry = (abit & bbit) | (abit & carry) | (bbit & carry);

        result |= (sum * bit);

        bit <<= 1;
        a >>= 1;
        b >>= 1;
    }

    printf("\nResult = %d", result);

    return 0;
}

/*recursion
uint32_t add(uint32_t a, uint32_t b)
{
    if ((a & b) == 0)
        return a | b;
    else 
        return add((a & b) << 1, a ^ b);
}*/
