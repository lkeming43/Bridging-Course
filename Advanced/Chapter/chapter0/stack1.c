// stack1.c - LIFO stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct 
{
    char color[10];  // tray color
    int id;          // tray id
} node;

node *trays[SIZE];  // array of pointers to node
int top = -1;       // index into top of stack

// 函数声明
void get_data(node *ptr);
void put_data(const node *ptr);
node *push(node tr);
node *pop(void);

int main() 
{
    int ans, flag;
    node t;
    node *ptr;

    // do stack operations until user signals halt
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
        } while (ans != 1 && ans != 2);

        printf("Enter 1 to continue, 0 to quit: ");
        scanf("%d", &flag);
        printf("\n");
    } while (flag);

    return 0;
}

// 获取节点数据
void get_data(node *ptr) 
{
    printf("Enter the tray's color: ");
    scanf("%s", ptr->color);

    printf("Enter the tray's id: ");
    scanf("%d", &(ptr->id));
}

// 打印节点数据
void put_data(const node *ptr) 
{
    printf("tray's color: %s\n", ptr->color);
    printf("tray's id: %d\n", ptr->id);
}

// 压栈
node *push(node tr) 
{
    if (top >= SIZE - 1)  // 栈满
        return NULL;

    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL) return NULL;  // malloc失败

    *ptr = tr;  // 拷贝数据
    trays[++top] = ptr;
    return ptr;
}

// 弹栈
node *pop(void) 
{
    static node temp;  // 静态变量：返回栈内数据副本
    if (top < 0)        // 栈空
        return NULL;

    temp = *trays[top];      // 拷贝数据
    free(trays[top--]);      // 释放内存
    return &temp;            // 返回副本地址
}
