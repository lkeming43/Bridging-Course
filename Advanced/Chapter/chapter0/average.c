#include<stdio.h>
#include<stdlib.h>

typedef struct number
{
    int stuNUM;
    struct number *next;
}node;

node *get_nodes(void);
double average(node *start);

int main()
{
    node *start;

    start = get_nodes();
    printf("\nAverage is %f.", average(start));
    return 0;
}

node *get_nodes(void)
{
    node *current, *first;
    int response;
    first = current = (node *)malloc(sizeof(node));

    printf("\nNumber of students: ");
    scanf("%d", &current->stuNUM);

    printf("\nContinue (1) or not (0): ");
    scanf("%d",&response);

    while(response)
    {
        current->next = (node *)malloc(sizeof(node));

        if(current->next == NULL)
        {
            printf("\nNo more space.");
            return first;
        }

        current = current->next;

        printf("\nNumber of students: ");
        scanf("%d", &current->stuNUM);

        printf("\nAdd another? (1 = yes, 0 = no)");
        scanf("%d", &response);
    }

    return first;
}

double average(node *start)
{
    double sum = 0;
    int n = 0;

    if(start == NULL)
    {
        printf("\nEmpty list.");
        return 1;
    }

    do
    {
        n++;
        sum = sum + start->stuNUM;
        start = start->next;
    }while(start != NULL);

    return sum / n;
}