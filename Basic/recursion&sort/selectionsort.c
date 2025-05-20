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
    int num[n], i, j, index, biggest;

    srand(seed);

    for(i=0;i<n;i++)
    {
        num[i] = rand() % 100;
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }

    for(i=0;i<n;i++)
    {
        biggest = i;
        for(j=0;j<n;j++)
        {
            if(num[j] > num[biggest])
            {
                biggest = j;
            }

            if(biggest != i)
            {
                swap(&num[biggest], &num[i]);
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