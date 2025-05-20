#include <stdio.h>
#include <stdlib.h>

#define N 10
#define SEED 17

// 非递归堆调整函数
void heapify(int x[], int n, int i);

int main()
{
    int i;
    int x[N];
    srand(SEED);

    // 生成随机数
    for(i = 0; i < N; i++)
        x[i] = rand() % 100;

    // 输出原始数组
    printf("Original array:\n");
    for(i = 0; i < N; i++)
        printf("%d ", x[i]);
    printf("\n");

    // 构建最大堆
    for(i = N / 2 - 1; i >= 0; i--)
        heapify(x, N, i);

    // 进行堆排序
    for(i = N - 1; i >= 1; i--)
    {
        // 交换堆顶元素与当前末尾元素
        int temp = x[0];
        x[0] = x[i];
        x[i] = temp;

        // 调整堆
        heapify(x, i, 0);
    }

    // 输出排序后的数组
    printf("Sorted array:\n");
    for(i = 0; i < N; i++)
        printf("%d ", x[i]);
    printf("\n");

    return 0;
}

void heapify(int x[], int n, int i)
{
    int largest = i;        // 当前最大元素的位置
    int left = 2*i + 1;     // 左子节点
    int right = 2*i + 2;    // 右子节点
    int temp;

    while (1) 
    {
        int largest = i;    // 重新初始化最大的元素

        // 如果左子节点大于父节点
        if (left < n && x[left] > x[largest])
            largest = left;

        // 如果右子节点大于父节点
        if (right < n && x[right] > x[largest])
            largest = right;

        // 如果最大元素不是父节点，则交换并继续调整
        if (largest != i)
        {
            temp = x[i];
            x[i] = x[largest];
            x[largest] = temp;

            // 更新当前节点为需要调整的子节点
            i = largest;
            left = 2*i + 1;
            right = 2*i + 2;
        }
        else {
            break;  // 如果堆已经满足条件，结束循环
        }
    }
}
