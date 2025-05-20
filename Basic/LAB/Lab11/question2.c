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
    float x;
    double result = 0.0,term;

    printf("Please Enter the Degree of the Angle:");
    scanf("%f",&x);

    x = (x/180)*PI;

    for(n=0;n<MAX;n++)
    {
        term = (pow(-1,n)*pow(x,(2*n)+1)) / factorial((2*n)+1);

        if (fabs(term) < 1e-8) break;

        result += term;
    }

    printf("sin(x) ≈ %f\n",result);

    return 0;
}