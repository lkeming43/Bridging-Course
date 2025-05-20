#include<stdio.h>
#include<string.h>

void reverse(char word[],int start,int end);
void swap(char *a, char *b);

int main()
{
    char ch[100];
    int i,n;

    for(i=0;i<100;i++) ch[i] = 0;

    printf("Enter a word: ");
    fgets(ch,sizeof(ch),stdin);
    ch[strcspn(ch, "\n")] = '\0';

    for(n=0;n<100 && ch[n] != 0;n++);
    char word[n];

    for(i=0;i<n;i++) word[i] = ch[i];

    reverse(word,0,n-1);

    for(i=0;i<n;i++)
    {
        printf("%c",word[i]);
    }

    return 0;
}

void reverse(char word[],int start,int end)
{
    char temp;
    if(start > end) return;

    temp = word[start];
    word[start] = word[end];
    word[end] = temp;

    reverse(word, start+1, end-1);

}