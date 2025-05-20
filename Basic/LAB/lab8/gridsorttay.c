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

  
  for(i=0;i<n-1;i++)
  {
    for(j=1;j<n;j++)
    {
        interchange=0;
        if(G[i][j]>G[i+1][0])
        {
            temp = G[i][j];
            G[i][j] = G[i+1][0];
            G[i+1][0] = temp;
            interchange = 1;
            this1 = G[i+1][0];
            thisi = i+1;
            thisj = 0;
        

        while(interchange)
        {
            if(thisi<=n-2 && thisj <= n-2&&(this1<G[thisi+1][thisj]||this1<G[thisi][thisj+1]))
            {
                if(G[thisi+1][thisj]<G[thisi][thisj+1])
                {
                    min = G[thisi+1][thisj];
                    nexti = thisi+1;
                    nextj = thisj;
                }

                else
                {
                    min = G[thisi][thisj+1];
                    nexti = thisi;
                    nextj = thisj+1;
                }
            }

            else
                if(thisi==n-1 && thisj <=n-1&&this1<G[thisi][thisj+1])
                {
                    min = G[thisi][thisj+1];
                    nexti = thisi;
                    nextj = thisj+1;
                }

            else
                if(thisi<=n-2 && thisj==n-1&&this1<G[thisi+1][thisj])
                {
                    min = G[thisi+1][thisj];
                    nexti = thisi+1;
                    nextj = thisj;
                }
            
            else
            {
                min = this1;
                break;
            }
                

            G[thisi][thisj] = min; // 修正：确保数据交换
            thisi = nexti;
            thisj = nextj;
    
            if (thisi == n-1 && thisj == n-1) // 终止条件
                interchange = 0;
        }
        G[thisi][thisj]=this1;
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

