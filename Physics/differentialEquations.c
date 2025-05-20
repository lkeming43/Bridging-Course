#include <stdio.h>
#include <math.h>

#define G 9.81
#define L 1.0
#define STEP 0.01
#define MAX_T 10.0

void euler(double theta0, double omega0, double h, double t_max)
{
    double t = 0.0;
    double theta = theta0;
    double omega = omega0;

    printf("t\t\ttheta (rad)\n");
    while (t <= t_max)
    {
        printf("%.2f\t\t%.6f\n", t, theta);

        double new_theta = theta + h * omega;
        double new_omega = omega - h * (G / L) * sin(theta);

        theta = new_theta;
        omega = new_omega;
        t += h;
    }
}

int main()
{
    double theta0 = 0.2;
    double omega0 = 0.0;

    euler(theta0, omega0, STEP, MAX_T);
    return 0;
}
