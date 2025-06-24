#include<stdio.h>
#define INTEREST 0.0001

void compute(int pay, double own);

int main()
{
    int pay;
    double own;

    printf("Enter the fixed payment per month: ");
    scanf("%d", &pay);
    printf("Enter the amount of the loan: ");
    scanf("%lf", &own);

    compute(pay, own);

    return 0;
}

void compute(int pay, double own)
{
    int i = 0;

    while(own > 0)
    {
        own = own * INTEREST + own - pay;
        i++;
    }

    printf("\n\n%d months are needed to repay the loan.", i);
}

/*void compute(int pay, double own)
{
    static int i = 0;

    if(own < 0) 
    {
        printf("\n\n%d months are needed to repay the loan.", i);
        return;
    }
    
    i++;
    compute(pay, own * INTEREST + own - pay);
}*/