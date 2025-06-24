#include<stdio.h>
#include<stdlib.h>
#define BUFFER 10

typedef struct 
{
    int no;
    char* name;       
    float* scores;  
    int course_count;
} student;

void liststu(student *group);
void addstu(student **group);
void deletestu(student *group);
void sort_by_id(student *group);

int count = 0, time = 1;

int main()
{
    int flag = 1, choice;
    student *group = (student*)calloc(BUFFER, sizeof(student));

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
            case 1: liststu(group); break;
            case 2: addstu(&group); break;//addstu内要改变group指向的内存的大小，所以不能直接传入group，需要传入指向group的指针，才能改变group指向的内存的大小
            case 3: deletestu(group); break;
            case 4: flag = 0; break;
            default: flag = 0; break;
        }
    }

    return 0;
}

void liststu(student *group)
{
    int i, j;

    for (i = 0; i < count; i++)
    {
        printf("\n----------------------------");
        printf("\nStudent #%d", i + 1);
        printf("\nID: %d", group[i].no);
        printf("\nName: %s", group[i].name);
        printf("\nNumber of courses: %d", group[i].course_count);
        printf("\nScores: ");
        for (j = 0; j < group[i].course_count; j++) 
        {
            printf("%.2f ", group[i].scores[j]);
        }
        printf("\n");
    }
}


void addstu(student **group)
{
    if(count % 10 == 0)
    {
        *group = (student*)realloc(*group, (++time) * BUFFER * sizeof(student));
    }

    printf("\nEnter student ID: ");
    scanf("%d", &(*group)[count].no);
    printf("Enter student name: ");
    (*group)[count].name = (char *)malloc(21 * sizeof(char));
    scanf("%20s", (*group)[count].name);
    printf("Enter number of courses: ");
    scanf("%d", &(*group)[count].course_count);

    (*group)[count].scores = (float *)calloc((*group)[count].course_count, sizeof(float));
    if ((*group)[count].scores == NULL) 
    {
        printf("Failed to allocate memory for grades.\n");
        exit(1);
    }

    for (int i = 0; i < (*group)[count].course_count; i++) 
    {
        printf("Enter grade for course %d: ", i + 1);
        scanf("%f", &(*group)[count].scores[i]);
    }

    count++;

    sort_by_id(*group); //这个group不是主函数里的group，是在addstu内部的指向group的一个指针，是**group，所以需要先解引用成*group
}

void deletestu(student *group)
{
    int num, i, j;
    printf("\nEnter the no of student to delete: ");
    scanf("%d", &num);

    for (i = 0; i < count; i++) if (group[i].no == num) break;

    if (i == count) 
    {
        printf("Student not found.\n");
        return;
    }
    
    free(group[i].name);
    free(group[i].scores);


    for (j = i; j < count - 1; ++j) 
    {
        group[j] = group[j + 1];
    }

    count--;
}

void sort_by_id(student *group) 
{
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (group[i].no > group[j].no) 
            {
                student temp = group[i];
                group[i] = group[j];
                group[j] = temp;
            }
        }
    }
}
