#include<stdio.h>
#include<stdlib.h>
#define COLUMNS 9
#define ROWS 6

int main()
{
    char *table;
    table = (char *)calloc(COLUMNS * ROWS, sizeof(char));

    int i, j;

    for(i=0;i<6;i++)
    {
        for(j=0;j<9;j++) table[COLUMNS * i + j] = 32;
    }

    for(i=1;i<5;i++)
    {
        for(j=0;j<8;j++)
        {
            if((i+j)>=5 && (i+j)<= (5+2*(i-1))) table[COLUMNS * i + j] = '*';
        }
    }

    for(i=0;i<6;i++)
    {
        printf("\n");
        for(j=0;j<9;j++)
        {
            printf("%c", table[COLUMNS * i + j]);
        }
    }

    return 0;
}