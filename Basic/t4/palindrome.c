#include<stdio.h>

int main()
{
    char w1[15], w2[15];
    int i = 0,count1 = 0, count2 = 0;

    printf("Enter a word:");
    fgets(w1, sizeof(w1), stdin);
    while(w1[count1] != '\0')
    {
        count1++;
    }
    w1[count1] = '\0';
    count1--;

    printf("\nEnter another word:");
    fgets(w2, sizeof(w2), stdin); 
    while(w2[count2] != '\0')
    {
        count2++;
    }
    w2[count2] = '\0';
    count2--;

    if( count1 != count2) printf("\nNOT");
    else
    {
        for(i=0;i<count1;i++)
        {
            if(w1[i] != w2[count2 - 1 - i]) 
            {
                printf("NOT");
                return 0;
            }
            
        }
        if(i==count1) printf("\nYES");
    }

    

    return 0;
}