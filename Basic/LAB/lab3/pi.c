// pi.c

# include <stdio.h>
# include <stdlib.h>

# define last 1000000

# define seed 31
main()
{
  long n=0, i;
  double x,y;

  srand(seed);

  for (i=0;i<last;i++)
  {
   x = rand()/32767.0;
   y = rand()/32767.0;

   if (x*x + y*y < 1.0) n++;
  }

  printf ("\n pi=  %f",n/(last/4.0));

  return 0;
}