#include<stdio.h>

int dayofweek(int *month,int *year)
{
    return 7;
}
 
void calendar(int c[6][7], int month, int year)
{
    int start,i,j,a[42],n=1;

    start = dayofweek(&month,&year);

    for(i=0;i<6;i++)
    {
        a[i]=0;
    }

    for(i=(start-1);(i-start)<30;i++) 
    {   
        a[i]=n;
        n++;
    }

    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            c[i][j]=a[(7*(i))+(j)];
        }
    }

}



int main()
{
    int cal[6][7],month=4,year=2012;

    calendar(cal, month, year);

    printf("  mon tue wed thu fri sat sun  \n");
   
    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            printf("%4d", cal[i][j]);
        }
        printf("\n");
    }
    return 0;
}