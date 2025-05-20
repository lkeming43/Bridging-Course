#include<stdio.h>
#include<stdlib.h>
#define n 10
#define seed 17

int main()
{
    int i,j,x[n],index,temp;
    srand(seed);

    for(i=0;i<n;i++)
    {
        x[i] = rand() % 100;
    }

    for(i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }

    for(i=1;i<n;i++)
    {
        temp = x[i];

        for(j=i-1;j>=0 && x[j]>temp ;j--)
        {
            x[j+1] = x[j];
        }
        
        x[j+1] = temp;
    }

    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }

    return 0;

}





/*for(i=1;i<n;i++)
    {
        temp = x[i];
        
        for(j = i - 1; j >= 0 && x[j] > temp; j--)
        {
            x[j+1] = x[j];
        }
        
        x[j+1] = temp;
    }*/