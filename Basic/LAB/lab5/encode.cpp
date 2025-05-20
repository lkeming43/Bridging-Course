#include <stdio.h>

int main() {
    char ch;
    char result[100];
    int i=0;

    printf("Enter your message (press Enter to finish): ");

    while (scanf("%c", &ch) == 1 && ch != '\n') 
	{  
        switch (ch) 
		{
            case 'a': ch = '!'; break;
            case 'e': ch = '$'; break;
            case 'i': ch = '#'; break;
            case 'o': ch = '*'; break;
            case 'u': ch = '&'; break;
            default: break;
        }
		result [i++]=ch;
    }

    printf("encoded message is: %s",result);
    return 0;
}
