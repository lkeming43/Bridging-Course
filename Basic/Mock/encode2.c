#include<stdio.h>

void encode(int num[]);
void decode(int num[]);

int main()
{
    int num[6],i,temp;

    printf("Enter a 6 digits number: ");
    scanf("%d",&temp);

    for(i=0;i<6;i++)
    {
        num[5-i] = temp % 10;
        temp = temp/10;
    }

    encode(num);
    printf("\nAfter being encoded: ");
    for(i=0;i<6;i++)
    {
        printf("%d",num[i]);
    }

    decode(num);
    printf("\nAfter being decoded: ");
    for(i=0;i<6;i++)
    {
        printf("%d",num[i]);
    }

    return 0;
}

void encode(int num[])
{
    int i,code[6];

    for(i=0;i<6;i++)
    {
        code[i] = num[i];
    }

    for(i=0;i<6;i++)
    {
        num[i] = (code[i] + i + 1 +code[5 - i]) % 10;
    }
}

void decode(int num[])
{
    int i,j,n,code[6];

    for(i=0;i<6;i++)
    {
        code[i] = num[i];
    }

    for(n=0;n<6;n++)
    {
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if((i + j + n + 1)%10 == code[n] && (i + j + 6 - n)%10 == code[5-n])
                {
                    printf("\n%d %d %d",i,j,n);
                }
            }
        }
    }
}