#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void bubbleSort(int arr[], int count) {
    int i, flag;
    int temp;

    while (count > 1) {
        flag = 0;
        for (i = 0; i < count - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                // 交换
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) break; // 如果本轮没发生交换，说明已经有序
        count--; // 减少比较范围
    }
}

int main() {
    int arr[SIZE];
    int i;

    srand(time(NULL));

    printf("排序前：\n");
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, SIZE);

    printf("排序后：\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
