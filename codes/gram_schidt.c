
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float normaf (int m, int n,float a[][n])
{
	int i,j;
	float r =0;
	for(i=0;i<m;i++)
	   for(j=0;j<n;j++)
	       r+= a[i][j]*a[i][j];
	r = sqrt(r);
	return r; 
	   
}

float norma2(int n, float b[])
{
  int i;
   float s = 0;
	
   
	for(i=0;i<n;i++)
	   s += b[i]*b[i];
	   
	   s = sqrt(s);
	   return s;
		  
}


int main()
{
	int n,k,i,j;
	printf("vectors size\n");
	scanf("%d", &n);
	
	float vc[n][n],v[n][n], r[n][n];
	
	float vv[n];
	
	
	for(i=0;i<n;i++)
	{
		printf("Enter the elements of the vector %d\n", i+1);
	    for(j=0;j<n;j++)
  	        {
				scanf("%f", &v[i][j]);
				vc[i][j] = v[i][j];
            }
    }
	  // modified gram-schimdt starts here;
//------------------------------------------------------------------	  
	  for(k=0;k<n;k++)
	  {
		 for(i=0;i<n;i++)
		   for(j=0;j<n;j++)
		       r[i][j] = 0;
		       
		for(i=0;i<k;i++)
		{
		   for(j=0;j<n;j++)
		       r[i][k] += vc[k][j]*vc[i][j];
	    
	    
		   for(j=0;j<n;j++)
  		       vc[k][j] = vc[k][j] - vc[i][j]*r[i][k];
  		 }
  		 
		for(i=0;i<n;i++)
  		    for(j=0;j<n;j++) 
  		        vv[j] = vc[k][j];
  		        
  		r[k][k] = norma2(n,vv);
  		
  		if ( r[k][k] == 0)
  		{
			printf("Os vetores são dependentes");
			exit (0);
		}
		
		
		
		for(j=0;j<n;j++)
		   {    
			   
			    vc[k][j] = (1/r[k][k]) * (vc[k][j]);
		   }
		   
		   
	}
	
	printf("modified Gram-Schmidt result\n");
	for(i=0;i<n;i++)
	    {
			for(j=0;j<n;j++)
	           printf("%f ", vc[i][j]);
	           
	         printf("\n");
	    }
	
	
	return 0;
}

