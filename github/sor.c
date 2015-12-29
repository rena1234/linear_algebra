
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

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
void sor (int n,float w, float a[][n], float b[], float x[])
{
	float sub1 =0;
	float sub2 =0;
	int i,j;
	for(i=0;i<n;i++)
	{
        for(j=0;j<i;j++)
		{
			sub1 += a[i][j]*x[j];
		 
		}
		
		for(j=(i+1);j<n;j++)
		{
			sub2 += a[i][j]*x[j];
		 
		}
		
		x[i] = (1-w)*x[i] + (w/a[i][i])*(b[i]-(sub1+sub2));
		sub1 = 0;
		sub2 = 0;
		
	}	
	
	
	
	
}
 


         



int main ()
{
	int n;
    printf("enter the A matrix magnitude : \n");
    scanf("%d", &n);
    
    float a [n][n];
    float b[n],t[n];
    float x[n]; // soh usa pro sor
    float w; // soh usa pro sor
    int i, j;
    float k;
    printf("Enter the elements of A\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
				scanf("%f", &a[i][j]);
				
            }
           
       printf("enter b vector\n");        
       for(i=0;i<n;i++)
        {
          scanf("%f",&b[i]);
          
       }
    
       printf("enter a tolerance\n");
       scanf("%f",&k);
       printf("\n");  
       
     
       printf("enter an initial x value\n");
       
       for(i=0;i<n;i++)
           scanf("%f",&x[i]); 
           
      printf("enter w value between 0 and 2\n");
      
      
      do
         scanf("%f",&w);
      while (!(w>0 && w<2));
       
      do
    {
		for(i=0;i<n;i++)
		   t[i]=0;
		sor(n,w,a,b,x);
		for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                t[i] += a[i][j]*x[j];
        for(i=0;i<n;i++)
            t[i]-=b[i];     
	  
	}
    while((norm2(n,t)>k));
       
    printf("Sor result\n");
    for (i=0;i<n;i++) 
         printf("%f\n", x[i]);
     
   
          
       
          
		return 0;
            
	
}

