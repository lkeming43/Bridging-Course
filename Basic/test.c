#include <stdio.h>

int main()
{
    int a,b,c;

    for(a=2;a<10;a++)
    {
        for(b=a;b<10;b++)
        {
            for(c=b;c<=10;c++)
            {
                if(a*a + b*b == c*c)
                printf("%d %d %d ",a, b, c);
            }
        }
    }

    return 0;

}