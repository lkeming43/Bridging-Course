#include<stdio.h>
#define MAXSIZE 48

void read_soc(int soc[][MAXSIZE], int size)
{
    int i,j,n;
    char temp[size*size];
    char ch;

    printf("\nRead the society.\n\n");
    
    i = 0;
    n = 0;
    
	while(i<size*size)
	{
		while ((ch = getchar()) == ' ' || ch == '\n' || ch == '\t');
		temp[i] = ch;
		i++;
	}

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(temp[n] == '*')  soc[i][j] = 1;
            else if(temp[n] == '-')  soc[i][j] = 0;
			n++;
        }
        
    }
}

void prt_soc(int soc[][MAXSIZE], int size)
{
    int i,j,n;

    printf("\nNew Life\n");

    n = 0;

    printf("\n/");
    while(n<3*size)
    {
        printf("o");
        n++;
    }
    printf("\\");

    for(i=0;i<size;i++)
    {
        printf("\n\n");
        printf("|");
        for(j=0;j<size;j++)
        {
            if(soc[i][j] == 1) printf(" * ");
            else printf(" - ");
        }
        printf("|");
    }

    printf("\n\n\\");
    n = 0;
    while(n<3*size)
    {
        printf("o");
        n++;
    }
    printf("/");
}

int main()
{
    int size;

    printf("Read the boundary size: ");
    scanf("%d",&size);
    getchar();

    int soc[MAXSIZE][MAXSIZE];
    read_soc(soc, size);
    prt_soc(soc, size);

    return 0;
}