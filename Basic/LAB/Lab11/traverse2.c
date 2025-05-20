#include <stdio.h>

#define N 6

void print(int this1[N][N]) 
{ 
    int i, j;
    for (i = 0; i < N; i++) 
	{
        for (j = 0; j < N; j++) 
		{
            if (this1[i][j] == 0) 
                printf(" ");
            else 
                printf("%c", 219);
        }
        printf("\n");
    }
}

int solution(int maze[N][N], int x, int y) 
{
    /*if (x < 0 || x >= N || y < 0 || y >= N || maze[x][y] == 1) 
        return 0;

    if (x == N - 1 && y == N - 1) 
	{
        return 1;
    }

    maze[x][y] = 1;

    if (solution(maze, x + 1, y)) return 1;

    if (solution(maze, x, y + 1)) return 1;

    maze[x][y] = 0;

    return 0;*/
    maze[x][y] = 1;

    if( x==N-1 && y==N-1) return 1;
    if( (x+1)<N && maze[x+1][y] == 0) 
        solution(maze, x+1, y);
        return 1;
    if( (y+1)<N && maze[x][y+1] == 0) 
        solution(maze, x, y+1);
        return 1;
    maze[x][y] = 0;

    return 0;

}

int main() 
{
    int maze1[N][N] = 
	{
        {0, 0, 1, 0, 0, 1},           
        {1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0}
    };

	int maze2 [N][N]= {0, 0, 1, 0, 0, 0,           
					   1, 0, 1, 0, 1, 0,
					   1, 0, 0, 0, 1, 0,
					   1, 1, 1, 1, 1, 0,
					   1, 1, 1, 1, 1, 0,
					   1, 1, 1, 1, 1, 0};

	int maze3 [N][N]= {0, 0, 1, 0, 0, 0,           
					   1, 0, 1, 0, 1, 0,
					   1, 0, 0, 0, 1, 0,
					   1, 1, 1, 1, 1, 0,
					   1, 1, 1, 1, 1, 1,
					   1, 1, 1, 1, 1, 0};

    printf("\n\nTwo directional Traversal:\n");
    print(maze1);

    if (!solution(maze1, 0, 0)) 
        printf("\nNo Path Found.\n");
    else printf("\nThere is a path.\n");

    return 0;
}
