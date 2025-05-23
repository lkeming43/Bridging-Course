#include<stdio.h>

int main(int argc, char *argv[])
{
    int i=0, j;
    char *word;

    for(i = 1;i<argc;i++)
    {
        word = argv[i];
        for(j=0; word[j] != '\0'; j++)
        {
            if(word[j] >= 97 && word[j] <= 122)
            {
                printf("%c", word[j] - 32 );
            }

            else printf("%c", word[j]);
        }

        printf(" ");
       
    }
    
    return 0;
}