#include<stdio.h>

int main()
{
    char input;
    do
    {
        char ch1[15],ch2[15],count1[26],count2[26];
        int i,n,check=0;

        printf("Enter first word: ");
        gets(ch1);
        printf("Enter second word: ");
        gets(ch2);

        for(i=0; ch1[i] != '\0' ;i++)
        {
            if (ch1[i] >= 'a' && ch1[i] <= 'z')
            count1[ch1[i] - 'a']++;
        }

        for(i=0; ch2[i] != '\0' ;i++)
        {
            if (ch2[i] >= 'a' && ch2[i] <= 'z')
            count2[ch2[i] - 'a']++;
        }

        for(i=0;i<26;i++) 
        {
            if(count1[i]==count2[i])  check=1;
        }
    
    
        if(check==1) printf("\n\"%s\" and \"%s\" are anagrams. ", ch1,ch2);
        else printf("\n\"%s\" and \"%s\" are not anagrams. ", ch1,ch2);

        printf("\nEnter * if you want to stop: ");
        scanf("%*c%c", &input);

    } while( input != '*');


}