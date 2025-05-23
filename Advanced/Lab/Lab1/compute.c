#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    typedef struct number
    {
        int num;
        struct number *next;
    }node;

    node *temp, *last = NULL, *first = NULL;
    int max, min, sum = 0, i = 1;
    double mean;

    if(argc < 2)
    {
        printf("No data.");

        return 0;
    }

    max = atoi(argv[i]);
    min = atoi(argv[i]);

    while(i < argc)
    {
        temp = (node *)malloc(sizeof(node));

        temp->num = atoi(argv[i]);
        if(i == 1) 
        {
            first = temp;
            last = temp;
        }

        if(temp->num < min) min = temp->num;
        else if(temp->num > max) max = temp->num;

        temp->next = NULL;
        last->next = temp;
        last = temp;
        i++;
    }

    temp = first;
    while (temp != NULL) 
    {
       sum = sum + temp->num;
       temp = temp->next;
    }

    mean = sum/((argc-1)*1.0);
    printf("\nSum = %d", sum);
    printf("\nMean = %f", mean);
    printf("\nMaximun = %d", max);
    printf("\nMinimun = %d", min);

    return 0;
}