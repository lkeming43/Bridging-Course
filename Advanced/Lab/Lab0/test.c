#include <stdio.h>

int main() 
{
    int *a;
    printf("sizeof(*int): %zu bytes\n", sizeof(a));
    printf("sizeof(long long int): %zu bytes\n", sizeof(long long int));
    return 0;
}
