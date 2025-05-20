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

    for(j=0;j<n;j++)
    {
        index = j;
        for(i=j + 1 ;i<n;i++)
        {
            if(x[i] < x[index]) index = i;//找到了暂时的最小的x[index]，下一次就要和x[index]比而不是x[j]
        }
        
        if(index != j)
        {
            temp = x[j];
            x[j] = x[index];
            x[index] = temp;
        }
    }
    
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", x[i]);
    }

    return 0;
}