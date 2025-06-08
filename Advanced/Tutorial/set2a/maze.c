#include<stdio.h>
#include<stdbool.h>
#define N 7

bool can_reach(int forest[N][N], int row, int col);

int main()
{
    int maze[7][7] = { 0, 0, 0, 0, 0, 0, 0,
                       0, 1, 1, 1, 1, 1, 0,
                       0, 1, 0, 1, 1, 1, 0,
                       0, 1, 1, 1, 0, 1, 0,
                       0, 1, 1, 0, 1, 1, 0,
                       0, 1, 1, 1, 1, 1, 0,
                       0, 0, 0, 0, 0, 0, 0 };

    if(can_reach(maze, 4, 4)) printf("Yes.");
    else printf("No");

    
}

//queue版
bool can_reach(int forest[N][N], int row, int col) 
{
    int visited[N][N] = { 0 };

    // 队列用二维数组保存每个位置坐标
    int queue[N * N][2];
    int front = 0, rear = 0;

    // 方向数组（上下左右）
    int dx[2] = { 0, 1 };
    int dy[2] = { 1, 0 };

    // 起点加入队列
    queue[rear][0] = 1;
    queue[rear][1] = 1;
    rear++;
    visited[1][1] = 1;

    while (front < rear) 
    {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;

        // 如果找到了 Grandma 的家
        if (x == row && y == col) 
        {
            return true;
        }

        // 扩展两个方向
        for (int i = 0; i < 2; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && forest[nx][ny] == 1 && !visited[nx][ny]) 
            {
                visited[nx][ny] = 1;
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;
            }
        }
    }

    return false;  // 搜索完也没找到 Grandma 的家
}


//stack版
bool can_reach(int forest[N][N], int row, int col) {
    // 递归内部使用的辅助函数，使用 static 保证只有一个函数
    static bool visited[N][N] = {false};

    // 起点坐标
    int x = 1, y = 1;

    // 递归栈模拟：用数组来作为手动递归（因为只能写一个函数）
    int stack[N * N][2];
    int top = 0;

    stack[top][0] = x;
    stack[top][1] = y;
    top++;
    visited[x][y] = true;

    while (top > 0) {
        top--;
        x = stack[top][0];
        y = stack[top][1];

        if (x == row && y == col)
            return true;

        // 向右
        if (y + 1 < N && forest[x][y + 1] == 1 && !visited[x][y + 1]) {
            visited[x][y + 1] = true;
            stack[top][0] = x;
            stack[top][1] = y + 1;
            top++;
        }

        // 向下
        if (x + 1 < N && forest[x + 1][y] == 1 && !visited[x + 1][y]) {
            visited[x + 1][y] = true;
            stack[top][0] = x + 1;
            stack[top][1] = y;
            top++;
        }
    }

    return false;
}
