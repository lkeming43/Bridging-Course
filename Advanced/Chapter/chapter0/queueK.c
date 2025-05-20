#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct
{
    char lname[25];
    char fname[25];
    int student_no;
}node;

node *customer[SIZE];
int front = 0, rear = 0; 
int count = 0;     

node *insert(node);
node *delete(void);
void get_data(node *);
void put_data(const node *);

int main()
{
    node this1, *ptr;
    int flag,ans;

    do
    {
        do
        {
            printf("\nEnter 1 to insert or 2 to delete: ");
            scanf("%d", &ans);

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
        }while(ans != 1 && ans != 2);

        printf("\nEnter 1 to continue or 0 to stop: ");
        scanf("%d", &flag);
    }while(flag == 1);

    return 0;
}

node *insert(node this1)
{
    node *p;

    if(count >= SIZE) return NULL;

    p = (node *)malloc(sizeof(node));
    *p = this1;

    customer[rear] = p;
    rear = (rear + 1) % 100;
    count++;

    return p;
}

node *delete(void)
{
    static node temp;
    if(count == 0) return NULL;

    temp = *customer[front];
    free(customer[front]);
    front = (front + 1) % SIZE;
    count--;

    return &temp;
}

void get_data(node *ptr)
{
    printf("Enter student's last name: ");//不需要换行符，输入了enter
    scanf("%s", ptr->lname);
    printf("Enter student's first name: ");
    scanf("%s", ptr->fname);
    printf("Enter student's no: ");
    scanf("%d", &ptr->student_no);
    printf("\n");
}

void put_data(const node *ptr)
{
    printf("Deleted Record:");
    printf("\nStudent's name: %s, %s\n", ptr->lname, ptr->fname);
    printf("Student's number: %d\n", ptr->student_no);
}