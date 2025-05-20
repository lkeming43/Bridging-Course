#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define cooling_rate 0.0001
#define initial_temp 500
#define lowest_temp 0.000001
#define seed 61
#define n 13

int x[n] = {0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6};
int y[n] = {6, 5, 3, 0, 2, 6, 4, 3, 1, 6, 0, 7, 3};
int initial_route[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int route[n], new_route[n], best_route[n];

void randomroute()
{
    int change1, change2, temp;
    change1 = rand() % n;
    change2 = rand() % n;

    // Copy the current route to new_route
    for (int i = 0; i < n; i++) new_route[i] = route[i];

    // Swap two random cities in new_route
    temp = new_route[change1];
    new_route[change1] = new_route[change2];
    new_route[change2] = temp;
}

double compute_distance(int r[])
{
    int dx, dy, i;
    double distance = 0;

    for (i = 0; i < n - 1; i++)
    {
        dx = x[r[i + 1]] - x[r[i]];
        dy = y[r[i + 1]] - y[r[i]];

        distance += sqrt((dx) * (dx) + (dy) * (dy));
    }

    dx = x[r[0]] - x[r[n - 1]];
    dy = y[r[0]] - y[r[n - 1]];
    distance += sqrt(dx * dx + dy * dy);

    return distance;
}

int main()
{
    int i, num;
    double distance, new_distance, best_distance, threshold, temp;
    
    temp = initial_temp;
    for (i = 0; i < n; i++) route[i] = initial_route[i];

    srand(seed);

    distance = compute_distance(route);  // Compute the initial distance
    best_distance = distance;
    for (i = 0; i < n; i++) best_route[i] = route[i]; // Initialize best_route

    while (temp > lowest_temp)
    {
        randomroute();
        new_distance = compute_distance(new_route);  // Compute distance for the new route

        if (new_distance < distance)
        {
            distance = new_distance;
            for (i = 0; i < n; i++) route[i] = new_route[i];
        }
        else
        {
            num = rand() / (double)RAND_MAX;
            threshold = exp(-(new_distance - distance) / temp);

            if (num < threshold)
            {
                distance = new_distance;
                for (i = 0; i < n; i++) route[i] = new_route[i];
            }
        }

        // Update best_route if a better solution is found
        if (distance < best_distance)
        {
            best_distance = distance;
            for (i = 0; i < n; i++) best_route[i] = route[i];
        }

        // Decrease temperature
        temp = temp - temp * cooling_rate;
    }

    // Output the best route and its distance
    printf("Best Route is: ");
    for (i = 0; i < n; i++) printf(" %d ", best_route[i]);
    printf("\nDistance: %lf\n", best_distance);

    return 0;
}
