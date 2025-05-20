#include<stdio.h>
#include<stdlib.h>
#define seed 11
#define n 10

int main()
{
    FILE *outdata;
    outdata = fopen("/Users/kemingliu/Desktop/filetest.inf","w");

    if(outdata == NULL)
    {
        printf("Invalid file");
        return 1;
    }

    int a[n],i;
    srand(seed);

    for(i=0;i<n;i++)
    {
        a[i] = rand() % 100;
    }

    for(i=0;i<n;i++)
    {
        fprintf(outdata,"%d \n",a[i]);
    }

    fclose(outdata);
    return 0;
}