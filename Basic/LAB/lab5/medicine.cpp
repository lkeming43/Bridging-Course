#include <stdio.h>
#include <stdlib.h>

int price(char label) 
{
    int unit_price = 0;
    switch (label) 
	{
        case 'A': case 'B': case 'C': unit_price = 9; break;
        case 'D': case 'E': case 'F': case 'G': unit_price = 15; break;
        case 'H': case 'I': case 'J': case 'K': unit_price = 5; break;
        case 'L': case 'M': case 'N': case 'O': unit_price = 12; break;
    }
    return unit_price;
}

int main() 
{
    FILE *input, *output;
    int billNo, numMedicines, i, quantity;
    float totalCost;
    char label;
    
    input = fopen("c:\\Users\\e1513092\\Desktop\\medicine.inf", "r");
    output = fopen("c:\\Users\\e1513092\\Desktop\\charges.ouf", "w");
    
    if (input == NULL || output == NULL) 
	{
        printf("Error opening file!\n");
        return 1;
    }
    
    fprintf(output, "Bill No.        Prescription Charge ($)\n");
    fprintf(output, "======================================\n");
    
    while (fscanf(input, "%d %d", &billNo, &numMedicines) == 2) 
	{
        totalCost = 0;
        for (i = 0; i < numMedicines; i++) 
		{
            fscanf(input, " %c%d", &label, &quantity);
            totalCost += price(label) * quantity;
        }
        fprintf(output, "%d           %.2f\n", billNo, totalCost);
    }
    
    fclose(input);
    fclose(output);
    
    printf("Billing process completed. Check charges.ouf\n");
    return 0;
}
