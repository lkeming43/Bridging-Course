#include <stdio.h>

int main(int argc, char *argv[]) 
{
    FILE *indata, *outdata;
    char this1;

    if (argc != 3) 
    {
        printf("Usage: %s inputfile outputfile\n", argv[0]);
        return 1;
    }

    indata = fopen(argv[1], "r");
    if (indata == NULL) 
    {
        printf("Error opening input file.\n");
        return 1;
    }

    outdata = fopen(argv[2], "w");
    if (outdata == NULL) 
    {
        printf("Error opening output file.\n");
        fclose(indata);
        return 1;
    }

    while (fscanf(indata, "%c", &this1) == 1) 
    {
        if (this1 >= 'A' && this1 <= 'Z') 
        {
            fprintf(outdata, "%c", (this1 - 'A' + 11) % 26 + 'A'); 
        } 
        else if (this1 >= 'a' && this1 <= 'z') 
        {
            fprintf(outdata, "%c", 'z' - (this1 - 'a'));  
        } 
        else 
        {
            fprintf(outdata, "%c", this1);  
        }
    }

    fclose(indata);
    fclose(outdata);
    return 0;
}
