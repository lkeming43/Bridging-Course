#include <stdio.h>

#define PI 3.14159265
#define TOLERANCE 1e-8

int main()
{
	double t = 2.0; 
    double tol = 2.0; 
    int n = 1;
	
	for(n=1;tol > TOLERANCE || tol < -TOLERANCE;n++)
	{

	tol=tol*(-1)*(PI*PI)/((2*n)*(2*n-1));
	t=t+tol;
	
	}
	
	printf("result is %f",t);
	return 0;
}


