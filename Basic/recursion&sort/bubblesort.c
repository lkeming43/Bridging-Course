#include<stdio.h>
#include<stdlib.h>
#define seed 11
#define n 10

void swap(int *n1, int *n2)
{
    int temp;

    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main()
{
    int num[n], i, j;

    srand(seed);

    for(i=0;i<n;i++)
    {
        num[i] = rand() % 100;
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }

    for(i=n;i>0;i--)
    {
        for(j=0;j<i-1;j++)
        {
            if(num[j] > num[j+1])
            {
                swap(&num[j], &num[j+1]);
            }
        }
    }
    
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }

    return 0;
}