#include<stdio.h>
#define f(x) (((x)*(x)*(x)*(x)*(x)*(x)*(x))-297)
#define tolerance 0.0000000001
#define last_round 1000000

int main()
{
    int rounds=0;
    double a=1.0,b=3.0,m;
    m=(a+b)/2;
    while (((f(m)>tolerance || f(m)<-tolerance)) && rounds<=last_round)
    {
        if (f(m)*f(a)>0) a=m;
        else b=m;
        m=(a+b)/2;
        rounds++;
    }
    printf("%f",m);
    return 0;
}