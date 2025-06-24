#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tool 
{
    int rec_Num;
    char name[16];
    int quantity;
    float cost;
};

int main() 
{
    FILE *text = fopen("data.txt", "r");
    if (!text) 
    {
        perror("Failed to open data.txt");
        return 1;
    }

    FILE *binary = fopen("hardware.dat", "wb");
    if (!binary) 
    {
        perror("Failed to open hardware.dat");
        fclose(text);
        return 1;
    }

    char line[100];
    struct tool t;

    while (fgets(line, sizeof(line), text)) 
    {
        char temp[32];

        strncpy(temp, line, 3);
        temp[3] = '\0';
        t.rec_Num = atoi(temp);

        strncpy(temp, line + 4, 21);
        temp[21] = '\0';

        int i = strlen(temp) - 1;
        while (i >= 0 && temp[i] == ' ') temp[i--] = '\0';
        strncpy(t.name, temp, 15);
        t.name[15] = '\0'; 

        strncpy(temp, line + 25, 5);
        temp[5] = '\0';
        t.quantity = atoi(temp);

        strncpy(temp, line + 30, sizeof(temp) - 1);
        temp[sizeof(temp) - 1] = '\0';
        t.cost = atof(temp);

        fwrite(&t, sizeof(struct tool), 1, binary);
    }

    fclose(text);
    fclose(binary);

    printf("Indata\n");
    return 0;
}
