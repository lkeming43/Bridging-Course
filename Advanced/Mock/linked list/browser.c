#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 双向链表节点
typedef struct Node 
{
    char url[100];  // 网页URL
    struct Node* prev;  // 指向前一个网页
    struct Node* next;  // 指向下一个网页
} Node;

typedef struct Browser 
{
    Node* current;  // 当前网页
    Node* head;     // 浏览历史的头节点
    Node* tail;     // 浏览历史的尾节点
} Browser;

// 创建浏览器
Browser* createBrowser() 
{
    Browser* browser = (Browser*)malloc(sizeof(Browser));
    browser->current = NULL;
    browser->head = NULL;
    browser->tail = NULL;
    return browser;
}

// 访问新网页
void visit(Browser* browser, const char* url) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->url, url, sizeof(newNode->url) - 1);
    newNode->prev = browser->current;
    newNode->next = NULL;

    // 如果当前节点不是NULL，意味着有前进历史。新的网页会替代所有后续网页。
    if (browser->current != NULL) 
    {
        browser->current->next = NULL;  // 删除后续历史
    }

    // 更新浏览器的当前节点
    if (browser->head == NULL) 
    {
        browser->head = newNode;
        browser->tail = newNode;
    } 
    else 
    {
        browser->current->next = newNode;
        browser->tail = newNode;
    }

    browser->current = newNode;
}

// 后退到上一个网页
void back(Browser* browser) 
{
    if (browser->current != NULL && browser->current->prev != NULL) 
    {
        browser->current = browser->current->prev;
        printf("Back to: %s\n", browser->current->url);
    } 
    else 
    {
        printf("No previous page.\n");
    }
}

// 前进到下一个网页
void forward(Browser* browser) 
{
    if (browser->current != NULL && browser->current->next != NULL) 
    {
        browser->current = browser->current->next;
        printf("Forward to: %s\n", browser->current->url);
    } 
    else 
    {
        printf("No next page.\n");
    }
}

// 输出当前网页的URL
void current(Browser* browser) 
{
    if (browser->current != NULL) 
    {
        printf("Current page: %s\n", browser->current->url);
    } 
    else
    {
        printf("No page visited.\n");
    }
}

// 释放浏览器历史链表
void freeBrowser(Browser* browser) 
{
    Node* current = browser->head;
    Node* next;

    while (current != NULL) 
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(browser);
}

int main() 
{
    Browser* browser = createBrowser();
    int choice;
    char url[100];

    while (1) 
    {
        printf("\n--- Browser Menu ---\n");
        printf("1. Visit a new webpage\n");
        printf("2. Go back to the previous page\n");
        printf("3. Go forward to the next page\n");
        printf("4. Show current webpage\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline left by scanf

        switch (choice) 
        {
            case 1:
                printf("Enter the URL of the new webpage: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0;  // Remove newline character from input
                visit(browser, url);
                break;

            case 2:
                back(browser);
                break;

            case 3:
                forward(browser);
                break;

            case 4:
                current(browser);
                break;

            case 5:
                printf("Exiting the browser...\n");
                freeBrowser(browser);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
