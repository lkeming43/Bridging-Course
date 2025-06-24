#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *data_ptr;
    char current_char;

    // 创建并写入测试文件
    data_ptr = fopen("ttt", "w");
    if (data_ptr == NULL) {
        perror("无法创建文件");
        return 1;
    }
    fputs("xyz12345", data_ptr);  // 文件内容，共8个字符，索引0-7
    fclose(data_ptr);

    // 重新以只读模式打开
    data_ptr = fopen("ttt", "r");
    if (data_ptr == NULL) {
        perror("无法打开文件");
        return 1;
    }

    // 跳过前3个字符 ('x','y','z')，指向 '1'
    fseek(data_ptr, 3L, SEEK_CUR);
    fread(&current_char, sizeof(char), 1, data_ptr);
    printf("After SEEK_CUR +3: %c\n", current_char);  // 应该是 '1'

    // fseek 到 -1（SEEK_SET），无效，等价于指向文件开头，再读
    fseek(data_ptr, -1L, SEEK_SET);  // C 标准中此为 undefined，但多数实现视为从头开始
    fread(&current_char, sizeof(char), 1, data_ptr);
    printf("After SEEK_SET -1 (treated as 0): %c\n", current_char);  // 一般输出 'x'

    // 从文件末尾回退4个字符：指向 '3'
    fseek(data_ptr, -4L, SEEK_END);
    fread(&current_char, sizeof(char), 1, data_ptr);
    printf("After SEEK_END -4: %c\n", current_char);  // 应该是 '3'

    // 从当前位置跳过2个字符：跳过 '4','5'，将指针移出文件尾
    fseek(data_ptr, 2L, SEEK_CUR);
    size_t result = fread(&current_char, sizeof(char), 1, data_ptr);
    if (result == 0)
        printf("After SEEK_CUR +2: EOF reached\n");   // 已超出文件尾
    else
        printf("After SEEK_CUR +2: %c\n", current_char);

    fclose(data_ptr);
    return 0;
}
