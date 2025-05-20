
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

#define cooling_rate 0.0001
#define initial_temp 500
#define lowest_temp 0.000001
#define seed 61
#define n 9

double x[n] = {0,0,0,  1,1,1,  2,2,2 };
double y[n] = {0,1,2,  0,1,2,  0,1,2 };
int initial_route[n]={0,1,2,3,4,5,6,7,8};
int route[n], new_route[n], best_route[n];

double compute_new_route_distance()
{
   double delta_x, delta_y, distance;
   int i;

   distance=0;

   for (i=0;i<n-1;i++) 
   {
	  delta_x= x[new_route[i+1]] - x[new_route[i]];
	  delta_y= y[new_route[i+1]] - y[new_route[i]];

	   distance += sqrt(delta_x*delta_x + delta_y*delta_y);
	}

	delta_x= x[new_route[n-1]] - x[new_route[0]];
	delta_y= y[new_route[n-1]] - y[new_route[0]];

	distance += sqrt(delta_x*delta_x + delta_y*delta_y);
    return distance;
}

double compute_route_distance()
{
   double delta_x, delta_y, distance;
   int i;

   distance=0;

   for (i=0;i<n-1;i++) 
   {
	  delta_x= x[route[i+1]] - x[route[i]];
	  delta_y= y[route[i+1]] - y[route[i]];

	   distance += sqrt(delta_x*delta_x + delta_y*delta_y);
	}

	delta_x= x[route[n-1]] - x[route[0]];
	delta_y= y[route[n-1]] - y[route[0]];

	distance += sqrt(delta_x*delta_x + delta_y*delta_y);
    return distance;
}

void randomize_initial_route()
{
	int i, last=2*n, num, this1,this2,temp;
	
	for (i=0; i<last;i++)
	{
	   num= rand();
	   if (num==32767) this1 = n-1;
	   else this1= (int) ((num/32767.0)*n);
	
	   num= rand();
	   if (num==32767) this2 = n-1;
	   else this2= (int) ((num/32767.0)*n);
	
	   temp = initial_route[this1];
	   initial_route[this1] = initial_route[this2];
	   initial_route[this2] = temp;
	}
}


void randomize_new_route()
{
	int i, last=1, num, this1,this2, temp;
	
	for (i=0; i<last;i++)
	{
	   num= rand();
	   if (num==32767) this1 = n-1;
	   else this1= (int) ((num/32767.0)*n);
	
	   num= rand();
	   if (num==32767) this2 = n-1;
	   else this2= (int) ((num/32767.0)*n);
	
	   temp = new_route[this1];
	   new_route[this1] = new_route[this2];
	   new_route[this2] = temp;
	}
}

int main()
{
	int i;
	double  distance, best_distance, new_distance, threshold;
	double temp;
	double num;

	int debug1=0, debug2=0;

	srand(seed);
	randomize_initial_route();
    for (i=0;i<n;i++) route[i]= initial_route[i];

	distance = compute_route_distance();
	
	printf("\n Initial route: ");
	for (i=0;i<n;i++) printf ("%d  ", route[i]);
	printf("\n   Distance: %lf\n", distance);

    best_distance = distance;
	for (i=0;i<n;i++) best_route[i] = route[i];

	temp=initial_temp;

	while (temp>lowest_temp)
	{
	   for (i=0;i<n;i++) new_route[i] = route[i]; // start from existing route
	   randomize_new_route(); 
	   new_distance= compute_new_route_distance();

	   if (new_distance < distance)
	   { // unconditionally accept
		 distance = new_distance;
		 for (i=0;i<n;i++) route[i] = new_route[i];
	   }
	   else
	   {
		  num = rand()/32767.0;
		  threshold = exp (-(new_distance-distance) /temp);

		  if (num < threshold)
		  {  // conditionally accept not a better solution
			distance = new_distance;
		    for (i=0;i<n;i++) route[i] = new_route[i];
		  }
	   }

	   if (new_distance < best_distance)
	   { // update best distance
		  best_distance = new_distance;
		  for (i=0;i<n;i++) best_route[i] = new_route[i];
	   }

	debug1++;
	debug2=0;

	   temp = temp - temp*cooling_rate;
	 }

	printf("\n Proposed route: ");
	
	debug1++;
	debug2=0;

	for (i=0;i<n;i++) 
	{ printf ("%d  ", best_route[i]);
	  debug2 += best_route[i];
	}
	printf("\n   %d: sum=%d, Distance: %lf\n", debug1, debug2, best_distance);
 

  return 0;
} 


