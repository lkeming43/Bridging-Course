#include<stdio.h>
#define MAXSIZE 48

void read_soc(int soc[][MAXSIZE], int size);
void prt_soc(int soc[][MAXSIZE], int size);
int population(int soc[][MAXSIZE], int size);
int evolve_soc(int soc[][MAXSIZE], int size);
int destiny(int soc[][MAXSIZE], int row, int col);

int sizeS;


int main()
{
    int size,j;

    printf("Read the boundary size: ");
    scanf("%d",&size);
    getchar();
    sizeS = size;

    int soc[MAXSIZE][MAXSIZE];
    read_soc(soc, size);
    prt_soc(soc, size);
    printf("\n\nThe number of inhabitants is: %d\n\n",population(soc, size));

    evolve_soc(soc,size);
    printf("\n\nThe number of inhabitants is: %d\n\n",population(soc, size));

    return 0;
}

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

    printf("\nNew Life:\n");

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

int population(int soc[][MAXSIZE], int size)
{
	int i,j,n;
    
    n = 0;

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(soc[i][j] == 1) n++;
            else continue;
        }
    }

    
	return n;
}

int evolve_soc(int soc[][MAXSIZE], int size)
{
    int i,j,n,temp[size][size];

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            temp[i][j] = soc[i][j];
        }
    }
    
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(destiny(soc,i,j)) temp[i][j] = 1;
            else temp[i][j] = 0;
        }
    }

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            soc[i][j] = temp[i][j];
        }
    }

    //print the evoloved society
    printf("\n\nAfter one evolution: \n\n++++++++++++++++++++");

    n = 0;
    printf("\n\n/");
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

    return 0;
}

int destiny(int soc[][MAXSIZE], int row, int col)
{
    int check[3][3];
    int i,j,live;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(row-1+i >= 0 && col-1+j >= 0 && row-1+i < sizeS && col-1+j < sizeS ) check[i][j] = soc[row-1+i][col-1+j];
            else check[i][j] = 0;
        }
    }

    live = 0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(check[i][j] == 1) live ++;
        }
    }

    if(check[1][1] == 1) live--;

    if(check[1][1] == 1)
    {
        if(live < 2) return 0;
        if(live == 2 || live == 3) return 1;
        if(live > 3) return 0;
    }
    
    else
    {
        if(live == 3) return 1;
        else return 0;
    }

    return 0;
}

