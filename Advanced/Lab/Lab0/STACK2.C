#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct elements
{
    int num;
    struct elements *below;
} node;

node *top = NULL;
int currsize = 0;

node *push(node tr);
node *pop(void);

int main(int argc, char *argv[])
{
    int i = 0, result = 0;
    char temp[100];
    node t, *a, *b, *c;

    FILE *indata;

    indata = fopen(argv[1], "r");

    while (fgets(temp, sizeof(temp), indata) != NULL)
    {
          i = 0;

          if(temp[i] == 'X') return 0;
     
          if(temp[strlen(temp) - 1] == '\n') 
          {
               temp[strlen(temp) - 1] = '\0';
          }

          top = NULL;
          currsize = 0;

          while(temp[i] != '\0')
          {
               if(temp[i] >= '0' && temp[i] <= '9')
               {
                    t.num = temp[i] - '0';
                    push(t);
               }

               else if(temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/' )
               {
                    a = pop();
                    b = pop();

                    if(a == NULL || b == NULL)
                    {
                         printf("\nError: not enough operands\n");
                         break;
                    }

                    switch(temp[i])
                    {
                         case '+': result = b->num + a->num; break;
                         case '-': result = b->num - a->num; break;
                         case '*': result = b->num * a->num; break;
                         case '/': result = b->num / a->num; break;
                    }

                    t.num = result;
                    push(t);
               }

               else if(temp[i] == '=') 
               {
                    if(temp[strlen(temp) - 2] == '=') 
                    {
                         temp[strlen(temp) - 2] = '\0';
                    }

                    c = pop();
                    for(i=0;temp[i] != '\0'; i++) printf("%c", temp[i]);
                    printf(" = %d", c->num);
                    printf("\n");
                    break;
               }
               i++;
          }
    }

    return 0;
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
    node *ptr;

    if (currsize < 1) return NULL;

    node *popped_node = (node *)malloc(sizeof(node));
    *popped_node = *top;
    ptr = top;
    top = top->below;
    free(ptr);
    --currsize;

    return popped_node;
}

/*node *pop(void)
{
    static node popped_node;        所有内容都指向一个固定的地址，所以最后传回的指针都指向同一个地址
    node *ptr;

    if (currsize < 1)
        return NULL;

    popped_node = *top;
    ptr = top;
    top = top->below;
    free(ptr);
    --currsize;

    return &popped_node;
}*/