#include<stdio.h>
#include<string.h>

void swap(char *ch1, char *ch2);
void reverse(char ch[], int i, int n);

int main()
{
    char ch[100];
    int i;

    printf("Enter a word: ");
    fgets(ch,sizeof(ch),stdin);
    ch[strcspn(ch, "\n")] = '\0';

    i = strlen(ch);

    reverse(ch,i-1,0);
    printf("\nReverse is %s.", ch);

    return 0;
}

void swap(char *ch1, char *ch2)
{
    char temp;

    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void reverse(char ch[], int i, int n)
{
    if (n >= i) return;

    swap(&ch[i], &ch[n]);

    if(n<i)
    {
        reverse(ch, i-1, n+1);
    }
    
}


