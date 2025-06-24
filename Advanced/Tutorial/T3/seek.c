#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *indata;
    char ch;

    // 创建并写入测试文件（为了演示完整过程）
    indata = fopen("test.txt", "w");
    if (indata == NULL) {
        perror("Failed to create file");
        return 1;
    }
    fputs("study*hard$&!", indata);
    fclose(indata);

    // 以只读模式重新打开文件
    indata = fopen("test.txt", "r");
    if (indata == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // 第一次读取
    fread(&ch, sizeof(char), 1, indata);
    printf("1. ch = %c\n", ch); // -> 's'

    // 跳过 6 个字符（当前位置是 index 1，跳到 index 7）
    fseek(indata, (long)6, SEEK_CUR);
    fread(&ch, sizeof(char), 1, indata);
    printf("2. ch = %c\n", ch); // -> 'r'

    // 回退 3 个字符（当前位置是 index 8，退到 index 5）
    fseek(indata, (long)-3, SEEK_CUR);
    fread(&ch, sizeof(char), 1, indata);
    printf("3. ch = %c\n", ch); // -> '*'

    // 从文件尾部往回 5 个字符（文件末尾 index = 13，跳到 index = 8）
    fseek(indata, (long)-5, SEEK_END);
    fread(&ch, sizeof(char), 1, indata);
    printf("4. ch = %c\n", ch); // -> 'r'

    // 当前位置是 index = 9，跳过 3 个字符到 index = 12
    fseek(indata, (long)3, SEEK_CUR);
    fread(&ch, sizeof(char), 1, indata);
    printf("5. ch = %c\n", ch); // -> '!'

    // 设置位置到 index = 4
    fseek(indata, (long)4, SEEK_SET);
    fread(&ch, sizeof(char), 1, indata);
    printf("6. ch = %c\n", ch); // -> 'y'

    fclose(indata);
    return 0;
}
