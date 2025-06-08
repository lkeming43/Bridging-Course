#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 21

void readWords(char bank[][MAX], int* maxWordSize, int* wordCount);
void prtWords(char bank[][MAX], int maxWordSize, int wordCount);
void findBigrams(char bank[][MAX], int maxWordSize, int wordCount, int bigramTable[26][26]);
void bfInfo(int bigramTable[26][26]);
void repeatBigram(char bank[][MAX], int maxWordSize, int wordCount, int bigramTable[26][26]);

char bank[100][MAX];

int main()
{
    int i, j, wordCount = 0, maxWordSize = 0, table[26][26];

    readWords(bank, &maxWordSize, &wordCount);
    prtWords(bank, maxWordSize, wordCount);
    findBigrams(bank, maxWordSize, wordCount, table);
    bfInfo(table);
    repeatBigram(bank, maxWordSize, wordCount, table);
}

void readWords(char bank[][MAX], int* maxWordSize, int* wordCount) 
{
    FILE *indata = fopen("/Users/kemingliu/Desktop/cProgramming/Advanced/Project/Project4/Words3.txt", "r");
    if (indata == NULL) 
    {
        printf("\nFail openning.");
        return;
    }
 
    int i = 0, j =0;

    while (*wordCount < 100 && fscanf(indata, "%20s", bank[i]) == 1) 
    {
        
        if (strlen(bank[i]) > *maxWordSize) *maxWordSize = strlen(bank[i]);

        for(j=0;bank[i][j] != '\0';j++)
        {
            bank[i][j] = tolower(bank[i][j]);
            if(bank[i][j] == '.') bank[i][j] = '\0';
        }

        (*wordCount)++;
        i++;
    }

    fclose(indata);
}

void prtWords(char bank[][MAX], int maxWordSize, int wordCount)
{
    printf("\nWord Bank:\n\n++++++++++\n\n");

    for (int i = 0; i < wordCount; ++i)
    {
        printf("%s\n", bank[i]);
    }

    printf("\nNumber of words read: %d\n", wordCount);
    printf("\nThe length of the longest word: %d\n\n", maxWordSize);
}

void findBigrams(char bank[][MAX], int maxWordSize, int wordCount, int bigramTable[26][26])
{
    int i, j, indexi, indexj;

    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            bigramTable[i][j] = 0;
        }
    }

    printf("\nBigrams found:\n\n++++++++++");
    for(i=0;i<wordCount;i++)
    {
        printf("\n\n%s: ", bank[i]);
        for(j=0;j<maxWordSize;j = j+1)
        {
            if(bank[i][j+1] != '\0') 
            {
                printf("%c%c ", bank[i][j], bank[i][j+1]);
                indexi = bank[i][j] - 'a';
                indexj = bank[i][j+1] - 'a';
                bigramTable[indexi][indexj]++;
            }
        }
    }

    
}

void bfInfo(int bigramTable[26][26])
{
    int i, j, flagC[26], flagR[26], ans = 0;
    printf("\n\nBigram Frequency Table:\n\n+++++++++++++++++++++++\n\n");

    for(i=0;i<26;i++) flagC[i] = 0;
    for(i=0;i<26;i++) flagR[i] = 0;

    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++) 
        {
            if(bigramTable[i][j] != 0) 
            {
                flagR[i] = 1;
                flagC[j] = 1;
            }
        }
    }

    printf("  |");
    for(j=0;j<26;j++)
    {
        if(flagC[j] == 1) 
        {
            printf("%3c", j+97);
            ans++;
        }
    }
    printf("\n\n--+");
    for(i=0;i<ans;i++) printf("---");
    printf("\n");
    
    for(i=0;i<26;i++)
    {
        if(flagR[i]) printf("\n%2c|", i+97);
        
        for(j=0;j<26;j++)
        {
            if(flagC[j] && flagR[i]) printf("%3d", bigramTable[i][j]);
        }
    }

}

void repeatBigram(char bank[][MAX], int maxWordSize, int wordCount, int bigramTable[26][26])
{
    int i, j, p = 0, q, index = 0, flag = 0, count = 0;
    char comp[100][3], temp[3];

    typedef struct wordnum
    {
        int num;
        char word[3];
    }node;

    node result[100] = {{0}}, chag;

    printf("\n\nRepeated Bigrams Statistics:\n\n++++++++++++++++++++++++++++\n\n");
    
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            if(bigramTable[i][j] > 1) 
            {
                comp[p][0] = i + 'a';
                comp[p][1] = j + 'a';
                comp[p][2] = '\0';
                p++;
            }
        }
    }

    for(q=0;q<p;q++)
    {
        flag = 0;
        for(i=0;i<wordCount;i++)
        {
            count = 0;
            for(j=0;j<strlen(bank[i]) - 1;j++)
            {
                temp[0] = bank[i][j];
                temp[1] = bank[i][j+1];
                temp[2] = '\0';

                if(strcmp(comp[q], temp) == 0)
                {
                    count++;
                    if(count > 1)
                    {
                        strcpy(result[index].word, temp);
                        result[index].num++;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag) index++;
    }

    if(index>0)
    {
        for (i = 0; i < index; i++) 
        {
            for (int j = 0; j < index - 1 - i; j++) 
            {
                if (result[j].num < result[j + 1].num) 
                {
                    chag = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = chag;
                }
            }
        }

        for(i=0;i<index;i++)
        {
            printf("\nNumber of words for which \"%s\" is found repeated: %d", result[i].word, result[i].num);
        }
    }

    else printf("No bigram is found repeated in any word.");
}


 
