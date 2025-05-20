#include <stdio.h>

void scan_set(int set[], int size)
{
    printf("\nEnter a set of integers: ");
    for(int i = 0; i < size; i++) 
    {
        scanf("%d", &set[i]);
    }
}

void prt_set(int set[], int size)
{
    printf("\n%d", size);
    printf("\n\n{");
    for(int i = 0; i < size-1; i++) 
    {
        printf("%2d,", set[i]);
    }
    printf("%2d",set[size-1]);
    printf("}.");
}

int is_member(int item, int set[], int size)
{
    for(int i = 0; i < size; i++) 
    {
        if(item == set[i]) return 1;
    }
    return 0;
}

int intersect(int setA[], int sizeA, int setB[], int sizeB, int setC[])
{
    int j = 0;

    for(int i = 0; i < sizeA; i++)
    {
        if(is_member(setA[i], setB, sizeB))
        {
            setC[j++] = setA[i];
        }
    }

    printf("\n%d\n", j);

    printf("{");
    for(int i = 0; i < j; i++) 
    {
        printf("%d", setC[i]);
        if(i != j - 1) printf(", ");
    }
    printf("}");

    return 0;
}

int  top_k_sum(int k, int set[], int size)
{
 int i;
 k=0;
 for(i=0;i<size;i++)
 {
  if(set[i]>0)
  {
   k++;
  }
 }
 return k;
}

int main()
{
    int option;
 printf("$ ./a.out\n\n");
    printf("Enter 1 (membership checking) or 2 (intersection) or 3 (top-k-sum): ");
    scanf("%d", &option);

    if(option == 1)
    {
        int size, item;
        printf("\nEnter the size of the set: ");
        scanf("%d", &size);

        int a[size];
        scan_set(a, size);
        prt_set(a, size);

        printf("\nEnter a number to check: ");
        scanf("%d", &item);

        if(is_member(item, a, size))
        {
            printf("\nItem %d is a member of the set.", item);
        }
        else
        {
            printf("\nItem %d is NOT a member of the set.", item);
        }
    }
    
    else if(option == 2)
    {
        int sizeA, sizeB, setC[100];

        printf("\nEnter the size of the first set: ");
        scanf("%d", &sizeA);
        int setA[sizeA];
        scan_set(setA, sizeA);
        prt_set(setA, sizeA);

        printf("\n\nEnter the size of the second set: ");
        scanf("%d", &sizeB);
        int setB[sizeB];
        scan_set(setB, sizeB);
        prt_set(setB, sizeB);

        intersect(setA, sizeA, setB, sizeB, setC);
    }
    
    else if(option == 3)
    {
     int size, k,sum=0,i;
        printf("\nEnter the size of the set: ");
        scanf("%d", &size);

        int a[size];
        scan_set(a, size);
        prt_set(a, size);
        k=top_k_sum(k, a, size);
        printf("\n\n%d\n\n",k);
        if(k<3)
        {
         printf("The set is too small.");
  }
  else
  {
   for(i=0;i<size;i++)
   {
    if(a[i]>0)
    {
     sum+=a[i];
    }
   }
   printf("%d",sum);
  }
 }
    
    else
    {
        printf("Invalid option.\n");
    }

    return 0;
}