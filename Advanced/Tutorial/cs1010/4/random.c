#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define MIN 2
#define MAX 10
#define RANGE_COUNT 5  

int main()
{
    int arr[SIZE], freq[RANGE_COUNT] = {0}, i, even, index;
    int maxFreq;
    int mostFrequent;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        even = (rand() % RANGE_COUNT) * 2 + MIN;
        arr[i] = even;

        index = (even - MIN) / 2;
        freq[index]++;
    }

    maxFreq = freq[0];
    mostFrequent = MIN;

    for (i = 1; i < RANGE_COUNT; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            mostFrequent = MIN + i * 2;
        }
    }

    printf("Most frequent value: %d\n", mostFrequent);

    return 0;
}
