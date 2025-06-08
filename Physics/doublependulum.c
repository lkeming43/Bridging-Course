#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define G 9.81
#define L1 1.0   // 上摆长
#define L2 1.0   // 下摆长
#define M1 1.0   // 上摆质量
#define M2 1.0   // 下摆质量
#define DT 0.01
#define STEPS 10000

// 状态变量：theta1, omega1, theta2, omega2
typedef struct 
{
    double theta1, omega1;
    double theta2, omega2;
} State;

// 计算导数
void compute_derivatives(State s, State *dsdt) 
{
    double delta = s.theta2 - s.theta1;
    double denom1 = (M1 + M2) * L1 - M2 * L1 * cos(delta) * cos(delta);
    double denom2 = (L2 / L1) * denom1;

    dsdt->theta1 = s.omega1;
    dsdt->theta2 = s.omega2;

    dsdt->omega1 = (M2 * L1 * s.omega1 * s.omega1 * sin(delta) * cos(delta) +
                    M2 * G * sin(s.theta2) * cos(delta) +
                    M2 * L2 * s.omega2 * s.omega2 * sin(delta) -
                    (M1 + M2) * G * sin(s.theta1)) / denom1;

    dsdt->omega2 = (-M2 * L2 * s.omega2 * s.omega2 * sin(delta) * cos(delta) +
                    (M1 + M2) * G * sin(s.theta1) * cos(delta) -
                    (M1 + M2) * L1 * s.omega1 * s.omega1 * sin(delta) -
                    (M1 + M2) * G * sin(s.theta2)) / denom2;
}

// RK4更新
void rk4_step(State *s, double dt) 
{
    State k1, k2, k3, k4, temp;

    compute_derivatives(*s, &k1);

    temp.theta1 = s->theta1 + 0.5 * dt * k1.theta1;
    temp.omega1 = s->omega1 + 0.5 * dt * k1.omega1;
    temp.theta2 = s->theta2 + 0.5 * dt * k1.theta2;
    temp.omega2 = s->omega2 + 0.5 * dt * k1.omega2;
    compute_derivatives(temp, &k2);

    temp.theta1 = s->theta1 + 0.5 * dt * k2.theta1;
    temp.omega1 = s->omega1 + 0.5 * dt * k2.omega1;
    temp.theta2 = s->theta2 + 0.5 * dt * k2.theta2;
    temp.omega2 = s->omega2 + 0.5 * dt * k2.omega2;
    compute_derivatives(temp, &k3);

    temp.theta1 = s->theta1 + dt * k3.theta1;
    temp.omega1 = s->omega1 + dt * k3.omega1;
    temp.theta2 = s->theta2 + dt * k3.theta2;
    temp.omega2 = s->omega2 + dt * k3.omega2;
    compute_derivatives(temp, &k4);

    s->theta1 += dt / 6.0 * (k1.theta1 + 2*k2.theta1 + 2*k3.theta1 + k4.theta1);
    s->omega1 += dt / 6.0 * (k1.omega1 + 2*k2.omega1 + 2*k3.omega1 + k4.omega1);
    s->theta2 += dt / 6.0 * (k1.theta2 + 2*k2.theta2 + 2*k3.theta2 + k4.theta2);
    s->omega2 += dt / 6.0 * (k1.omega2 + 2*k2.omega2 + 2*k3.omega2 + k4.omega2);
}

int main() 
{
    State s = {PI / 2, 0.0, PI / 2, 0.0}; // 初始角度都为90度
    double t = 0.0;

    printf("time\ttheta1\ttheta2\n");

    for (int i = 0; i < STEPS; i++) {
        printf("%.4f\t%.6f\t%.6f\n", t, s.theta1, s.theta2);
        rk4_step(&s, DT);
        t += DT;
    }

    return 0;
}
