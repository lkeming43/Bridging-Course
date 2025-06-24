#include<stdio.h>
#include<string.h>

int period(char str[])
{
    int i = 1, j, len;

    len = strlen(str);

    while(i <= len)
    {
        if(len % i == 0)
        {
            char check[i];
            strncpy(check, str, i);

            for(j=0;j * i < len;j++)
            {
                if(strncmp(check, str + j*i, i) != 0) break;
            }
        }

        if(j*i == len) return i;

        i++;
    }

    return len;
}

int main(void) 
{
    char str1[] = "abcabcabcabc";
    char str2[] = "aaaa";
    char str3[] = "abababx";
    char str4[] = "xyz";

    printf("Period of \"%s\" is %d\n", str1, period(str1)); // 3
    printf("Period of \"%s\" is %d\n", str2, period(str2)); // 1
    printf("Period of \"%s\" is %d\n", str3, period(str3)); // 7
    printf("Period of \"%s\" is %d\n", str4, period(str4)); // 3

    return 0;
}