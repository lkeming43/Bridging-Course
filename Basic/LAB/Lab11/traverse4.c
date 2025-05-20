
/* april 2012 q19 traversing a maze. 
   
   traverse4.c
   Travsere only four possibilities: down, right, up, left.
*/

#include <stdio.h>

#define N 6


void print (int this1[N][N])
{ 
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (this1[i][j]==0) printf (" ");
			else printf ("%c",219);
		}
			printf ("\n");
	}
}

// Your own recursive function for traversing in four directions
int solution(int maze[N][N], int x, int y) 
{
    if (x < 0 || x >= N || y < 0 || y >= N || maze[x][y] == 1) 
        return 0;

    if (x == N - 1 && y == N - 1) 
	{
        printf("\nThere is a path to reach the end of the maze\n");
        return 1;
    }

    maze[x][y] = 1;

    if (solution(maze, x + 1, y)) return 1;

	if (solution(maze, x - 1, y)) return 1;

	if (solution(maze, x, y - 1)) return 1;

    if (solution(maze, x, y + 1)) return 1;

    maze[x][y] = 0;

    return 0;
}


int main()
{

	
	int maze1 [N][N]= {0, 0, 1, 0, 0, 1,           
	                   1, 0, 1, 0, 1, 1,
	                   1, 0, 0, 0, 1, 0,
	                   1, 0, 1, 1, 1, 1,
					   1, 0, 0, 0, 0, 0,
	                   1, 1, 1, 1, 1, 0};

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

	print (maze3);
    printf ("\n\nFour directional Traversal:");

	if (!solution(maze3, 0, 0)) 
        printf("\nNo Path Found\n");


}
