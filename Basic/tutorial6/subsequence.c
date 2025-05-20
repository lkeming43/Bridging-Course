#include<stdio.h>
#include<string.h>

int main()
{
    int countS = 0, countC = 0,i,j,n = 0,check;
    char s[100],c[100];
    
    printf("Enter a sequent of characters: ");
    fgets(s,sizeof(s),stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("\nEnter another sequent of characters: ");
    fgets(c,sizeof(c),stdin);
    c[strcspn(c, "\n")] = '\0';
    
    while(s[countS] != '\0' ) countS++;
    while(c[countC] != '\0' ) countC++;
    
    if(countS<countC)
    {
        check = 0;
        for(i=0;i<countS;i++)
        {
            for(j=check;j<countC;j++)
            {
                if(s[i] == c[j]) 
                {
                    n++;
                    check = j + 1;
                    break;
                }

            }
        }

        if(n<countS) printf("\nThe sequnce of \"%s\" is not the subsequence of \"%s\"", s,c);

        else printf("\nThe sequnce of \"%s\" is the subsequence of \"%s\"", s,c);

    }

    else
    {
        check = 0;
        for(i=0;i<countC;i++)
        {
            for(j=check;j<countS;j++)
            {
                if(c[i] == s[j]) 
                {
                    n++;
                    check = j + 1;
                    break;
                }

            }
        }

        if(n<countC) printf("\nThe sequnce of \"%s\" is not the subsequence of \"%s\"", c,s);

        else printf("\nThe sequnce of \"%s\" is the subsequence of \"%s\"", c,s);
    }

    
    return 0;
}