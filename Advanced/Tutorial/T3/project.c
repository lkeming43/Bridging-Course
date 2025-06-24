#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tool {
    int rec_Num;
    char name[16];
    int quantity;
    float cost;
};

void add_tool(FILE *fp);
void list_tools(FILE *fp);
void delete_tool(FILE *fp);
void update_tool(FILE *fp);

int main() 
{
    FILE *fp = fopen("hardware.dat", "rb+");
    if (!fp) 
    {
        perror("Failed to open hardware.dat");
        return 1;
    }

    int choice;
    do 
    {
        printf("1. Input a new record\n");
        printf("2. Update a record\n");
        printf("3. List all recordsn\n");
        printf("4. Delete a tool\n");
        printf("5. Exit\n");
        printf("Your option -> ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: add_tool(fp); break;
            case 2: update_tool(fp); break;
            case 3: list_tools(fp); break;
            case 4: delete_tool(fp); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 0);

    fclose(fp);
    return 0;
}

void add_tool(FILE *fp) 
{
    struct tool t;
    printf("Enter record number (0-99): ");
    scanf("%d", &t.rec_Num);
    printf("Enter tool name: ");
    scanf("%15s", t.name);
    printf("Enter quantity: ");
    scanf("%d", &t.quantity);
    printf("Enter cost: ");
    scanf("%f", &t.cost);

    fseek(fp, t.rec_Num * sizeof(struct tool), SEEK_SET);
    fwrite(&t, sizeof(struct tool), 1, fp);
    fflush(fp); 
    printf("Tool added successfully.\n");
}

void list_tools(FILE *fp) 
{
    struct tool t;
    rewind(fp);  
    printf("\n%-10s %-16s %-10s %-10s\n", "Record#", "Tool Name", "Quantity", "Cost");
    while (fread(&t, sizeof(struct tool), 1, fp) == 1) 
    {
        if (t.rec_Num != -1) 
        { 
            printf("%-10d %-16s %-10d $%-9.2f\n", t.rec_Num, t.name, t.quantity, t.cost);
        }
    }
}

void delete_tool(FILE *fp) 
{
    int rec;
    struct tool blank = { -1, "", 0, 0.0 };  
    printf("Enter record number to delete: ");
    scanf("%d", &rec);

    fseek(fp, rec * sizeof(struct tool), SEEK_SET);
    fwrite(&blank, sizeof(struct tool), 1, fp);
    fflush(fp);
    printf("Tool deleted (marked as blank).\n");
}

void update_tool(FILE *fp) 
{
    int rec;
    struct tool t;

    printf("Enter record number to update: ");
    scanf("%d", &rec);

    fseek(fp, rec * sizeof(struct tool), SEEK_SET);
    if (fread(&t, sizeof(struct tool), 1, fp) != 1 || t.rec_Num == -1) 
    {
        printf("Record not found.\n");
        return;
    }

    printf("Existing data: %s, %d, %.2f\n", t.name, t.quantity, t.cost);
    printf("Enter new name: ");
    scanf("%15s", t.name);
    printf("Enter new quantity: ");
    scanf("%d", &t.quantity);
    printf("Enter new cost: ");
    scanf("%f", &t.cost);

    fseek(fp, rec * sizeof(struct tool), SEEK_SET);
    fwrite(&t, sizeof(struct tool), 1, fp);
    fflush(fp);
    printf("Tool updated.\n");
}
