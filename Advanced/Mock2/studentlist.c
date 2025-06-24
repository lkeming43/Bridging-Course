#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    int num;
    char name[21];
    float grades;
}node;

void liststu(FILE *indata);
void addstu(FILE *indata);
void deletestu(FILE *indata);

int main()
{
    int i, choice, flag = 1;

    FILE *indata = fopen("stu.dat", "rb+");
    if (!indata) 
    {
        indata = fopen("stu.dat", "wb+");
    }

    while(flag)
    {
        printf("\n1. List all students.");
        printf("\n2. Add a new student.");
        printf("\n3. Delete a studnet.");
        printf("\n4. Quit.");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: liststu(indata); break;
            case 2: addstu(indata); break;
            case 3: deletestu(indata); break;
            case 4: flag = 0; break;
            default: flag = 0; break;
        }
    }

    return 0;
}

void liststu(FILE *indata)
{
    rewind(indata);

    int i;
    node *stu = (node *)malloc(sizeof(node));
    while(fread(stu, sizeof(node), 1, indata) == 1)
    {
        if(stu->num != -1 && stu->num != 0)
        {    
            printf("\n\nStudnet's number is %d", stu->num);
            printf("\nStudnet's name is %s.", stu->name);
            printf("\nStudent's grades is %f.", stu->grades);
        }
    }
    free(stu);

    printf("\n");
}

void addstu(FILE *indata)
{
    node *stu = (node *)malloc(sizeof(node));
    printf("\nEnter student's number: ");
    scanf("%d", &stu->num);
    printf("Enter studnet's name: ");
    scanf("%20s", stu->name);
    printf("Enter studnet's grades: ");
    scanf("%f", &stu->grades);

    fseek(indata, (long) stu->num * sizeof(node), SEEK_SET);
    fwrite(stu, sizeof(node), 1, indata);

}

void deletestu(FILE *indata)
{
    int i;
    node blank = {-1, "", 0};

    printf("\nEnter the no. of student: ");
    scanf("%d", &i);

    fseek(indata, (long) i * sizeof(node), SEEK_SET);
    fwrite(&blank, sizeof(node), 1, indata);

    printf("\nDeleted.");
}

