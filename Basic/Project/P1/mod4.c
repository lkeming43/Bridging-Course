#include <stdio.h>
int main ()
{
    int a,i,j;
    

    printf("$ ./a.out");
    printf("\nEnter n:");
    scanf("%d",&a);

    printf("\nOutput Multiplication Table");
    printf("\n---+---------------------\n");




    int MT[a][a];

    for(i=0;i<a-1;i++)
    {
        for(j=0;j<a-1;j++)
        MT[i][j]=0;
    }

    //赋值第一行&第一列
    for(j=0;j<a-1;j++)
        MT[0][j]=(j+1);
    for(i=0;i<a-1;i++)
        MT[i][0]=(i+1);
    
    //赋值mod
    for(i=1;i<a-1;i++)
    {
        for(j=1;j<a-1;j++)
        MT[i][j]=(i+1)*(j+1)%a;
    }

    //打印抬头
    printf("   |");
    for(i=0;i<a-1;i++)
    {
        printf(" %d ",i+1);
    }
    printf("\n---+---------------------\n");
    
    //打印MT
    for(i=0;i<a-1;i++)
    {
        printf("  %d|",i+1);
        for(j=0;j<a-1;j++)
        printf(" %d ", MT[i][j]);
        printf("\n");
    }
    
    printf("---+---------------------\n");

    //打印抬头
    printf("\nOutput inverse Table");
    printf("\n---+---------------------\n");

    printf("   |");
    for(i=0;i<a-1;i++)
    {
        printf(" %d ",i+1);
    }
    printf("\n---+---------------------\n");

    //打印inverse
    for(i=0;i<a-1;i++)
    {
        printf("  %d|",i+1);
        for(j=0;j<a-1;j++)
        
        if(MT[i][j]==1) printf(" * ");
        else printf("   ");
        printf("\n");
    }

    printf("---+---------------------\n");

    

    return 0;
}