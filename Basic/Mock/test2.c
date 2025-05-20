#include<stdio.h>
int de( int code , int n);

int a[10] = {9,0,1,2,3,4,5,6,7,8};

int main()
{
    FILE *indata;
    int code[6], decode[6],i,temp;
    char coun;

    indata = fopen("/Users/kemingliu/Desktop/bombs.txt", "r");
    
    if( indata == NULL)
    {
        printf("Invalid file");
        return 1;
    }

    printf("Actual Bombs Possession");
    printf("\nCountry code        Number");
    printf("\n===========================");
    while(fscanf(indata, " %c", &coun) == 1)
    {
        fscanf(indata, " %6d",&temp);

        for(i=0;i<6;i++)
        {
            code[5-i] = temp%10;
            temp = temp/10;
        }

        for(i=0;i<6;i++)
        {
            decode[i] = de(code[i], i);
        }
    
        printf("\n      %c             ",coun);

        for(i=0;i<6;i++)
        {
            printf("%d", decode[i]);
        }

    }

    return 0;
}

int de(int code, int n)
{
    int i,decode;
    for(i=0;i<(n+1);i++)
    {
        decode = a[code];
        code = decode;
    }
    return decode;
}