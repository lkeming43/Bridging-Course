#include<stdio.h>
#include<stdlib.h>
#define n 10
#define seed 17

void heapify(int x[], int N, int i);

int main()
{
    int i,j,x[n],temp;
    srand(seed);

    for(i=0;i<n;i++)
    {
        x[i] = rand() % 100;
    }

    for(i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }

    for(i=n/2 - 1;i>=0;i--)
    {
        heapify(x,n,i);
    }

    for(i=n-1;i>=0;i--)
    {
        temp = x[i];
        x[i] = x[0];
        x[0] = temp;

        heapify(x,i,0);
    }

    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }

    return 0;
}

void heapify(int x[], int N, int i)
{
    int right,left,biggest,temp;
    

    while(1)
    {
        right = 2*i + 2;
        left = 2*i + 1;
        biggest = i;

        if(right<N && x[right] > x [biggest])
        {
            biggest = right;
        }

        if(left<N && x[left] > x [biggest])
        {
            biggest = left;
        }

        if( biggest!=i)
        {
            temp = x[biggest];
            x[biggest] = x[i];
            x[i] = temp;

            i = biggest;
        }
        
        else break;
    }
}
