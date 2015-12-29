


#include <stdio.h>
# include <math.h>

double norm2(int n, double b[])
{
	//for vectors
  int i;
   double s = 0;
	
   
	for(i=0;i<n;i++)
	   s += b[i]*b[i];
	   
	   s = sqrt(s);
	   return s;
		  
}

int main()
{
	
	int n;
	printf("Enter the A matrix magnitude\n");
	scanf("%d", &n);
	double a[n][n];
	double x[n],r[n],b[n],p[n],q[n],t[n];
	double k;
	double u = 0;
	double v = 0;
	double v1 = 0;
	
	double alfa, beta;
	
	int i,j;
	for (i=0;i<n;i++)
	     r[i]=0;
	
	
	    
	printf("Enter the elements of A\n");
	 for(i=0;i<n;i++)
        for(j=0;j<n;j++)
         scanf("%lf", &a[i][j]);
    
    printf("Enter the b vector\n");
    for(i=0;i<n;i++)
        scanf("%lf", &b[i]);
    
    printf("Enter an initial x vector\n");
    for(i=0;i<n;i++)
        scanf("%lf", &x[i]);
   
   printf("Enter a tolerance number\n");
      scanf("%lf", &k);
        
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
        r[i] += a[i][j]*x[j];
        
    for (i=0;i<n;i++)
         r[i] = b[i] - r[i];   
         
     for (i=0;i<n;i++)
         v+= r[i]*r[i];  
     
          
     for (i=0;i<n;i++)
         p[i] = r[i];
         
         
    //----------------------------------------------------------------
    // main loop     
     do
     {
		 for (i=0;i<n;i++)
	        q[i]=0;
	     
		  for(i=0;i<n;i++)
             for(j=0;j<n;j++)
                 q[i] += a[i][j]*p[j];
          
          for(i=0;i<n;i++)
             u += p[i]*q[i];
          
          alfa = v/u;
          
          for(i=0;i<n;i++)
              x[i]+= alfa*p[i];
          
          for(i=0;i<n;i++)
              r[i] += - alfa*q[i];
          
          for(i=0;i<n;i++)
              v1 += r[i]*r[i];
              
          beta = v1/v;
          
          for(i=0;i<n;i++)
             p[i] = r[i] + beta*p[i];
          
          v = v1;
          v1 = 0;
          u = 0;
          
           
              
           
     
	    
	    for(i=0;i<n;i++)    
          t[i] = 0; 
         
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                t[i] += a[i][j]*x[j];
                
        for(i=0;i<n;i++)    
          t[i]-= b[i];
           
        
		 
	 }
	 while(norm2(n,t)>k);
	 
	 for (i=0; i<n;i++)
	    printf("%lf\n", x[i]);
	 
	
	
	
	return 0;
}

