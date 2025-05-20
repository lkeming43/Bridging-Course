#include <stdio.h>

#define TOLERANCE 1e-8
#define PI 3.14159265358979323846


double maclaurin_sin(double x) 
{
    double term = x, sum = x;
    int k = 1;

    while (term > TOLERANCE || term < -TOLERANCE) {
        term *= -x * x / ((2 * k) * (2 * k + 1)); 
        sum += term;
        k++;
    }

    return sum;
}

int main() {
    double degrees = 135.0;
    double radians = degrees * PI / 180.0; 

    double result = maclaurin_sin(radians);
    printf("sin(135 degrees) = %.8f\n", result);
    
    return 0;
}
