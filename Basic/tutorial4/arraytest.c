#include<stdio.h>

int main()
{
    char i[3]={'a','b','c'};
    int n;

     for(n=0;n<3;n++)
     {
        printf("%d %c \n",i[n],i[n]);
     }
}