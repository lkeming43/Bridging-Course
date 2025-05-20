#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double f(double x) 
{
    return x * x; 
}

int main() 
{
    double x_min = 2.0, x_max = 5.0;
    double y_max = 25.0;
    
    int n_points = 1000000000;
    
    int count_under_curve = 0;

    srand(time(NULL));

    for (int i = 0; i < n_points; i++) 
	{
        double x = x_min + (x_max - x_min) * ((double)rand() / RAND_MAX);
        double y = ((double)rand() / RAND_MAX) * y_max;

        if (y <= f(x)) 
		{
            count_under_curve++;
        }
    }

    double area_rect = (x_max - x_min) * y_max;
    
    double integral_approx = area_rect * ((double)count_under_curve / n_points);

    printf("Approximated value of the integral: %.6f\n", integral_approx);

    return 0;
}
