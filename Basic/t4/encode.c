#include<stdio.h>

int main()
{
    int i,n;
    char ch,temp,result[100];//按字符读

    i = 0;
    printf("Enter the price: ");

    //while(scanf("%c",&ch) == 1 && scanf("%c",&ch) != '\n') 这样写会scanf两遍
    while(scanf("%c",&ch) == 1 && ch != '\n')
    {
        switch(ch)
        {
            case '0': temp = 'X'; break;
            case '1': temp = 'S'; break;
            case '2': temp = 'R'; break;
            case '3': temp = 'E'; break;
            case '4': temp = 'T'; break;
            case '5': temp = 'U'; break;
            case '6': temp = 'P'; break;
            case '7': temp = 'M'; break;
            case '8': temp = 'O'; break;
            case '9': temp = 'C'; break;
            case '.': temp = '.'; break;
            default: break;
        }
        result[i++] = temp;
    }

    n = i;
    printf("\n");
    for(i=0;i<n;i++) printf("%c",result[i]);
    return 0;
}