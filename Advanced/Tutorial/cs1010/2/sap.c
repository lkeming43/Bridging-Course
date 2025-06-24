#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char code[9]; 
    int mc; 
    char grade[3]; 
    char su[6]; 
} module_t;

int readResults(module_t mod[7]);
float computeSAP(module_t mod[7], int count);
float gradeToPt(char grade[]);

int main(void) 
{
    module_t modules[7]; 
    int num_modules;
    float sap; 
    num_modules = readResults(modules);
    sap = computeSAP(modules, num_modules);
    printf("SAP = %.2f\n", sap);
    return 0;
}

int readResults(module_t mod[7])
{
    FILE *indata = fopen("results.inf", "r");

    if(indata == NULL) 
    {
        printf("Invalid file");
        return 0;
    }

    int count, times = 0, j;
    fscanf(indata, "%d", &count);

    while (times < count) 
    {
        fscanf(indata, "%s", mod[times].code);       
        fscanf(indata, "%d", &mod[times].mc);        
        fscanf(indata, "%s", mod[times].grade);      
        fscanf(indata, "%s", mod[times].su);
        
       
        for (j = 0; mod[times].su[j] != '\0'; j++) 
        {
            if (mod[times].su[j] >= 'a' && mod[times].su[j] <= 'z') 
            {
                mod[times].su[j] = mod[times].su[j] - 'a' + 'A';
            }
        }

        times++;
    }
    

    return count;
}

float gradeToPt(char grade[])
{
    int i = 0;
    float pts[11] = {5.0, 5.0, 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0};
    char *grades[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D+", "D", "F"};

    while(strcmp(grade, grades[i]) != 0)
    {
        i++;
    }

    return pts[i];
}

float computeSAP(module_t mod[7], int count)
{
    int i;
    float cresum = 0, gradesum = 0;

    for (i = 0; i < count; i++) 
    {
        if (strcmp(mod[i].su, "TRUE") != 0)  
        {
            gradesum += mod[i].mc * gradeToPt(mod[i].grade);
            cresum += mod[i].mc;
        }
    }
    
    return gradesum / cresum;
}