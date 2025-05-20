#include<stdio.h>

int main()
{
    int count[26],i;
    char sentence[201];

    printf("Enter a sentence:");
    gets(sentence);

    for(i=0;i<26;i++) count[i] = 0;

    for(i=0;sentence[i] != '\0';i++)
    {
        if(sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            count[sentence[i] - 'a'] ++;
        }
    }

    for(i=0;i<26;i++)
    {
        if(count[i] != 0) printf("\n %c          %d", i + 97, count[i]);
    }

    return 0;
}