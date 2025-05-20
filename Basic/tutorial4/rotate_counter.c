#include<stdio.h>
#define n 10

void rotate_cc (int p[n], int count) 
{
    int temp, m;
    int times;
    times = count % 10; 

    for (m = 9; m > 0; m--) 
    { 
        temp = p[m];
        p[m] = p[(m - times + 10) % 10];
        p[(m - times + 10) % 10] = temp;
    }
}


int main()
{
    int a[n],i,step;

    for(i=0;i<n;i++) a[i] = 3*i + 3;
    printf("\n");
    for(i=0;i<n;i++) printf("%d",a[i]);

    printf("Enter the numberof steps for counter clockwise push < 0 to stop> :");
    
    while (1) 
    {
        scanf("%d", &step);  
        if (step < 0) break;  

        rotate_cc(a, step);  

        printf("Rotated array:\n");
        for (i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\nEnter the number of steps for counter-clockwise push (< 0 to stop): ");
    }


}