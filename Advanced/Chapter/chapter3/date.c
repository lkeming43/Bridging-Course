#include<stdio.h>

unsigned pack_date(int day1, int month1, int year1,
                   int day2, int month2, int year2)
{
    unsigned packed;
    day1 <<= 27;    // 左移27位
    month1 <<= 23;  // 左移23位
    year1 %= 100;   // 年份取后两位
    year1 <<= 16;   // 左移16位
    day2 <<= 11;    // 左移11位
    month2 <<= 7;   // 左移7位
    year2 %= 100;   // 年份取后两位
    packed = day1 | month1 | year1 | day2 | month2 | year2;  // 合并所有位
    return packed;
}

void print_bit(unsigned word)
{
    int n = sizeof(int) * 8, i;
    unsigned mask = 1 << (n - 1);  // 创建一个掩码，指向最高位
    for (i = 0; i < n; i++)
    {
        if (word & mask)
            printf("1");
        else
            printf("0");
        word <<= 1;  // 左移，查看下一个位
    }
    putchar('\n');
}

void unpack_date(unsigned packed)
{
    int day, month, year;
    day = packed >> 27;                          // 右移27位得到第一天
    month = (packed & 0x07800000) >> 23;         // 提取月份
    year = (packed & 0x007f0000) >> 16;          // 提取年份
    printf("Date 1: %02d/%02d/%02d\n", day, month, year);

    day = (packed & 0x0000f800) >> 11;           // 提取第二天的日、月、年
    month = (packed & 0x00000780) >> 7;
    year = packed & 0x007f;
    printf("Date 2: %02d/%02d/%02d\n", day, month, year);
}

int main()
{
    int d1, m1, y1, d2, m2, y2;
    unsigned packed;
    printf("Enter the first date in the form dd/mm/yyyy: ");
    scanf("%d/%d/%d", &d1, &m1, &y1);
    printf("Enter the second date in the form dd/mm/yyyy: ");
    scanf("%d/%d/%d", &d2, &m2, &y2);
    
    packed = pack_date(d1, m1, y1, d2, m2, y2);
    printf("The packed bit pattern is: ");
    print_bit(packed);
    
    unpack_date(packed);
    
    return 0;
}
