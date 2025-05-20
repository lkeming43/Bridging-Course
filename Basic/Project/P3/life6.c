#include<stdio.h>
#define MAXSIZE 48

void read_soc(int soc[][MAXSIZE], int size);
void prt_soc(int soc[][MAXSIZE], int size);
int population(int soc[][MAXSIZE], int size);
int evolve_soc(int soc[][MAXSIZE], int size);
int destiny(int soc[][MAXSIZE], int row, int col);
void generate(int soc[][MAXSIZE], int size, int gen) ;
void census(int soc[][MAXSIZE], int size, int pop[]);
int sizeS;

int main()
{
    int size,i,j,gen,n;
    int pop[MAXSIZE];

	printf("$ a.out\n");
    printf("\nRead the boundary size: ");
    scanf("%d",&size);
    getchar();
    sizeS = size;

    int soc[MAXSIZE][MAXSIZE];
    read_soc(soc, size);
    printf("\nNew Life:\n");
    prt_soc(soc, size);
    printf("\n\nThe number of inhabitants is: %d\n\n",population(soc, size));

    
    //the first evoloved society
    evolve_soc(soc,size);
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
    printf("\n\nThe number of inhabitants is: %d.\n\n",population(soc, size));


    //evolve for certain times
    printf("\n\n\nEnter the times for evolution: ");
    scanf("%d",&gen);
    printf("\nEvolution begins.\n\n+++++++++++++++++");
    generate(soc, size, gen);
    census(soc, size, pop);
    migrate(soc, size, pop);
    printf("\n\n\nAfter migration:\n");
    printf("\n++++++++++++++++++++\n\n");
    prt_soc(soc, size);
	printf("\n\nThe number of inhabitants is: %d.",population(soc, size));
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

void generate(int soc[][MAXSIZE], int size, int gen)
{
    int n,i,j,check[size][size],equal,evotimes;

    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            check[i][j] = soc[i][j];
        }
    }

    for(evotimes=0;evotimes<gen;evotimes++)
    {
        evolve_soc(soc,size);
        
        //check whether the society is stable
        equal = 1;  
        for ( i = 0; i < size; i++) 
        {
            for(j=0;j<size;j++)
            {
                if (check[i][j] != soc[i][j]) 
                {
                    equal = 0;  
                    break;      
                }
            }
        }
        if(equal)
        {
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

            printf("\n\nThe number of inhabitants is: %d\n\n",population(soc, size));
            printf("The society stabilizes at evolution %d.",++evotimes);

            return;
        }

        //not stable
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                check[i][j] = soc[i][j];
            }
        }
    }

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

    printf("\n\nThe number of inhabitants is: %d\n\n",population(soc, size));
    printf("Evolution continues after %d evolutions.",gen);
}

void census(int soc[][MAXSIZE], int size, int pop[])
{
	int i,j;
	for(i=0;i<size;i++)
	{
		pop[i]=0;
		for(j=0;j<size;j++)
		{
			if(soc[i][j])
			{
				pop[i]++;
			}
		}
	}
	printf("\nCensus Result:\n");
	printf("\n++++++++++++++\n");
	printf("\n[");
    for (i = 0; i < size; i++) 
	{
        printf(" %d",pop[i]);
	}
	printf(" ]");
}

void migrate(int soc[][MAXSIZE], int size, int pop[])
{
    int i, j;

    // 定义结构来记录原始行索引和活跃数
    typedef struct {
        int index;
        int count;
    } RowInfo;

    RowInfo rows[MAXSIZE];

    // 初始化 row 信息
    for (i = 0; i < size; i++) {
        rows[i].index = i;
        rows[i].count = pop[i];
    }

    // 稳定排序：按活跃细胞数量降序排序，保留相对顺序
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (rows[i].count < rows[j].count) {
                RowInfo temp = rows[i];
                rows[i] = rows[j];
                rows[j] = temp;
            }
        }
    }

    // 创建新数组用于迁移结果
    int new_soc[MAXSIZE][MAXSIZE];

    for (i = 0; i < size; i++) {
        memcpy(new_soc[i], soc[rows[i].index], sizeof(int) * size);
    }

    // 把结果复制回原数组 soc
    for (i = 0; i < size; i++) {
        memcpy(soc[i], new_soc[i], sizeof(int) * size);
    }

    // 重新生成 census 数据
    for (i = 0; i < size; i++) {
        pop[i] = 0;
        for (j = 0; j < size; j++) {
            if (soc[i][j] == 1)
                pop[i]++;
        }
    }
}