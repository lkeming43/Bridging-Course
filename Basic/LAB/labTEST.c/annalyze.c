#include<stdio.h>
float result[31];

float findMax (float a1, float a2, float a3, float a4);
float computeaverage(float *start, float *end);

int main()
{
    float a1,a2,a3,a4;
    int i = 0;
    FILE *indata;

    indata = fopen("/Users/kemingliu/Desktop/READING.INF","r");

    if(indata == NULL)
    {
        printf("Invalid file");
        return 1;
    }

    for(i=0;i<31;i++)
    {
        result[i] = 0;
    }

    i = 0;
    while(fscanf(indata,"%f%f%f%f",&a1,&a2,&a3,&a4)==4)
    {
        result[i] = findMax(a1,a2,a3,a4);
        i++;
    }
    
    for(i=0;result[i] != 0;i++)
    {
        printf("%2d %.2f\n", i+1, result[i]);
    }
    
    printf("\nThe average temperature for first five days is %.2f", computeaverage(&result[0],&result[4]));
    printf("\nThe average temperature for last five days is %.2f", computeaverage(&result[i-5],&result[i-1]));


    return 0;
}

float findMax (float a1, float a2, float a3, float a4)
{
    float max;
    max = a1;
    
    if(a2>max) max = a2;
    if(a3>max) max = a3;
    if(a4>max) max = a4;

    return max;
}

float computeaverage(float *start, float *end)
{
    float *i, sum = 0.0;
    for(i=start;i<=end;i++)
    {
        sum = sum + *i;
    }

    return sum/5.0;
}