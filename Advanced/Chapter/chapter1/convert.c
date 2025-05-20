#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32

int main(int argc, char *argv[])
{
    int digit, base, remainder, i;
    char symbol[SIZE];

    if (argc != 3)
    {
        printf("Wrong Format! Use this instruction:\n");
        printf("convert dd...d /base=d\n");
        exit(1);
    }

    if (strncmp(argv[2], "/base=", 6) != 0)
    {
        printf("Base Format Error!\n");
        exit(1);
    }

    base = atoi(argv[2] + 6);

    if (base < 2 || base > 36)
    {
        printf("Base should be between 2 and 36!\n");
        exit(1);
    }

    digit = atoi(argv[1]);

    printf("\t\t");

    if (digit < 0)
    {
        putchar('-');
        digit = -digit;
    }

    i = 0;

    do
    {
        remainder = digit % base;
        symbol[i] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
        i++;
        digit = digit / base;
    }
    while (digit > 0);

    do
    {
        i--;
        putchar(symbol[i]);
    }
    while (i > 0);

    putchar('\n');

    return 0;
}
