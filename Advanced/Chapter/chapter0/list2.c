#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* declare a self-referential structure */
typedef struct animal
{
    char name[10];  // 存储动物名称
    struct animal *next;  // 指向下一个节点的指针
} node;

// 函数声明
void print_nodes(const node *ptr);
node *get_nodes(void);

int main()
{
    node *start;
    // 获取链表的起始节点
    start = get_nodes();
    // 打印链表中的所有节点
    print_nodes(start);
    return 0;
}

// 获取用户输入的节点并创建链表
node *get_nodes(void)
{
    node *current, *first;
    int response;

    // 分配第一个节点
    first = current = (node *)malloc(sizeof(node));

    // 输入第一个动物的名称
    printf("\n\tNAME:\t");
    scanf("%s", current->name);

    // 询问是否继续添加下一个节点
    printf("\tAdd another? (1 = yes, 0 = no)\t");
    scanf("%d", &response);

    // 循环创建新的节点，直到用户选择不再添加
    while (response)
    {
        // 分配下一个节点
        current->next = (node *)malloc(sizeof(node));
        
        // 如果内存分配失败，输出错误并返回已创建的链表
        if (current->next == NULL)
        {
            printf("Out of memory\nCan't add more nodes\n");
            return first;
        }

        // 移动到下一个节点
        current = current->next;

        // 输入下一个动物的名称
        printf("\tNAME:\t");
        scanf("%s", current->name);

        // 询问是否继续添加下一个节点
        printf("\tAdd another? (1 = yes, 0 = no)\t");
        scanf("%d", &response);
    }

    // 最后一个节点的 next 指向 NULL，表示链表结束
    current->next = NULL;
    
    // 返回链表的起始节点
    return first;
}

// 打印链表中每个节点的名称
void print_nodes(const node *ptr)
{
    int count = 1;
    printf("\n");

    // 遍历链表并打印每个节点的名称
    while (ptr != NULL)
    {
        printf("\nAnimal number %d is %s.", count++, ptr->name);
        ptr = ptr->next;  // 移动到下一个节点
    }
}
