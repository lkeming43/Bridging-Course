
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define cooling_rate 0.0001
#define initial_temp 600
#define lowest_temp 0.000001
#define seed 61
#define n 13

int x[n] = {0,0,1,1,2,3,3,4,4,5,5,6,6};
int y[n] = {6,5,3,0,2,6,4,3,1,6,0,7,3};
int initial_route[n] = {0,1,2,3,4,5,6,7,8,9,10,11,12};

int route[n], new_route[n], best_route[n];

int adj[n][n] = {0};

void setup_adjacency_matrix() 
{
    adj[0][1] = adj[1][0] = 1;
    adj[0][3] = adj[3][0] = 1;
    adj[0][5] = adj[5][0] = 1;
    adj[0][6] = adj[6][0] = 1;
    adj[0][11] = adj[11][0] = 1;

    adj[1][2] = adj[2][1] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[1][5] = adj[5][1] = 1;
    adj[1][6] = adj[6][1] = 1;
    adj[1][7] = adj[7][1] = 1;

    adj[2][3] = adj[3][2] = 1;
    adj[2][4] = adj[4][2] = 1;
    adj[2][7] = adj[7][2] = 1;

    adj[3][4] = adj[4][3] = 1;
    adj[3][5] = adj[5][3] = 1;
    adj[3][8] = adj[8][3] = 1;
    adj[3][10] = adj[10][3] = 1;

    adj[4][7] = adj[7][4] = 1;
    adj[4][8] = adj[8][4] = 1;

    adj[5][6] = adj[6][5] = 1;
    adj[5][7] = adj[7][5] = 1;
    adj[5][9] = adj[9][5] = 1;
    adj[5][11] = adj[11][5] = 1;

    adj[6][7] = adj[7][6] = 1;
    adj[6][9] = adj[9][6] = 1;

    adj[7][9] = adj[9][7] = 1;
    adj[7][10] = adj[10][7] = 1;
    adj[7][12] = adj[12][7] = 1;

    adj[8][10] = adj[10][8] = 1;
    adj[8][11] = adj[11][8] = 1;

    adj[9][10] = adj[10][9] = 1;
    adj[9][11] = adj[11][9] = 1;
    adj[9][12] = adj[12][9] = 1;

    adj[10][11] = adj[11][10] = 1;
    adj[10][12] = adj[12][10] = 1;

    adj[11][12] = adj[12][11] = 1;
}



void randomroute()
{
    int change1, change2, temp;
    change1 = rand() % n;
    change2 = rand() % n;
    for(int i = 0; i < n; i++) new_route[i] = route[i];

    temp = new_route[change1];
    new_route[change1] = new_route[change2];
    new_route[change2] = temp;
}

double compute_distance(int r[])
{
    int dx, dy, i;
    double distance = 0;

    for(i = 0; i < n - 1; i++)
    {
        if (adj[r[i]][r[i+1]] == 0) return 1e9;  // invalid path
        dx = x[r[i+1]] - x[r[i]];
        dy = y[r[i+1]] - y[r[i]];
        distance += sqrt(dx * dx + dy * dy);
    }

    // Return to starting point
    if (adj[r[n-1]][r[0]] == 0) return 1e9;
    dx = x[r[0]] - x[r[n - 1]];
    dy = y[r[0]] - y[r[n - 1]];
    distance += sqrt(dx * dx + dy * dy);

    return distance;
}

int main()
{
    int i;
    double distance, new_distance, best_distance, threshold, temp,num;

    temp = initial_temp;
    for(i = 0; i < n; i++) route[i] = initial_route[i];

    setup_adjacency_matrix();

    srand(seed);

    distance = compute_distance(route);
    best_distance = distance;

    while(temp > lowest_temp)
    {
        randomroute();
        new_distance = compute_distance(new_route);

        if(new_distance < distance)
        {
            distance = new_distance;
            for(i = 0; i < n; i++) route[i] = new_route[i];
        }
        else
        {
            num = rand() / (double)RAND_MAX;
            threshold = exp(-(new_distance - distance) / temp);

            if (num < threshold)
            {
                distance = new_distance;
                for(i = 0; i < n; i++) route[i] = new_route[i];
            }
        }

        if(distance < best_distance)
        {
            best_distance = distance;
            for(i = 0; i < n; i++) best_route[i] = route[i];
        }

        temp = temp - temp * cooling_rate;
    }

    printf("Best Route is: ");
    for(i = 0; i < n; i++) printf(" %d ", best_route[i]);
    printf("\nDistance: %lf\n", best_distance);

    return 0;
}





