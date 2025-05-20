#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 20

int isPalindrome(char str[]) 
{
    int start = 0;
    int end = strlen(str) - 1;
    
    while (start < end) 
    {
        if (tolower(str[start]) != tolower(str[end])) 
        {
            return 0;  
        }
        start++;
        end--;
    }
    return 1;  
}

int main() {
    char word[MAX_LENGTH + 1];  
    printf("Enter a word to check if it's a palindrome (or press Enter to exit)\n");

    while (1) 
    {
        printf("Enter a word: ");
        gets(word);

        if (strlen(word) == 0) 
        {
            break;
        }

        if (isPalindrome(word)) 
        {
            printf("\"%s\" is a palindrome.\n", word);
        } 
        else 
        {
            printf("\"%s\" is not a palindrome.\n", word);
        }
    }

    printf("Session ended.\n");
    return 0;
}
