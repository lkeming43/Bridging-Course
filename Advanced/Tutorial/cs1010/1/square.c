#include<stdio.h>

int det(int n, int square[][n]);

int main()
{
    int n, i, j;

    printf("Enter the order of the square: ");
    scanf("%d", &n);

    int square[n][n];

    printf("\nEnter the content of the square: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++) scanf("%d", &square[i][j]);
    }

    if(det(n, square)) printf("\nYes");
    else printf("\nNo");

    return 0;
}

int det(int n, int square[][n])
{
    int flag = 1, ans = 1, check = 0, temp = 0;
    int i, j;
    
    for(i=0;i<n;i++)
    {
        temp = 0;

        if(flag)
        {
            for(j=0;j<n;j++) check = check + square[i][j];
            flag = 0;
        }

        for(j=0;j<n;j++) temp = temp + square[i][j];

        if(temp != check) return 0; 
    }

    for(j=0;j<n;j++)
    {
        temp = 0;

        for(i=0;i<n;i++) temp = temp + square[i][j];

        if(temp != check) return 0; 
    }

    temp = 0;
    for(i=0;i<n;i++)
    {
        temp = temp + square[i][i];
    }
    if(temp != check) return 0; 

    temp = 0;
    for(i=n-1;i>=0;i--)
    {
        temp = temp + square[i][n - 1 - i];
    }
    if(temp != check) return 0;

    return 1;
}
