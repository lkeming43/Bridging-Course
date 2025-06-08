#include<stdio.h>
#include<stdbool.h>

typedef struct range{
    int x;
    int y;
}range;

bool can_merge(range a, range b);
range merge(range a, range b);
void add(range r, range s[], int n);
void print(range r);

int main()
{
    range a, b, c, d;
    a.x = 1;
    a.y = 3;
    b.x = 4;
    b.y = 6;

    d.x = 3;
    d.y = 5;
    /*if(can_merge( a, b)) 
    {
        printf("Can merge");
        c = merge( a, b);
        printf("\nMerged range: [%d-%d]", c.x, c.y);
    }

    else printf("\nCannot merge.");*/

    int n = 3;
    range s[n];
    s[0].x = 1;
    s[0].y = 2;
    s[1].x = 4;
    s[1].y = 6;
    s[2].x = 7;
    s[2].y = 10;

    add(d, s, n);

    return 0;
}

bool can_merge(range a, range b)
{
    if((a.y >= b.x && a.y <= b.y) || a.y == b.x - 1) return true;
    if((b.y >= a.x && b.y <= a.y) || b.y == a.x - 1) return true;

    else return false;
}

range merge(range a, range b)
{
    int max, min;
    range c;

    if( a.x > b.x) min = b.x;
    else min = a.x;

    if( a.y > b.y) max = a.y;
    else max = b.y;

    c.x = min;
    c.y = max;

    return c;
}

void add(range r, range s[], int n)
{
    int i, j;

    for(i=0;i<n;i++)
    {
        if(can_merge(r,s[i])) s[i] = merge(r, s[i]);
    }

    for(i=0;i<n-1;i++)
    {
        if(can_merge(s[i], s[i+1])) 
        {
            s[i] = merge(s[i], s[i+1]);
            for(j=i+1;j<n-1;j++) s[j] = s[j+1];
            n--;
            i--;
        }
    }

    for(i=0;i<n;i++)
    {
        print(s[i]);
    }

    return;
}


void print(range r)
{
    printf("\n[%d-%d]", r.x, r.y);
}