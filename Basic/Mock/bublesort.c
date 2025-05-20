#include<stdio.h>
#include<stdlib.h>
#define n 10
#define seed 17

int x[n];

int main()
{
    int i,j,exchange,temp;
    exchange = 1;
    srand(seed);

    for(i=0;i<n;i++)
    {
        x[i] = rand() % 300;
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }
    

    while(exchange)
    {
        exchange = 0;
        for(i=0;i<=n-2;i++)
        {
            if(x[i] > x[i+1])
            {
                temp = x[i];
                x[i] = x[i+1];
                x[i+1] = temp;
                exchange = 1;
            }
        }
    }

    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }
}