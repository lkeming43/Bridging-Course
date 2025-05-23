#include <stdio.h>

unsigned int interleave(unsigned int x, unsigned int y);

int main()
{
    unsigned int x, y, result;
    char flag = 'y';

    while (flag == 'y')
    {
        printf("Enter X: ");
        scanf("%u", &x);
        printf("Enter Y: ");
        scanf("%u", &y);

        result = interleave(x, y);

        printf("\nInterleaved = %u  Binary: ", result);

        for (int i = 31; i >= 0; i--)
        {
            printf("%d", (result >> i) & 1);
        }

        printf("\n\nContinue (y/n): ");
        getchar(); 
        scanf("%c", &flag);
    }

    return 0;
}

unsigned int interleave(unsigned int x, unsigned int y)
{
    unsigned int result = 0;
    int i;

    for (i = 0; i < 32; i++)
    {

        if (i % 2 == 0)
        {
            result |= (x & 1) << i;  
            x = x >> 1;
        }
        else
        {
            result |= (y & 1) << i;  
            y = y >> 1;
        }
    }

    return result;
}
