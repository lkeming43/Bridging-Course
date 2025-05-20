#include<stdio.h>
int size;

void scan_set(int set[ ], int size)
{
    printf("\nEnter a set of integer:");
    int i;
    for(i=0;i<size;i++) scanf("%d",&set[i]);
}

void prt_set(int set[ ], int size)
{
    int i;
    printf("%d",size);
    printf("\n(");
    for(i=0;i<size;i++) printf("%2d",set[i]);
    printf(")");
}

int main()
{
    printf("Enter the size of the set:");
    scanf("%d",&size);

    int a[size];

    scan_set(a,size);

    prt_set(a,size);

    return 0;

}