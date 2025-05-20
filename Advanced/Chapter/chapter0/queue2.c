#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct customer
{
    char lname[15];
    char fname[15];
    int account_no;
    long balance;
    struct customer *succ;
} node;

node *front = NULL;
node *rear = NULL;
int count = 0;

void get_data(node *ptr);
void put_data(const node *ptr);
node *insert(node this1);
node *delete_node(void);

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

            switch (ans)
            {
                case 1:
                    get_data(&this1);
                    if (insert(this1) == NULL)
                        printf("\nQUEUE FULL\n");
                    break;

                case 2:
                    if ((ptr = delete_node()) != NULL)
                        put_data(ptr);
                    else
                        printf("\nQUEUE EMPTY\n");
                    break;

                default:
                    printf("\nIllegal response\n");
                    break;
            }
        } while (ans != 1 && ans != 2);

        printf("\n1 to continue, 0 to quit: ");
        scanf("%d", &flag);
        printf("\n");

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
    printf("\nCustomer's name: %s, %s\n", ptr->lname, ptr->fname);
    printf("Customer's account number: %d\n", ptr->account_no);
    printf("Customer's balance: %ld\n\n", ptr->balance);
}

node *insert(node this1)
{
    if (count >= SIZE)
        return NULL;

    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    *ptr = this1;
    ptr->succ = NULL;

    if (count == 0)
    {
        front = ptr;//如果前面没有node，就成为第一个node
    }
    else
    {
        rear->succ = ptr;//prt是新的内容，succ指向新的节点
    }

    rear = ptr;
    ++count;

    return ptr;
}

node *delete_node(void)
{
    static node this1;
    node *next;

    if (count == 0)
        return NULL;

    this1 = *front;
    next = front;//释放原始要被删除的节点
    front = front->succ;
    free(next);
    --count;

    return &this1;
}
