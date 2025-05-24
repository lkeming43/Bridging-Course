#include<stdio.h>
#include<stdlib.h>

typedef struct bracket
{
    char check;
    struct bracket *below;
}node;

void push(node* cur);
node *pop(void);
int is_matching(char open, char close);

node *top = NULL;

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        printf("Usage: %s \"bracket_string\"\n", argv[0]);
        return 1;
    }
    

    int i = 0;
    node *temp, *flag;

    while(argv[1][i] != '\0')
    {
        if(argv[1][i] == '(' || argv[1][i] == '{' || argv[1][i] == '[')
        {
            temp = (node *)malloc(sizeof(node));
            temp->check = argv[1][i];
            push(temp);
        }

        else if(argv[1][i] == ')' || argv[1][i] == '}' || argv[1][i] == ']')
        {
            flag = pop();
            if (flag == NULL || !is_matching(flag->check, argv[1][i])) 
            {
                printf("\nInvalid brackets.\n");
                return 0;
            }
            free(flag);
        }

        else
        {
            i++;
            continue;
        }

        i++;
    }

    if (argv[1][i] == '\0' && top == NULL)
    printf("\nValid brackets.");
    else
    printf("\nInvalid brackets.");

    return 0;
}

void push(node* cur)
{	
	cur->below = top;
	top = cur;

    return;
}

node *pop(void) 
{
    if (top == NULL)
        return NULL;

    node *temp = top;
    top = top->below;
    return temp;
}

int is_matching(char open, char close) 
{
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}
