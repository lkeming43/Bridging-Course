#include<stdio.h>
#include<stdlib.h>

typedef struct stu
{
    char name[100];
    int no;
    struct stu *below;
}node;

node *push(node* cur);
node *pop(node* cur);

node *top;

int main()
{

}

node *push(node* cur)
{
    node *temp = (node *)mallo(sizeof(node));

    
}

node *pop(node* cur)
{

}