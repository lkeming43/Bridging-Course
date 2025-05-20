#include<stdio.h>
#define PI 3.14159265

int main()
{
	int result=0,n,x,num=0;
	
	for(num=n=x=1;x<=10;n=n+1,num=num+1)
	{
		num=num*n;
		result=result+(2*((-1)^n)*((PI)^(2*PI)))/(num);
	}
	
	return 0;
	
	
}