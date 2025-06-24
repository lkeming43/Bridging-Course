#include<stdio.h>

typedef struct{
    float height;
    float mass;
    float bmi;
    int riskType;
} record;

int main()
{
    record body;

    printf("Enter your height: ");
    scanf("%f", &body.height);
    printf("Enter your mass: ");
    scanf("%f", &body.mass);

    body.bmi = (int)((body.mass / (body.height * body.height)) * 10 + 0.5) / 10.0;//手动四舍五入 或者roundf(num * 10) / 10;，round是取到最近的整数

    if(body.bmi <= 18.4) body.riskType = -1;
    else if(body.bmi > 18.4 && body.bmi < 22.9) body.riskType = 0;
    else if(body.bmi > 23.0 && body.bmi < 27.4) body.riskType = 1;
    else body.riskType = 2;

    printf("BMI is %2f", body.bmi);
    printf("\nRisktype is %d", body.riskType);
    return 0;
}