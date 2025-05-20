#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20  
#define MIN -2.55
#define MAX 3.76


double generate_random(double min, double max) 
{
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

int main() 
{
    srand(time(NULL)); 

    printf("%d Random Numbers between %.2f and %.2f:\n", N, MIN, MAX);
    for (int i = 0; i < N; i++) 
	{
        double random_number = generate_random(MIN, MAX);
        printf("%.2f\n", random_number);
    }

    return 0;
}
