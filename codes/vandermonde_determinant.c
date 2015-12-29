


#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float det(int n , float a [][n] )
{
	int i,j;
	float r = 1;
	for (i=0;i<n;i++)
	    for(j=0;j<n;j++)
	       {
			   if(i>j)
	          {
			      r*=(a[i][1]-a[j][1]);
	          }
	          else
	             break;
	         }
	     return r;    
}

int main()
{

	
	int i,j,k,n;
	
	printf("enter the matrix mgnitude\n");
	scanf("%d",&n);
	
	float a[n][n];
	
	float acm =1;
    
    printf("enter the matrix elements\n");
	for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++)
          {
		    scanf("%f", &a[i][j]);
            if ( j == 0)
            {
               if ( a[i][j] != 1 )
               {
                  printf("its not a vandermonde matrix\n");
                  return 1;
                  exit (0);
                  
                  return 0;
               }
             }
            
            if ( (j > 1)  )
            {
				for(k=0;k<j;k++)
				{
					acm*=a[i][1];
				}
				if(acm!=a[i][j])
                  {
					  printf("%f", acm);
					  return 2;
                      printf("its not a vandermonde matrix\n");
                      exit(0);
                  }
                  acm = 1;
                 
                  
                  
             }
                 
        } 
       }

	

	
    
         printf("it's a vandermonde matrix !\n");
         
         printf("determinant\n");
         printf ("%f",det(n,a));
         
    
	
	
	return 0;
}




