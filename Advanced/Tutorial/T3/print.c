#include <stdio.h>
#include <stdlib.h>

struct tool
{
    int rec_Num;
    char name[16];
    int quantity;
    float cost;
};

int main()
{
    FILE *binary = fopen("hardware.dat", "rb"); // 以二进制读取模式打开
    if (!binary)
    {
        perror("Failed to open hardware.dat");
        return 1;
    }

    struct tool t;
    printf("Contents of hardware.dat:\n");
    printf("RecNum\tName\t\tQuantity\tCost\n");
    printf("--------------------------------------------------\n");

    // 循环读取直到文件结束
    while (fread(&t, sizeof(struct tool), 1, binary) == 1)
    {
        printf("%d\t%-15s\t%d\t\t%.2f\n", t.rec_Num, t.name, t.quantity, t.cost);
    }

    fclose(binary);
    return 0;
}