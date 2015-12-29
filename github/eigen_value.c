


#include <stdio.h>
#include <math.h>

float infinitnorm (int n, float b [])
{
	//for vectors
	int i;
	float c[n],m;
	
	for(i=0;i<n;i++)
	   c[i]=b[i];
	   
	m = c[1];   
	
	for(i=0;i<n;i++)
	{
	   c[i]=(c[i]*c[i]);
	   c[i]=sqrt(c[i]);
	}
	for(i=0;i<n;i++)
	    if(m<c[i])
	    m = c[i];
	    
	    return m;
	   
	   
	   
	 
	
}

int main()
{
	int n,i,j;
	float norm;
	float support;
	printf("tamanho da Matriz\n");
	scanf("%d", &n);
	float a[n][n];
	float x[n],xc[n],xc2[n];
	
	for(i=0;i<n;i++)
	    xc[i] = 0;
	    
	printf("Digite A\n");
	 for(i=0;i<n;i++)
        for(j=0;j<n;j++)
         scanf("%f", &a[i][j]);

     printf("digite o auto-vetor inicial\n");
     for(i=0;i<n;i++)
      scanf("%f", &x[i]);
     
  do
  {
     // achando autovetor 
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
             xc[i]+= a[i][j] * x[j];
             
     norm = infinitnorm(n,xc);
     
             
     // simplifying  the vector       
     for(i=0;i<n;i++)
             xc[i]=(xc[i]/norm);
             
     // copying to  x 
     for(i=0;i<n;i++)
      {
		  xc2[i] = sqrt(xc[i]*xc[i]) - sqrt(x[i]*x[i]);
	  }  
	  
	  norm = infinitnorm(n,xc2);
	       
    for(i=0;i<n;i++)
      {
		  x[i] = xc[i];
		  xc[i] = 0;
	  }
    
  
      
           
  }
 while ( norm > 0.0000001 );
    
    // finding eigen-value
  for(i=0;i<n;i++)
        for(j=0;j<n;j++)
             xc[i]+= a[i][j] * x[j];

norm = 0;
  for(i=0;i<n;i++)
  // reusing norm variable
		norm += xc[i]*x[i];
   for (i=0;i<n;i++)
        support += x[i]*x[i];	
        
 printf("autovalor dominante aproximado\n");        
 printf("%f", norm/support);
 
    
         
	return 0;
}

