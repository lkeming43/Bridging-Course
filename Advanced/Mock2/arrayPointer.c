#include<stdio.h>
#include<string.h>

int main()
{
    char *names[] = {"Tom", "Alice", "Bob", "John"};
    char *temp;
    int flag = 1;
    int num = 4, i;

    while(flag)
    {
        flag = 0;

        for(i=0;i<num-1;i++)
        {
            if(strcmp(names[i], names[i+1]) > 0)
            {
                temp = names[i];
                names[i] = names[i+1];
                names[i+1] = temp;
                flag = 1;
            }
        }

        num--;
    }

    i = 0;
    while(i < 4)
    {
        printf("\n%s", names[i]);
        i++;
    }

    return 0;
}