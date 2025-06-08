#include<stdio.h>
#define N 50

typedef struct {
    int x;
    int y;
    } coord_t;

void readMap(int map[][N], int *m, int *n);
void prtMap(int map[][N], int m, int n);
void read2Corners(coord_t *c1, coord_t *c2);
void findCorners(coord_t c1, coord_t c2, coord_t corners[4]);
void fillSpace(int map[][N], coord_t corners[4]);
void drawBorders(int map[][N], int rows, int cols);
void touch(int map[][N], int rows, int cols);


int main()
{
    int choose, map[N][N], m, n;
    coord_t c1, c2, corners[4];
    readMap(map, &m, &n);
    prtMap(map, m, n);

    c1.x = -1;
    
    while(1)
    {
        printf("\nEnter operation number [0 to 4]; other integer to get out: ");
        scanf("%d", &choose);

        switch(choose)
        {
            case 0: 
            {
                printf("\nPrint the current map: \n\n+++++++++++++++++++++\n");
                prtMap(map, m, n); 
                break;
            }
            case 1:
            {
                printf("\nFind corners.\n\n+++++++++++++\n");
                read2Corners(&c1, &c2);
                findCorners(c1, c2, corners);

                printf("\nTop-left corner: %d, %d.", corners[0].y, corners[0].x);
                printf("\nTop-right corner: %d, %d.", corners[1].y, corners[1].x);
                printf("\nBottom-left corner: %d, %d.", corners[2].y, corners[2].x);
                printf("\nBottom-right corner: %d, %d.\n", corners[3].y, corners[3].x);

                break;
            }
            case 2:
            {
                if(c1.x == -1)
                {
                    read2Corners(&c1, &c2);
                    findCorners(c1, c2, corners);
                    printf("\nTop-left corner: %d, %d.", corners[0].y, corners[0].x);
                    printf("\nTop-right corner: %d, %d.", corners[1].y, corners[1].x);
                    printf("\nBottom-left corner: %d, %d.", corners[2].y, corners[2].x);
                    printf("\nBottom-right corner: %d, %d.\n", corners[3].y, corners[3].x);
                }

                fillSpace(map, corners);
                break;
            }
            case 3:
            {
                printf("\nDisplay map borders. \n\n++++++++++++++++++++\n");
                drawBorders(map, m, n);
                break;
            }
            case 4:
            {
                printf("\nMap Touching Operation. \n\n+++++++++++++++++++++++\n");

                touch(map, m, n);
                break;
            }
            default: 
            {
                printf("\nThe end.");
                return 0;
            }
        }
    }

}

void readMap(int map[][N], int *m, int *n)
{
    int i, j;
    printf("Read in number of rows: ");
    scanf("%d", m);
    printf("Read in number of columns: ");
    scanf("%d", n);

    printf("\nRead in the map of size %d X %d\n", *m, *n);

    for(i=0;i<*m;i++)
    {
        for(j=0;j<*n;j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
}

void prtMap(int map[][N], int m, int n)
{
    int i, j;
    
    printf("\n   ");
    for(i=0;i<n;i++) printf("%3d", i);
    printf("*");

    printf("\n  +");
    for(i=0;i<n;i++) printf("---");
    printf("*\n");

    for(i=0;i<m;i++)
    {
        printf("%2d|", i);
        for(j=0;j<n;j++) printf("%3d", map[i][j]);
        printf("*\n\n");
    }
}

void read2Corners(coord_t *c1, coord_t *c2)
{
    printf("\nPlease enter the first corner: ");
    scanf("%d%d", &c1->y, &c1->x);

    printf("\nPlease enter the other corner: ");
    scanf("%d%d", &c2->y, &c2->x);
}

void findCorners(coord_t c1, coord_t c2, coord_t corners[4])
{
    int ymax, ymin, xmax, xmin;

    if(c1.y >= c2.y) 
    {
        ymax = c1.y; 
        ymin = c2.y;
    }
    else 
    {
        ymax = c2.y; 
        ymin = c1.y;
    }
    if(c1.x >= c2.x)
    {
        xmax = c1.x; 
        xmin = c2.x;
    } 
    else 
    {
        xmax = c2.x;
        xmin = c1.x;
    }

    corners[0].y = ymin;
    corners[0].x = xmin;
    corners[1].y = ymin;
    corners[1].x = xmax;
    corners[2].y = ymax;
    corners[2].x = xmin;
    corners[3].y = ymax;
    corners[3].x = xmax;
}

void fillSpace(int map[][N], coord_t corners[4])
{
    int ob, i, j;

    printf("\n\nEnter number to be filled in: ");
    scanf("%d", &ob);

    for(i=corners[0].y;i<corners[4].y;i++)
    {
        for(j=corners[0].x;j<corners[4].y;j++) map[i][j] = ob;
    }
}

void drawBorders(int map[][N], int rows, int cols)
{
    int r, c, i, j;
    r = (rows*2) + 1;
    c = (cols*2) + 1;
    char border[r][c], ob;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i%2 == 0) border[i][j] = ' ';
            else 
            {
                if(j%2 == 0) border[i][j] = ' ';
                else border[i][j] = map[(i-1)/2][(j-1)/2] + '0';
            }
        }
    }

    printf("\nRead in a number: ");
    scanf("%*c%c", &ob);

    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            if(map[i][j] == (ob - '0'))
            {
                border[2*i][(2*j)+1] = '-';
                border[(2*i)+2][(2*j)+1] = '-';
                border[(2*i)+1][(2*j)] = '|';
                border[(2*i)+1][(2*j)+2] = '|';
            }
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(border[i][j] == ob && border[i+2][j] == ob) border[i+1][j] = ' ';
            if(border[i][j] == ob && border[i][j+2] == ob) border[i][j+1] = ' ';
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%c", border[i][j]);
        }
        printf("*\n");
    }
}

void touch(int map[][N], int rows, int cols)
{
    coord_t c1, c2, corners[4];
    coord_t touch;
    int new, old, ymin, ymax, xmin, xmax, r, c, newR, newC, i;
    int queue[N*N][2];
    int front = 0, rear = 0;
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    printf("Please enter the first corner: ");
    scanf("%d %d", &c1.y, &c1.x);
    printf("Please enter the corresponding diagonal corner: ");
    scanf("%d %d", &c2.y, &c2.x);
    findCorners(c1, c2, corners);

    printf("Enter the coordinate of a location to touch: ");
    scanf("%d %d", &touch.y, &touch.x);

    printf("Choose a number to spread: ");
    scanf("%d", &new);

    ymin = corners[0].y;
    ymax = corners[3].y;
    xmin = corners[0].x;
    xmax = corners[3].x;

    old = map[touch.y][touch.x];

    queue[rear][0] = touch.y;
    queue[rear][1] = touch.x;
    rear++;
    map[touch.y][touch.x] = new;

    while (front < rear) 
    {
        r = queue[front][0];
        c = queue[front][1];
        front++;

        for (i = 0; i < 4; i++) 
        {
            newR = r + dr[i];
            newC = c + dc[i];
            if (newR >= ymin && newR <= ymax && newC >= xmin && newC <= xmax && map[newR][newC] == old) 
            {
                map[newR][newC] = new;
                queue[rear][0] = newR;
                queue[rear][1] = newC;
                rear++;
            }
        }
    }
}

/*void touch(int map[][N], int rows, int cols)
{
    coord_t c1, c2, corners[4], touch;
    int virus, key, ref[rows][cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            ref[i][j] = 0; // 初始化
    read2Corners(&c1, &c2);
    findCorners(c1, c2, corners);
    printf("Enter the coordinate of a location to touch: ");
    scanf("%d%d", &touch.x, &touch.y);
    printf("Choose a number to spread: ");
    scanf("%d", &virus);
    key = map[touch.x][touch.y];
    map[touch.x][touch.y] = virus;

    // 在该限定函数内无法进行递归操作:(, 只能每次都遍历map，并记录是否成功拓展，若有拓展则需继续进行
    int change;
    ref[touch.x][touch.y] = 1;
    do
    {
        change = 0;
        for (int i = corners[0].x; i <= corners[3].x; i++)
        {
            for (int j = corners[0].y; j <= corners[3].y; j++)
            {
                if (ref[i][j])
                {
                    // 上方
                    if (i - 1 >= corners[0].x && map[i - 1][j] == key && ref[i - 1][j] != 1)
                    {
                        ref[i - 1][j] = 1;
                        map[i - 1][j] = virus;
                        change = 1;
                    }

                    // 下方
                    if (i + 1 <= corners[3].x && map[i + 1][j] == key && ref[i + 1][j] != 1)
                    {
                        ref[i + 1][j] = 1;
                        map[i + 1][j] = virus;
                        change = 1;
                    }

                    // 左边
                    if (j - 1 >= corners[0].y && map[i][j - 1] == key && ref[i][j - 1] != 1)
                    {
                        ref[i][j - 1] = 1;
                        map[i][j - 1] = virus;
                        change = 1;
                    }

                    // 右边
                    if (j + 1 <= corners[3].y && map[i][j + 1] == key && ref[i][j + 1] != 1)
                    {
                        ref[i][j + 1] = 1;
                        map[i][j + 1] = virus;
                        change = 1;
                    }
                }
            }
        }
    } while (change);
}*/