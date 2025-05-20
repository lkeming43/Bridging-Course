

#include<stdio.h>
#include<math.h>

#define f(x) (exp(2*(x)) - (x) -6)
#define last_round 100
#define start 0.25
#define next 1.2
#define tolerance 0.000001

int main()
{
   double x0,x1, x2;
   int rounds;

   rounds=1;
   x0=start;
   x1=next;
   
   while ( (f(x1) > tolerance || f(x1) < -tolerance) && rounds<=last_round)
   {
      printf ("Secant %d  x=%lf   f(x)=%lf\n", rounds, x1, f(x1));
      x2 = x1 - f(x1)/((f(x1)-f(x0))/(x1-x0));
     
	  x0=x1;
	  x1 = x2;
      rounds++;
   }

   printf ("Secant %d  x=%lf   f(x)=%lf\n", rounds, x1, f(x1));
   return 0;
}
