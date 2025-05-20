#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct stackKe1
{
    int number;
    char student_name[20];
    struct stackKe1 *below;
}node;

node *top = NULL;
int size = 0;

void present(node this1);
void get(node *this1);
node *push(node this1);
node *pop(void);

int main()
{
    int flag, sig;
    node this1, *temp;

    do
    {
        printf("\nEnter 1 to push or 2 to pop: ");
        scanf("%d", &flag);
        do
        {
            switch(flag)
            {
                case 1:
                {
                    get(&this1);
                    if(push(this1) == NULL)
                    {
                        printf("Stack is full.");
                    }
                    break;
                }

                case 2:
                {
                    if( (temp = pop()) == NULL)
                    {
                        printf("Empty stack.");
                    }
                    else present(*temp);
                    break;
                }

                default:
                {
                    printf("Invalid choice.");
                    break;
                }
            }
        } while (flag != 1 && flag != 2);
        
        printf("\nEnter 1 to continue or 0 to stop: ");
        scanf("%d", &sig);
    } while (sig);
    
    return 0;
}

void present(node this1)
{
    printf("%d %s", this1.number, this1.student_name);
}


void get(node *this1)
{
    printf("Enter student's number: ");
    scanf("%d", &this1->number);
    printf("Enter student's name: ");
    scanf("%s", this1->student_name);
}


node *push(node this1) 
{
    if(size >= SIZE) return NULL;

    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) return NULL; 
    
    *new_node = this1;
    new_node->below = top;
    top = new_node;

    size++;

    return new_node;
}

node *pop(void) 
{
    static node temp;
    node *ptr;
    if (top < 0) 
    {
        return NULL;
    }

    temp = *top;  
    ptr = top;
    top = top->below;   
    free(ptr);      
    return &temp;         
}