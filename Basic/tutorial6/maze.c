#include <stdio.h>
#include <string.h>

#define N 4 

// Version 1: Move right/down only
int helperV1(int maze[N][N], int i, int j) 
{
    if (i == N-1 && j == N-1) return 1;
    if (j+1 < N && maze[i][j+1] == 0 && helperV1(maze, i, j+1)) return 1;
    if (i+1 < N && maze[i+1][j] == 0 && helperV1(maze, i+1, j)) return 1;
    return 0;
}

int mazePathV1(int maze[N][N]) 
{
    if (maze[0][0] != 0 || maze[N-1][N-1] != 0) return 0;
    return helperV1(maze, 0, 0);
}

// Version 2: Move in all directions
int helperV2(int maze[N][N], int i, int j, int visited[N][N]) 
{
    if (i == N-1 && j == N-1) return 1;
    if (i < 0 || i >= N || j < 0 || j >= N || maze[i][j] != 0 || visited[i][j]) return 0;
    visited[i][j] = 1;
    if (helperV2(maze, i-1, j, visited)) return 1;
    if (helperV2(maze, i+1, j, visited)) return 1;
    if (helperV2(maze, i, j-1, visited)) return 1;
    if (helperV2(maze, i, j+1, visited)) return 1;
    visited[i][j] = 0;
    return 0;
}

int mazePathV2(int maze[N][N]) 
{
    if (maze[0][0] != 0 || maze[N-1][N-1] != 0) return 0;
    int visited[N][N];
    memset(visited, 0, sizeof(visited));
    return helperV2(maze, 0, 0, visited);
}

// Add a main() function for testing
int main() 
{
    int maze[N][N] = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 0, 0}
    };

    printf("Version 1: %d\n", mazePathV1(maze));
    printf("Version 2: %d\n", mazePathV2(maze));
    return 0;
}