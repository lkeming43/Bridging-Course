#include <stdio.h>
#include <string.h>

#define MAX_WORDS 25
#define MAX_LENGTH 16 

void swap(char *s1, char *s2) 
{
    char temp[MAX_LENGTH];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}

void sortWords(char words[MAX_WORDS][MAX_LENGTH], int count) 
{
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (strcmp(words[i], words[j]) > 0) 
            {
                swap(words[i], words[j]);
            }
        }
    }
}

int main() 
{
    FILE *file = fopen("words.inf", "r");

    if (file == NULL) 
    {
        printf("Error opening file.\n");
        return 1;
    }

    char words[MAX_WORDS][MAX_LENGTH];
    int count = 0;

    while (count < MAX_WORDS && fscanf(file, "%15s", words[count]) == 1) 
    {
        count++;
    }
    fclose(file);

    sortWords(words, count);

    printf("Sorted in lexicographical order\n");
    printf("================================\n");
    for (int i = 0; i < count; i++) 
    {
        int m=i+1;
        printf("%3d.                  ",m);
        printf("%s\n", words[i]);
    }

    return 0;
}
