#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct node 
{
    int val;
    struct node* next;
} node;

node* createNode(int val) 
{
    node* n = (node*)malloc(sizeof(node));
    n->val = val;
    n->next = NULL;
    return n;
}

void printList(node* head) 
{
    node* cur = head;
    while (cur != NULL) 
    {
        printf("%d", cur->val);
        if (cur->next != NULL) 
        {
            printf(" -> ");
        } else {
            printf(" -> NULL\n");
        }
        cur = cur->next;
    }
}

node* reverse(node* head)
{
    node* cur, * temp,* pre = NULL;
    cur = head;

    while(cur != NULL)
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}

int main() 
{
    node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printList(head);

    node* rev;
    rev = reverse(head);

    printList(rev);

    return 0;
}
