#include<stdio.h>
#include<math.h>
#define MAX 1000
#define PI 3.14159265

double factorial(int n)
{
    if(n>0) return n*factorial(n-1);

    else return 1;
}

int main()
{
    int n;
    double result = 0.0,term;

    for(n=0;n<MAX;n++)
    {
        term = (2 * pow(-1, n) * pow(PI, 2 * n)) / factorial(2 * n);

        if (fabs(term) < 1e-8) break;

        result += term;
    }

    printf("Result is: %3f",result);

    return 0;
}