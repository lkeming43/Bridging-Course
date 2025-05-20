# include <stdio.h>
# include <stdlib.h>

# define n 8

int main ()
{
  int G [n][n];

  int i,j,this1;
  int nexti, nextj, temp, interchange;
  int thisi, thisj,  min;

  int i1, j1,i2,j2,i3,j3;
  int row, col;
  long checksum, sorted;

  int exchange,index;

	  




  srand (31);
  for (j=0; j<n; j++)
  {
	    for (i=0; i<n; i++)
	    G[i][j] = rand()%200;
  }

  printf ("\n\nRaw Data:\n");
  checksum=0;
  for (i1=0; i1<n; i1++)
  {
	  for ( j1=0; j1<n; j1++)
	    {
	      printf ("%5d",G[i1][j1]);
	      checksum += G[i1][j1];
	    }
	  printf ("\n");
  }
      
  printf ("Checksum = %ld",checksum);

  
  for(i2=0;i2<8;i2++)
  {
  do
  {
  exchange=0;
    for(j2=0;j2<7;j2++)
    if(G[i2][j2]>G[i2][j2+1])
    {
      temp = G[i2][j2];
      G[i2][j2] = G[i2][j2+1];
      G[i2][j2+1] = temp;
      exchange = 1;
    }
        
  }while(exchange==1);
  }

 
      

  printf ("\n\nAfter row sort:\n");
  checksum=0;
  for (i1=0; i1<n; i1++)
  {
	  for (j1=0; j1<n; j1++)
	  {
	    printf ("%5d",G[i1][j1]);
	    checksum += G[i1][j1];
	  }
	  printf ("\n");
  }
      
	printf ("Checksum = %ld",checksum);

	
  for(j2=0;j2<8;j2++)
  {
  do
  {
    exchange=0;
  
  
    for(i2=0;i2<7;i2++)
    if(G[i2][j2]>G[i2+1][j2])
    {
      temp = G[i2][j2];
      G[i2][j2] = G[i2+1][j2];
      G[i2+1][j2] = temp;
      exchange = 1;
    }
  }while(exchange==1);
  }
        
  

  

  printf ("\n\nAfter column sort:\n");
  checksum=0;
  for ( i1=0; i1<n; i1++)
  {
	  for (j1=0; j1<n; j1++)
	  {
	    printf ("%5d",G[i1][j1]);
	    checksum += G[i1][j1];
	  }
	  printf ("\n");
  }
  printf ("Checksum = %ld",checksum);

  
  for (i3 = 0; i3 < n-1; i3++) 
  {
    for (j3 = 1; j3 < n; j3++) 
    {
        if (G[i3][j3] > G[i3+1][0]) 
        {
            temp = G[i3][j3];
            G[i3][j3] = G[i3+1][0];
            G[i3+1][0] = temp;

            int x = i3 + 1, y = 0;
            while (x < n) 
            {  
                int nx, ny;
                if (x + 1 < n) 
                {
                    nx = x + 1;
                    ny = y;
                    if (y + 1 < n && G[x][y + 1] < G[nx][ny]) 
                    {
                        nx = x;
                        ny = y + 1;
                    }
                } 
                else 
                {
                    if (y + 1 < n) 
                    {
                        nx = x;
                        ny = y + 1;
                    } 
                    else 
                    {
                        break; 
                    }
                }

                if (nx >= n || ny >= n) break; 

                if (G[x][y] > G[nx][ny]) 
                {
                    temp = G[x][y];
                    G[x][y] = G[nx][ny];
                    G[nx][ny] = temp;
                    x = nx;
                    y = ny;
                } 
                else 
                {
                    break;
                }
            }
        }
    }
}

  printf ("\n\nAfter interchange and restoration:\n");
  checksum=0;
  sorted =1;
  for (i1=0; i1<n; i1++)
  {
	  for (j1=0; j1<n; j1++)
	  {
	    printf ("%5d",G[i1][j1]);
	    checksum += G[i1][j1];
	    if (! ( i1==(n-1) && j1 == (n-1) ) )
	    if ( *(&G[0][0] + i1*n +j1) > *(&G[0][0] + i1*n +j1 + 1) )
		  sorted =0;
	  }
	  printf ("\n");
  }
  printf ("Checksum = %ld",checksum);

  if (sorted ==1) printf ("   sorted\n\n");
  else printf ("    not sorted\n\n");

  return 0;
}

