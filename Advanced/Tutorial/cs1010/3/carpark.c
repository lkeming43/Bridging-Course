#include<stdio.h>
#include<stdlib.h>
#define seed 11
#define MAX_PARKING_UNIT 9000
#define LENGTH_OF_CAR 8
#define MAX_NUM_ROUND 10000

int find(int units[], int location);

int main()
{
    int units[MAX_PARKING_UNIT] = {0};
    int flag = 1, location, times = 0, i, count = 0, start;

    srand(seed);

    while(times < MAX_NUM_ROUND)
    {
        location = rand() % (MAX_PARKING_UNIT - LENGTH_OF_CAR + 1);
        start = find(units, location);
        if(start != -1)
        {
            for (i = 0; i < LENGTH_OF_CAR; i++)
            {
                units[start + i] = 1;
            }
        }

        times++;
    }

    for(i = 0; i < MAX_PARKING_UNIT; i++) 
    {
        if(units[i]) count++;
    }

    printf("Rate is %.2lf%%\n", (double)count / MAX_PARKING_UNIT * 100);
}

int find(int units[], int location)
{
    int i;

    if (location > MAX_PARKING_UNIT - LENGTH_OF_CAR)
        return -1;

    for (i = 0; i < LENGTH_OF_CAR; i++)
    {
        if (units[location + i] != 0)
            return find(units, location + 1);
    }

    return location;
}