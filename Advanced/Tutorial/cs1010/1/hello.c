#include<stdio.h>

void greatings(char *name)
{
    printf("Hello %s", name);
}


int main()
{

    greatings("Bob");
    return 0;
}