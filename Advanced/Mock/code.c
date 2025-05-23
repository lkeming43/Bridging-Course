#include<stdio.h>

unsigned encode(unsigned this1);
unsigned decode(unsigned result);

int main()
{
    unsigned original, code;

    printf("Enter a number to encode: ");
    scanf("%x", &original);
    printf("The number is: %08X %u", original, original);

    code = encode(original);

    printf("\nCode is: %08X %u", code, code);

    code = decode(code);

    printf("\nOriginal number is: %08X %u", code, code);

    return 0;
}

/*unsigned encode(unsigned this1)
{
    unsigned middle, reverse = 0, temp, result;
    int i;

    middle = ((this1 << 8) >> 16) << 8;

    for(i = 0;i < 32;i++)
    {
        reverse = reverse | (this1 & 1);
        reverse = reverse << 1;
        this1 = this1 >> 1;
    }

    temp = (reverse >> 8) << 24;
    result = (middle | temp) | ((reverse << 24)>>24);

    return result;
}*/

unsigned encode(unsigned this1) //分别读取每一位
{
    unsigned x03, x4, x5, x6, x7;

    // 提取最低的 16 位（h1 h0），左移 8 位
    x03 = (this1 & 0x0000FFFF) << 8;

    // 提取 h4（第 3 字节低位的 nibble），左移 12
    x4 = (this1 & 0x000F0000) << 12;

    // 提取 h5（第 3 字节高位的 nibble），左移 4
    x5 = (this1 & 0x00F00000) << 4;

    // 提取 h6（第 4 字节低位的 nibble），右移 20
    x6 = (this1 & 0x0F000000) >> 20;

    // 提取 h7（第 4 字节高位的 nibble），右移 28
    x7 = (this1 & 0xF0000000) >> 28;

    return (x4 | x5 | x03 | x6 | x7);
}


unsigned decode(unsigned result)
{
    unsigned x03, x4, x5, x6, x7;
    
    x03 = (result & 0x00FFFF00) >> 8;
    x4 = (result & 0xF0000000) >> 12;
    x5 = (result & 0x0F000000) >> 4;
    x6 = (result & 0x000000F0) << 20;
    x7 = (result & 0x0000000F) << 28;

    return ( x03 | x4 | x5 | x6 | x7);
}