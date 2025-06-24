#include <stdio.h>
#include <math.h>

int zombie(double r0, int day); // 函数声明

int main() {
    double r0 = 0.5;
    int day = 6;

    int result = zombie(r0, day);
    printf("zombie(%.1f, %d) = %d\n", r0, day, result);

    return 0;
}

#include <math.h>

int zombie(double r0, int day) 
{
    int prev;
    if (day == 0) 
    {
        return 1;
    } 
    else 
    {
        prev = zombie(r0, day - 1);
        return prev + (int)ceil(r0 * prev);
    }
}

int zombie(double r0, int day) 
{
    int i;
    int result = 1;

    for(i=0;i<day;i++)
    {
        result = result + (int)ceil(r0 * result);
    }

    return result;
}

