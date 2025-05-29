#include <stdio.h>

int main(void) {
    char *days[] = {"Mon", "Tue", "Wed", "Thu", "Fri"};
    char **p    = days + 2;
    char ***pp  = &p;

    printf("%s\n", *p);            
    printf("%c\n", *(*pp)[1]);    
    printf("%s\n", *(pp[0] - 1));  
    return 0;
}
