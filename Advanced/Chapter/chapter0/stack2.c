#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct tray
{
    char color[10];
    int id;
    struct tray *below;
} node;

node *top = NULL;
int currsize = 0;

void get_data(node *ptr);
void put_data(const node *ptr);
node *push(node tr);
node *pop(void);

int main()
{
    int ans, flag;
    node t, *ptr;

    do
    {
        do
        {
            printf("Enter 1 to push, 2 to pop: ");
            scanf("%d", &ans);

            switch (ans)
            {
                case 1:
                    get_data(&t);
                    if (push(t) == NULL)
                        printf("STACK FULL\n");
                    break;

                case 2:
                    if ((ptr = pop()) != NULL)
                        put_data(ptr);
                    else
                        printf("STACK EMPTY\n");
                    break;

                default:
                    printf("Illegal response\n");
                    break;
            }
        }
        while (ans != 1 && ans != 2);

        printf("1 to continue, 0 to quit: ");
        scanf("%d", &flag);
    }
    while (flag);

    return 0;
}

void get_data(node *ptr)
{
    printf("Enter the tray's color: ");
    scanf("%s", ptr->color);

    printf("Enter the tray's id: ");
    scanf("%d", &(ptr->id));
}

void put_data(const node *ptr)
{
    printf("Tray's color: %s\n", ptr->color);
    printf("Tray's id: %d\n", ptr->id);
}

node *push(node tr)
{
    if (currsize >= SIZE)
        return NULL;

    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
        return NULL;

    *ptr = tr;
    ptr->below = top;
    top = ptr;
    ++currsize;

    return ptr;
}

node *pop(void)
{
    static node popped_node;
    node *ptr;

    if (currsize < 1)
        return NULL;

    popped_node = *top;
    ptr = top;
    top = top->below;
    free(ptr);
    --currsize;

    return &popped_node;
}
