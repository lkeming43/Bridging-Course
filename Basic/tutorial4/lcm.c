#include <stdio.h>

int hcf(int a, int b) 
{
    int temp;
    while (b != 0) 
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) 
{
    return (a * b) / hcf(a, b);
}

int main() 
{
    int numbers[6];
    int count;
    char choice;

    do 
    {
        printf("How many integers do you want to enter (between 2 and 6)? ");
        scanf("%d", &count);

        printf("Enter %d integers, separated by spaces: ", count);
        
        for (int i = 0; i < count; i++) 
        {
            scanf("%d", &numbers[i]);
        }

        int current_hcf = numbers[0];
        int current_lcm = numbers[0];

        for (int i = 1; i < count; i++) 
        {
            current_hcf = hcf(current_hcf, numbers[i]);
            current_lcm = lcm(current_lcm, numbers[i]);
        }

        printf("Highest Common Factor (HCF): %d\n", current_hcf);
        printf("Least Common Multiple (LCM): %d\n", current_lcm);

        printf("Do you want to continue with another set of integers? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
