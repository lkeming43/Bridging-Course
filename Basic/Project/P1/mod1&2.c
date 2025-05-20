#include <stdio.h>
int main ()
{
    int a,i,j;
    

    printf("$ ./a.out");
    printf("\nEnter n:");
    scanf("%d",&a);

    int MT[a][a];

    for(i=0;i<a-1;i++)
    {
        for(j=0;j<a-1;j++)
        MT[i][j]=0;
    }

    for(j=0;j<a-1;j++)
        MT[0][j]=(j+1);
    for(i=0;i<a-1;i++)
        MT[i][0]=(i+1);
    
    for(i=1;i<a-1;i++)
    {
        for(j=1;j<a-1;j++)
        MT[i][j]=(i+1)*(j+1)%a;
    }
        
    for(i=0;i<a-1;i++)
    {
        for(j=0;j<a-1;j++)
        printf("%d ", MT[i][j]);
        printf("\n");

    }

    

    return 0;
}