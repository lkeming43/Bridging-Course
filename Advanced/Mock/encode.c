#include<stdio.h>

unsigned int encode(unsigned int num, int n);
unsigned int decode(unsigned int num, int n);
void print_binary(unsigned int n);


int main()
{
    unsigned int num, code;
    int n;
    printf("Enter an integer: ");
    scanf("%u", &num);
    printf("\nEnter the number to move: ");
    scanf("%d", &n);

    printf("\nThe number is: ");
    print_binary(num);
    code = encode(num, n);
    printf("\nAfter being encoded: %u ", code);
    print_binary(code);


    return 0;
}

unsigned int encode(unsigned int num, int n)
{
    int i;
    unsigned int mask = 0, temp;
    for(i=0;i<n;i++)
    {
        mask = mask << 1;
        mask = mask | 1;
    }

    temp = num & mask;

    return (num>>n) | (temp<<(32-n));
}


#include <stdio.h>

void print_binary(unsigned int n) 
{
    for (int i = 31; i >= 0; i--) 
    {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0) printf(" ");  // 可选：每4位加个空格方便阅读
    }
    printf("\n");
}


