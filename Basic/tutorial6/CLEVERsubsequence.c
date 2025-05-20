#include<stdio.h>
#include<string.h>

//clever method
int check(char *s1,char *s2)
{
    int i=0,j=0;
    while(s2[j] != '\0')
    {
        if(s1[i] == s2[j]) i++;
        j++;
        if(s1[i] == '\0') return 1;
    }

    return 0;
}

int main()
{
    int countS = 0, countC = 0,n;
    char s[100],c[100];
    
    printf("Enter a sequent of characters: ");
    fgets(s,sizeof(s),stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("\nEnter another sequent of characters: ");
    fgets(c,sizeof(c),stdin);
    c[strcspn(c, "\n")] = '\0';

    while(s[countS] != '\0' ) countS++;
    while(c[countC] != '\0' ) countC++;

    if(countS<=countC)
    {
        n = check(s,c);

        if(n == 0) printf("\nThe sequnce of \"%s\" is not the subsequence of \"%s\"", s,c);
        else printf("\nThe sequnce of \"%s\" is the subsequence of \"%s\"", s,c);
    }

    if(countC<countS)
    {
        n = check(c,s);

        if(n == 0) printf("\nThe sequnce of \"%s\" is not the subsequence of \"%s\"", c,s);
        else printf("\nThe sequnce of \"%s\" is the subsequence of \"%s\"", c,s);
    }

    return 0;


}