#include <stdio.h>
#include <string.h> 

typedef struct animal
{
    char name[10];
    struct animal *next;
} node;

void print_nodes(const node *ptr);

int main()
{
    node e1, e2, e3, *start;

    strcpy(e1.name, "AA");
    strcpy(e2.name, "BB");
    strcpy(e3.name, "CC");

    e1.next = &e2;
    e2.next = &e3;
    e3.next = NULL;

    start = &e1;

    print_nodes(start);

    return 0;
}

void print_nodes(const node *ptr)
{
    int count = 1;
    printf("\n\n\n");
    while (ptr != NULL)
    {
        printf("Animal number %d is %s.\n", count++, ptr->name);
        ptr = ptr->next;
    }
}
