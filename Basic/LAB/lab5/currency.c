#include <stdio.h>
#define SELLS 1
#define BUYS 2
#define QUIT 3

void print_menu(void)
{
   printf("\n\n   Currency Conversion\n");
   printf("1.   Customer sells Renminbi\n");
   printf("2.   Customer buys Renminbi\n");
   printf("3.   Quit\n\n");
   printf("Enter your choice: ");
}

int main(void)
{
	FILE *indata;
	int command;
	float num,buyingrate,sellingrate,a;
	

	indata = fopen("C:\\Users\\e1513092\\Desktop\\RATE.DAT","r");
	
	if (indata == NULL)
    {
        printf("Error: Unable to open RATE.DAT\n");
        return 1;
    }
	
	fscanf(indata,"%f%f",&buyingrate,&sellingrate);
	fclose(indata);
	


	
	do
	{
	print_menu();
	scanf("%d",&command);
		
	
		switch(command)
		{
			case SELLS:
			printf("How much CNY are you selling?");
			scanf("%f", &num);
			a=(num*buyingrate)/1000;
			printf("\nFor %f CNY, you will get %.2f SGD\n",num,a);
			break;
			
			case BUYS:
			printf("How much SGD do you have?");
			scanf("%f", &num);
			a=(num*sellingrate)/100;
			printf("\nFor %f SGD, you will get %.2f CNY\n",num,a);
			break;
			
			case QUIT:
			printf("Have a nice day");

			break;
			
			
			
		
		}

	}while(command!=QUIT);


}
 
