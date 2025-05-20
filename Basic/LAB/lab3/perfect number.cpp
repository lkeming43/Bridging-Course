#include <stdio.h>

int main() {
    int num, i, sum;

    for (;;) 
		{ 
        printf("Enter 0 to stop or enter a positive integer: ");
        scanf("%d", &num);

        if (num == 0) 
			{
            printf("Program exited.\n");
            break; 
        	}

        if (num < 0) 
			{
            printf("Negative numbers cannot be perfect numbers.\n");
            continue;
        	}

        sum = 0;
        for (i = 1; i <= num / 2; i++) 
		{
            if (num % i == 0)  sum += i;
            
        }

        if (sum == num)
            printf("%d is a perfect number.\n", num);
        else
            printf("%d is not a perfect number.\n", num);
    }

    return 0;
}
