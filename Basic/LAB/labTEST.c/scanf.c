#include<stdio.h>

int main()
{
    int n;
    char c;
    FILE *indata;
    indata = fopen("/Users/kemingliu/Desktop/IDENTITY.INF","r");

    if(indata == NULL)
    {
        printf("Invalid file");
        return 1;
    }

    while(fscanf(indata,"%d%c",&n,&c) == 2)
    {
        printf("\n%d %c",n,c);
    }

    return 0;
}