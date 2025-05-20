#include<stdio.h>

main()
{
	FILE *indata;
	float payment, pricea, priceb, pricec,total=0;
	int num,a,b,c;
	indata = fopen("C:\\Users\\e1513092\\Desktop\\BILL.inf","r");
	
	if(indata != NULL)
	{
		printf(   "Bill Number     Payment($)  \n");
		printf("===================================\n");
		
		while ( fscanf(indata,"%d%d%d%d", &num, &a, &b, &c)==4)
		{
		
			if(a>100) pricea=3.92;
			else pricea=4.00;
		
			if(b>200) priceb=5.7;
			else priceb=6.00;
		
			if(c>150) pricec=4.5;
			else pricec=5.00;
			
			payment=a*pricea+b*priceb+c*pricec;
			total=total+payment;
		
		
	
		printf("      %d               %.2f \n",num,payment);

		
		}
		
		fclose(indata);
		printf("     Total             %.2f \n",total);
		
		return 0;	
		}
	
	else printf("error ");
	
	return 0;
}