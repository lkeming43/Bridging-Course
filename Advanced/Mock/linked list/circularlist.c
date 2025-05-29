#include<stdio.h>
#include<stdlib.h>

typedef struct circle
{
    int num;
    struct circle *next;
}node;

int main()
{
    node *cur, *rear = NULL, *first = NULL, *temp;
    int player, no, i = 1;

    printf("Enter the number of player: ");
    scanf("%d", &player);
    printf("\nEnter the lucky number: ");
    scanf("%d", &no);

    while(i <= player)
    {
        cur = (node*)malloc(sizeof(node));
        cur->num = i;
        if(first == NULL) 
        {
            first = cur;
            rear = cur;
        }
        rear->next = cur;
        rear = cur;

        i++;
    }

    cur->next = first;
    cur = first;

    while(player > 1)
    {
        int flag = 1;

        while(flag < no)
        {
            temp = cur;
            cur = cur->next;
            flag++;
        }

        temp->next = cur->next;

        printf("\nThe lucky man is %d.", cur->num);

        cur = cur->next;
        player--;
    }

    printf("\nThe winning man is %d.", cur->num);

    return 0;
}