#include<stdio.h>
#include<math.h>

void convertB(int num, int bits[32]);
unsigned int convertD(int bits[32]);

int main()
{
    int x, y, bx[32], by[32], i, interleaved[32], mask = 1;
    int fx = 31, fy = 31;
    unsigned int result;
    char flag = 'y';

    while(flag == 'y')
    {
        fx = 31;
        fy = 31;
        printf("Enter X: ");
        scanf("%d", &x);
        printf("\nEnter Y: ");
        scanf("%d", &y);

        convertB(x, bx);
        convertB(y, by);

        printf("\nx = %5d   ", x);
        for(i=0;i<32;i++)
        {
            printf("%d", bx[i]);
        }

        printf("\ny = %5d   ", y);
        for(i=0;i<32;i++)
        {
            printf("%d", by[i]);
        }

        for(i=0;i<32;i++)
        {
            interleaved[i] = 0;
        }

        for(i=0;i<32;i++)
        {
            if((i & mask) == 1) 
            {
                interleaved[31-i] = by[fy--]; 
            }
            else 
            {
                interleaved[31-i] = bx[fx--]; 
            }
        }

        result = convertD(interleaved);
        printf("\nInterleaved = %u  ", result);
        for(i=0;i<32;i++)
        {
            printf("%d", interleaved[i]);
        }

        getchar();
        printf("\n\nContinue (y/n): ");
        scanf("%c", &flag);
    }

    return 0;
}

unsigned int convertD(int bits[32])
{
    int i;
    unsigned int num = 0;
    for(i=0;i<32;i++)
    {
        //num = num + pow(2,i) * bits[31-i];
        num = num | bits[31-i] << i;
    }

    return num;
}

void convertB(int num, int bits[32])
{
    int i;
    for(i=0;i<32;i++)
    {
        bits[31-i] = num & 1;
        num = num >> 1;
    }
}