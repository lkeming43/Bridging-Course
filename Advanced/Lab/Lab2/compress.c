#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *indata = fopen("digit.inf", "r");
    FILE *outdata = fopen("packeddigit.ouf", "wb");

    if (!indata || !outdata)
    {
        printf("File opening failed");
        return 1;
    }

    char digits[8];
    unsigned int packed;
    char decoded[8], ch;

    while (fread(digits, sizeof(char), 8, indata) == 8)
    {
        packed = 0;
        for (int i = 0; i < 8; i++)
        {
            packed = packed << 4;
            packed = packed | ((digits[i] - '0') & 0xF);
        }
        fwrite(&packed, sizeof(unsigned int), 1, outdata);
    }

    fclose(outdata);

    outdata = fopen("packeddigit.ouf", "rb");
    if (!outdata)
    {
        printf("File opening failed");
        return 1;
    }

    rewind(indata);
    printf("Original digits from outdata:\n");
    while (fread(&ch, sizeof(char), 1, indata) == 1) 
    {
        printf("%c", ch);
    }

    printf("\n\nAter being compressed:\n");
    while (fread(&packed, sizeof(unsigned int), 1, outdata) == 1)
    {
        for (int i = 7; i >= 0; i--)
        {
            decoded[i] = (packed & 0xF) + '0';
            packed = packed >> 4;
        }
        for (int i = 0; i < 8; i++)
        {
            printf("%c", decoded[i]);
        }
    }

    printf("\n");

    fclose(outdata);

    return 0;
}
