#include <stdio.h>
#include <stdlib.h>  // 推荐包含以使用 exit()

// 定义客户数据结构
struct clientData {
    int acctNum;             // 账户号
    char lastName[15];       // 姓
    char firstName[10];      // 名
    float balance;           // 余额
};

int main() {
    struct clientData blankClient = {0, "", "", 0.0};  // 初始化为空记录
    FILE *outdata;
    int i;

    printf("Size of struct: %d\n", (int)sizeof(blankClient));  // 显示结构体大小

    // 打开文件（注意路径写法和引号）
    if ((outdata = fopen("credit.dat", "wb")) == NULL) {
        printf("File could not be opened.\n");
        exit(1);  // 退出程序
    }

    // 写入 100 个空白记录
    for (i = 1; i <= 100; i++) {
        fwrite(&blankClient, sizeof(struct clientData), 1, outdata);
    }

    fclose(outdata);  // 正确关闭文件
    return 0;
}
