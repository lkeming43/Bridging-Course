
// newton.c

// This is the numerical method used to approximate the root of an equation.
// This method may not work if the starting point does not lead to the convergence
// of the solution, or the gradient of the tangential lines fluctuates.

// Need to specify the last round because the rate of convergence can be very slow
// for a special group of equations, and you have to mean enough is enough. The
// algorithm can also be trapped in infinite loop.

#include<stdio.h>
#include<math.h>

#define f(x) (exp(2*(x)) - (x) -6)
#define fpr(x) (2*exp(2*(x)) -1)
#define last_round 100
#define start 0.25
#define tolerance 0.000001

int main()
{
   double x1, x2;
   int rounds;

   rounds=1;
   x1=start;
   
   while ( (f(x1) > tolerance || f(x1) < -tolerance) && rounds<=last_round)
   {
      printf ("%d  x=%lf   f(x)=%lf\n", rounds, x1, f(x1));
      x2 = x1 - f(x1)/fpr (x1);
      x1 = x2;
      rounds++;
   }

   printf ("%d  x=%lf   f(x)=%lf\n", rounds, x1, f(x1));
   return 0;
}
