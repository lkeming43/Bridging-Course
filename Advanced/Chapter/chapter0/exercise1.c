#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct hsy
{
    char name[10];
    struct hsy *next;
}node;

void print_nodes(const node *ptr);
node *get_nodes(void);

int main()
{
    node *start;

    start = get_nodes();
    print_nodes(start);
    return 0;
}

void print_nodes(const node *ptr)
{
    int count = 1;
    printf("\n");

    while(ptr != NULL)
    {
        printf("\nStudent's name %d is %s.", count, ptr->name);
        ptr = ptr->next;
        count++;
    }
}

node *get_nodes(void)
{
    node *current, *first;
    int response;
    first = current = (node *)malloc(sizeof(node));

    printf("\nNAME: ");
    scanf("%s", current->name);

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

        printf("\nNAME: ");
        scanf("%s", current->name);

        printf("\nAdd another? (1 = yes, 0 = no)");
        scanf("%d", &response);
    }

    return first;
}