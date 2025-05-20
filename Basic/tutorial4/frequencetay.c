#include <stdio.h>
#include <string.h>

int main() 
{
    char sentence[201];
    int i, count[26];

    for (i = 0; i < 26; i++) 
        count[i] = 0;

    printf("Type a sentence and press enter key: ");
    gets(sentence);

    for (i = 0; sentence[i] != '\0'; i++) 
    {
        if (sentence[i] >= 'a' && sentence[i] <= 'z') 
            count[sentence[i] - 'a']++;
    }

    printf("\n\nAlphabet   Frequency\n");
    printf("=====================\n");
    for (i = 0; i < 26; i++) 
    {
        if (count[i] != 0) 
            printf("   %c        %3d\n", i + 97, count[i]);
    }

    return 0;
}
