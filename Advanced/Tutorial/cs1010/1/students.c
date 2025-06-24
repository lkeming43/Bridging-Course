#include<stdio.h>
#define S 10
#define M 5

struct student
{
    int matricnumber;
    int modules[M];
    int count;
}students[S];

typedef struct 
{
    int student_matric[S];  
    int grades[S];          
    int count;             
    int modulecode;        
} module;

module mod[M];          

void compute(struct student students[])
{
    int i, j, k, p, num;
    double cap;

    for(i=0;i<S;i++)
    {
        cap = 0.0;

        num = students[i].count;
        for(j=0;j<num;j++)
        {
            for(k=0;k<M;k++) if(students[i].modules[j] == mod[k].modulecode) break;//k第几个mod
            for(p=0;p<mod[k].count;p++) if(mod[k].student_matric[p] == students[i].matricnumber) break;//mod里的第p个学生是ta

            cap = cap + mod[k].grades[p];
        }

        cap = cap / num;

        printf("Student %d: CAP = %.2f\n", students[i].matricnumber, cap);
    }
}
