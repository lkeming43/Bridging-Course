#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100 

typedef struct elements
{
	int num;
	struct elements *below;
}node;

node *top = NULL;
node *temp;
int current = 0;

int pop(void);
int push(int a);

int main()
{
	int a, b, c, i, result;
	char temp[SIZE];
	
	FILE *indata;
	indata = fopen("C:\\Users\\e1513092\\Desktop\\Lab\\Lab0\\postfix.inf", "r");
	
	while (fgets(temp, sizeof(temp), indata) != NULL)
    {
          i = 0;

          if(temp[i] == 'X') return 0;
     
          if(temp[strlen(temp) - 1] == '\n') 
          {
               temp[strlen(temp) - 1] = '\0';
          }

          top = NULL;
          current = 0;

          while(temp[i] != '\0')
          {
               if(temp[i] >= '0' && temp[i] <= '9')
               {
                    push(temp[i] - '0');
               }

               else if(temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/' )
               {
                    a = pop();
                    b = pop();

                    if(a == -1 || b == -1)
                    {
                         printf("\nError: not enough operands\n");
                         break;
                    }

                    switch(temp[i])
                    {
                         case '+': result = b + a; break;
                         case '-': result = b - a; break;
                         case '*': result = b * a; break;
                         case '/': result = b / a; break;
                    }
                    
                    push(result);
               }

               else if(temp[i] == '=') 
               {
                    if(temp[strlen(temp) - 2] == '=') 
                    {
                         temp[strlen(temp) - 2] = '\0';
                    }

                    c = pop();
                    for(i=0;temp[i] != '\0'; i++) printf("%c", temp[i]);
                    printf(" = %d", c);
                    printf("\n");
                    break;
               }
               i++;
          }
    }
    
    return 0;
}

int push(int a)
{

	node *ptr = (node *)malloc(sizeof(node));
	ptr->num = a;
	ptr->below = top;
	top = ptr;
	current++;
	
	return 1;
}

int pop(void)
{
	if (top == NULL) 
	{
        return -1;
    }
    
	int result;
	result = top->num;
	
	node *ptr;
	ptr = top;
	top = top->below;
	free(ptr);
	current--;
	
	return result;
}

















