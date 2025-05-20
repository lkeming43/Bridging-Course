#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#define SIZE 100

typedef struct 
{
    char lname[25];    
    char fname[15];    
    int account_no;    
    long int balance;  
} node;

node *customers[SIZE];  
int front = 0, rear = 0; 
int count = 0;     

node *insert(node);
node *delete(void);
void get_data(node *);
void put_data(const node *);

int main() 
{
    int ans, flag;
    node this1, *ptr;

    do 
    {  
        do 
        {
            printf("\nEnter 1 to insert, 2 to remove: ");
            scanf("%d", &ans);
            printf("\n");
            
            switch(ans) 
            {
                case 1:
                    get_data(&this1);
                    if (insert(this1) == NULL) 
                        printf("\nQUEUE FULL\n\n");
                    break;
                case 2:
                    if ((ptr = delete()) != NULL)
                        put_data(ptr);
                    else
                        printf("\n\nQUEUE EMPTY\n\n");
                    break;
                default:
                    printf("\nIllegal response\n");
                    break;
            }
        } while (ans != 1 && ans != 2);
        
        printf("1 to continue, 0 to quit: ");
        scanf("%d", &flag);
    } while (flag);
    
    return 0;
}

void get_data(node *ptr) 
{
    printf("Enter the customer's last name: ");
    scanf("%s", ptr->lname);
    printf("Enter the customer's first name: ");
    scanf("%s", ptr->fname);
    printf("Enter the customer's account number: ");
    scanf("%d", &(ptr->account_no));
    printf("Enter the customer's balance: ");
    scanf("%ld", &(ptr->balance));
    printf("\n");
}

void put_data(const node *ptr) 
{
    printf("Deleted Record:");
    printf("\nCustomer's name: %s, %s\n", ptr->lname, ptr->fname);
    printf("Customer's account number: %d\n", ptr->account_no);
    printf("Customer's balance: %ld \n\n", ptr->balance);
}

node *insert(node this1) 
{
    node *ptr;
    if (count >= SIZE) return NULL;  
    
    ptr = (node *)malloc(sizeof(node));
    *ptr = this1;                  
    customers[rear] = ptr;          
    rear = ++rear % SIZE;           
    ++count;                        
    return ptr;
}

node *delete(void) 
{
    static node this1;
    if (count == 0) return NULL;    
    
    this1 = *customers[front];      
    free(customers[front]);        
    front = ++front % SIZE;         
    --count;
    return &this1;
}