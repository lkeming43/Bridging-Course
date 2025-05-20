#include <stdio.h>
#include <stdlib.h>


int main() 
{
    int bet = 2; 
    int totalBet = 1000000 * bet; 
    int totalReturn = 0; 
    int i;
   
    srand(31); 

   
    for ( i = 0; i < 1000000; i++)
	 {
        double roll = (double)rand() / RAND_MAX; 

        if (roll < 0.2) 
		{

        } 
		else if (roll < 0.4)
		{
           
        } 
		else if (roll < 0.45) 
		{
            totalReturn += bet;
        }
		 else if (roll < 0.5)
	    {
            totalReturn += bet;
        } 
		else if (roll < 0.8)
	    {
            totalReturn += 3;
        } 
		else 
		{
            totalReturn += 4;
        }
    }

    double houseAdvantage = ((double)(bet * 50 - totalReturn) / (bet * 50) * 100);


    printf("Total Bet: $%d\n", totalBet);
    printf("Total Return: $%d\n", totalReturn);
    printf("House Advantage: %.2f%%\n", houseAdvantage);

    if (houseAdvantage <= 6.0) {
        printf("The game meets the regulatory requirement.\n");
    } else {
        printf("The game does not meet the regulatory requirement.\n");
    }

    return 0;
}