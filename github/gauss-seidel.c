

#include <stdio.h>
#include <math.h>

float norm2(int n, float b[])
{
	//for vectors
  int i;
   float s = 0;
	
   
	for(i=0;i<n;i++)
	   s += b[i]*b[i];
	   
	   s = sqrt(s);
	   return s;
		  
}
int main()
{
	int i,j,n,flag;
	float r1,r2; // stores the residue, r1
	 //stores the previous iteration residue and r2 stores the current;
	float sub1 = 0;
	float sub2 = 0;
	
	printf("Enter the magnitude of the matrix A\n");
	scanf("%d",&n);
	
	float a[n][n];
	float b[n], x[n], t[n];
	float k;
	
	printf("Enter the A matrix elements \n");
	
	for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%f", &a[i][j]);
         
    printf("Enter b vector\n" ); 
     
    for (i=0;i<n;i++)
        {
			scanf("%f",&b[i]);
			
	    }
    printf("Enter a tolerance number\n");
    scanf("%f", &k);         
  
 //-----------------------------------------------------------
 //seidel
 
     for(i=0;i<n;i++)
	    {
           for(j=0;j<i;j++)
			   sub1 += a[i][j]*x[j];
		
		   for(j=(i+1);j<n;j++)
			  sub2 += a[i][j]*x[j];
		
		    x[i] = (1-1)*x[i] + (1/a[i][i])*(b[i]-(sub1+sub2));
		    sub1 = 0;
		    sub2 = 0;
		
	    }
	    
	    for(i=0;i<n;i++)
		    t[i]=0;
	
		for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                t[i] += a[i][j]*x[j];
        for(i=0;i<n;i++)
            t[i]-=b[i];
        r2 = norm2(n,t);	
        
    do
    {
		r1 = r2;
	
	    for(i=0;i<n;i++)
	    {
           for(j=0;j<i;j++)
			   sub1 += a[i][j]*x[j];
		
		   for(j=(i+1);j<n;j++)
			  sub2 += a[i][j]*x[j];
		
		    x[i] = (1-1)*x[i] + (1/a[i][i])*(b[i]-(sub1+sub2));
		    sub1 = 0;
		    sub2 = 0;
		
	    }
	    
	    for(i=0;i<n;i++)
		    t[i]=0;
	
		for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                t[i] += a[i][j]*x[j];
        for(i=0;i<n;i++)
            t[i]-=b[i];
        r2 = norm2(n,t);
        if ( r2 > r1);
        {
			flag = 1;
			break;
		}	
	}
    while((r2>k));
    
    if(flag)
    {
		printf("This system does not converge on gauss-seidel");
	}
	else
	{
		printf("Gauss-Seidel's result\n");
	    for(i=0;i<n;i++)
        {
		   printf("%f\n", x[i]);  
                   
	    }
	 }
	
	   
	return 0;
}
	
	


