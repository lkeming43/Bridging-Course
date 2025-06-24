#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    int num;
    char name[20];
    float grades;
}node;

int count = 0;

int main()
{
    int i;
    node hsy[3] = { {101, "Alice", 88.0},
                    {102, "Bob", 76.5},
                    {103, "Charlie", 92.0}};
    node *stu = (node *)malloc(sizeof(node));

    FILE *outdata = fopen("students.dat", "wb");
    if (!outdata) 
    {
        perror("Failed to open file");
        return 1;
    }

    
    for(i=0;i<3;i++) fwrite(&hsy[i], sizeof(node), 1, outdata);

    fclose(outdata);

    FILE *indata = fopen("students.dat", "rb");
    if (!indata) 
    {
        perror("Failed to open file");
        return 1;
    }

    for(i=0;i<3;i++)
    {
        fread(stu, sizeof(node), 1, indata);
        printf("\n\nStudnet's number is %d", stu->num);
        printf("\nStudnet's name is %s.", stu->name);
        printf("\nStudent's grades is %.2f.", stu->grades);
    }

    /*fseek(indata, (long) 2*sizeof(node), SEEK_SET);
    fread(stu, sizeof(node), 1, indata);
    printf("\n\nStudnet's number is %d", stu->num);
    printf("\nStudnet's name is %s.", stu->name);
    printf("\nStudent's grades is %f.", stu->grades);*/

    return 0;
}

