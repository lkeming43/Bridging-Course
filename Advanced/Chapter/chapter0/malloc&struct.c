#include<stdio.h>
#include<stdlib.h>

typedef struct test
{
    char school_name[10];
    char student_name[10];
    int stunum;
}node;

int main()
{
    node *list[3];
    int i;

    for(i=0;i<3;i++)
    {
        list[i] = (node*)malloc(sizeof(node));

        printf("\nEnter student's number: ");
        scanf("%d", &list[i]->stunum);

        printf("Enter school name: ");
        scanf("%s", list[i]->school_name);

        printf("Enter student's name: ");
        scanf("%s", list[i]->student_name);
    }
    
    for(i=0;i<3;i++)
    {
        printf("\n\n%d", list[i]->stunum);

        printf(" %s", list[i]->school_name);

        printf(" %s", list[i]->student_name);
    }

    for (int i = 0; i < 3; i++) 
    {
        free(list[i]);
    }

    return 0;
}
