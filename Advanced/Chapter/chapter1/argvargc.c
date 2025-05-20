#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;
    printf("Number of parameters: %d", argc);

    for(i=0;i<=argc;i++)
    {
        printf("\nThe %dth parameter is %s.\n", i, argv[i]);
    }

    return 0;
}