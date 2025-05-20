// matrix.c

// compute product and the transpose of product.

#include <stdio.h>
#include<stdlib.h>

int main(void)
{
	int i,j,k;
	int A[3][4] = { 1, 2,  3,  1,
	              0, 1, -5,  2,
				  6, 2,  0, -2} ;
	               
	int B[4][3] = { 1,  0, -1,
	              0,  1,  1,
				  2,  3,  4,
				  0, -1,  0} ;

	int C[3][3],D[3][3];

	for (i = 0; i < 3; i++) 
	{  
        for (j = 0; j < 3; j++) 
		{ 
            C[i][j] = 0; 
            for (k = 0; k < 4; k++) 
			{  
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

	printf("    AxB     \n");
	printf("============\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("%3d ",C[i][j]);
		}
	printf("\n");
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		D[i][j]=C[j][i];
		}
	}

	printf("Transpose of (AxB) \n");
	printf("============\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("%3d ",D[i][j]);
		}
	printf("\n");
	}
	

	
	return 0;
}
