#include<stdio.h>
#include<string.h>

void reverse(char str[], int start, int end)
{
    char temp;
    if(start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        reverse(str, ++start, --end);
    }
}

void swapSubstrings(char str[], int len_a, int len_b)
{
    reverse(str, 0, strlen(str) - 1);

    reverse(str, 0, len_b - 1);

    reverse(str, len_b, strlen(str) - 1);
}

int main(void)
{
    char str[] = "programming";
    reverse(str, 3, 7);
    printf("Reversed string: %s\n", str);  

    char str2[] = "Hamburger";  
    swapSubstrings(str2, 3, 6);
    printf("%s\n", str2);      

    return 0;
}
