#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(2 * x) - x - 6;
}

double secant(double x0, double x1, double tol, int max_iter) {
    double x2, fx0, fx1;
    int iter = 0;

    while (iter < max_iter) {
        fx0 = f(x0);
        fx1 = f(x1);

        if (fx1 - fx0 == 0) {
            printf("Zero difference encountered. Try different initial points.\n");
            return x1;
        }

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);

        if (fabs(x2 - x1) < tol) {
            printf("Convergence achieved after %d iterations.\n", iter);
            return x2;
        }

        x0 = x1;
        x1 = x2;

        iter++;
    }

    printf("Maximum iterations reached.\n");
    return x1;
}

int main() {
    double x0 = 0.25, x1 = 1.2; 
    double tolerance = 1e-6; 
    int max_iterations = 100; 

    double root = secant(x0, x1, tolerance, max_iterations);
    printf("Estimated root: %.6f\n", root);
    return 0;
}
