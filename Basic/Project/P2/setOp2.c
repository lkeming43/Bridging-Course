#include<stdio.h>

void scan_set(int set[ ], int size)
{
    printf("\nEnter a set of integer:");
    int i;
    for(i=0;i<size;i++) scanf("%d",&set[i]);
}

void prt_set(int set[ ], int size)
{
    int i;
    printf("\n%d",size);
    printf("\n\n(");
    for(i=0;i<size;i++) printf("%2d,",set[i]);
    printf(")");
    for(i=0;i<size;i++) printf("\n");
}

int is_member(int item, int set[ ], int size)
{
    int i;
    
    for(i=0;i<size;i++) 
    {
        if(item == set[i]) 
        {
            printf("\nItem %d is a member of the set.",item);
            for(i=0;i<size;i++) printf("\n");
            break;
        }
    }

    if(i == size) 
        printf("\nItem %d is NOT a member of the set.",item);
        for(i=0;i<size;i++) printf("\n");

    return 0;
}

int main()
{
    int size,item;
    printf("\nEnter the size of the set:");
    scanf("%d",&size);

    int a[size];

    scan_set(a,size);
    prt_set(a,size);

    printf("Enter a checked number:");
    scanf("%d",&item);
    is_member(item, a, size);

    return 0;

}