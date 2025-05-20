#include<stdio.h>

int k=1;

void go(int num[10][10],int i, int j);

int main()
{
    int i,j;
    int num[10][10] = {0};

    
    i=0;
    j=0;

    go(num,i,j);

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%3d ",num[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void go(int num[10][10],int i, int j)
{
    num[i][j] = k++;
    if(i == 5 && j==4) return;

    if(j+1 < 10 && num[i][j+1] == 0 && !(i-1 >= 0 && num[i-1][j] == 0)) go(num, i, j+1);
    else if(i+1 < 10 && num[i+1][j] == 0) go(num,i+1,j);
    else if(j-1 >= 0 && num[i][j-1] == 0) go(num, i, j-1);
    else if(i-1 >= 0 && num[i-1][j] == 0) go(num, i-1, j);
    
    else return;

}