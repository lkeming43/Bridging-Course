#include <stdio.h>

int main() 
{
    char ch;
    char result[100];
    int i=0;

    printf("Enter price (press Enter to finish: ");

    while (scanf("%c", &ch) == 1 && ch != '\n') 
	{  
        switch (ch) 
		{
            case '0': ch = 'X'; break;
            case '1': ch = 'S'; break;
            case '2': ch = 'R'; break;
            case '3': ch = 'E'; break;
            case '4': ch = 'T'; break;
            case '5': ch = 'U'; break;
            case '6': ch = 'P'; break;
            case '7': ch = 'M'; break;
            case '8': ch = 'O'; break;
            case '9': ch = 'C'; break;
            default: break;
        }
		result [i++]=ch;
    }

    printf("\nEncoded price is: %s",result);
    return 0;
}