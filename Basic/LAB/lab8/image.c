# include <stdio.h>

float computeThreshold(int image[8][8]) 
{
  int min = image[0][0], max = image[0][0];

  for (int i = 0; i < 8; i++) 
  {
      for (int j = 0; j < 8; j++) 
      {
          if (image[i][j] < min) min = image[i][j];  
          if (image[i][j] > max) max = image[i][j];  
      }
  }
  
  return (max + min) / 2.0; 
}

void convertToBinaryImage(int image[8][8], float threshold) 
{
  int i, j;
  for (i = 0; i < 8; i++) 
  {
      for (j = 0; j < 8; j++) 
      {
          if (image[i][j] >= threshold)
              image[i][j]=1;
          else
              image[i][j]=0;
      }
      printf("\n");
  }
}

int main()
{
  int i,j;
  int letter[8][8] =
   {
     6, 6, 6, 6, 6, 6, 6, 6,
     6, 2, 2, 2, 2, 2, 2, 6,
     6, 3, 1, 0, 1, 1, 2, 7,
     6, 6, 5, 0, 1, 5, 6, 6,
     6, 6, 5, 3, 3, 5, 6, 7,
     7, 6, 5, 3, 2, 6, 6, 7,
     7, 6, 6, 2, 2, 5, 6, 7,
     7, 7, 7, 7, 7, 7, 7, 7
   };



   float threshold = computeThreshold(letter);

   convertToBinaryImage(letter, threshold);

   for(i=0;i<8;i++)
   {
    printf("\n");

    for(j=0;j<8;j++)
    {
      if (letter[i][j]==0)
      {
        printf("%c",219);
      }
      else printf(" ");
    }
   }

  return 0;
}



