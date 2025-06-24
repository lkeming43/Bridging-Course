#include<stdio.h>

void flipLeftRight(int square[][10], int size, int index)
{
    int i, j, temp;

    for(i=0;i<size;i++)
    {
        for(j=0;j<size/2;j++)
        {
            if(i == size-index-1 || i == index || j == index || j ==size-index-1)
            {
                temp = square[i][j];
                square[i][j] = square[i][size - j - 1];
                square[i][size - j - 1] = temp;
            }
        }
    }
}

void printMatrix(int square[][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%3d", square[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int square[10][10] = {
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9, 10},
        {11,12, 13,14,15},
        {16,17, 18,19,20},
        {21,22, 23,24,25}
    };

    int size = 5;

    printf("Original matrix:\n");
    printMatrix(square, size);

    // Flip ring 0
    flipLeftRight(square, size, 0);

    printf("\nAfter flipping ring 0 (outermost):\n");
    printMatrix(square, size);

    // Flip ring 1
    flipLeftRight(square, size, 1);

    printf("\nAfter flipping ring 1 (inner):\n");
    printMatrix(square, size);

    return 0;
}