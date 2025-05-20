#include<stdio.h>

int main()
 {
 	int num,numa;
 	int digit;
 	int reversed=0;
	 
	printf("Enter 0 to stop or enter a positive integer smaller than 2147483647: ");
 	scanf("%d", &num);
 	
 	numa=num;
 	
 	while (num > 0) 
	{
        digit = num % 10;           
        reversed = reversed * 10 + digit; 
        num = num/10;                   
    }
    
    if(reversed==numa) 
		printf(" %d is a palindrome ", numa);
    else 
		printf(" %d is not a palindrome ", numa);
    
 	return 0;
 }