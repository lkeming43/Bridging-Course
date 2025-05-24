#include<stdio.h>
#include<stdlib.h>

typedef struct stu
{
    char name[100];
    int no;
    struct stu *below;
}node;

void pushI(node* cur);
node *popI(void);
void pushO(node* cur);
node *popO(void);
void printnode(node *stu);

node *topI = NULL, *topO = NULL;


int main()
{
	int flag = 1, arg;
	node *temp, *stu, *tempnode;
	
	while(flag)
	{
		printf("\nEnter 1 to add or 2 to delete: ");
		scanf("%d", &arg);
		
		if((topI == NULL && topO == NULL) && arg == 2)
		{
			printf("\nEmpty queue.");
		}
		
		else
		{
			switch(arg)
			{
				case 1:
				{
					temp = (node* )malloc(sizeof(node));
					printf("Enter student's name: ");
					scanf("%s", temp->name);
			
					printf("Enter student's number: ");
					scanf("%d", &temp->no);
			
					pushI(temp);
					break;
				}
				
				case 2:
				{
					if(topO == NULL)
					{
						while((tempnode = popI())!= NULL)
						{
							pushO(tempnode);
						}
						
						stu = popO();
						printnode(stu);
						
						free(stu);
					}
					
					else
					{
						stu = popO();
						printnode(stu);
					}
					
					break;
				}
				
				default:
				{
					printf("\nInvalid input.");
					break;
				}
			}
		}

		
		printf("\nEnter 1 to continue or 0 to stop: ");
		scanf("%d", &flag);
	}
	
	return 0;
}

void pushI(node* cur)
{	
	cur->below = topI;
	topI = cur;

    return;
}

node *popI(void) 
{
    if (topI == NULL)
        return NULL;

    node *temp = topI;
    topI = topI->below;
    return temp;
}

void pushO(node* cur)
{	
	cur->below = topO;
	topO = cur;
    
    return;
}

node *popO(void) 
{
    if (topO == NULL)
        return NULL;

    node *temp = topO;
    topO = topO->below;
    return temp;
}

void printnode(node *stu)
{
	printf("\nStudent is %d %s.", stu->no, stu->name);
}