
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float det(int n , float a [][n] )
{
  int i,j,k,l;
  float d = 0;
  float m[n-1][n-1];
  if(n==2)
      {
         d = (a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
         return(d);
      }
  else
  {
	  
	 for (k=0;k<n;k++)
	 {
	   for (i=1;i<n;i++) {
		   //"trhow away" the line 0
            l = 0;
            for (j=0;j<n;j++) {
               if (j == k) // trhow away the column [k] 
                  continue;
             
               m[i-1][l] = a[i][j];
               l++;
            }
         }
         d += pow(-1.0,k) * a[0][k] * det(n-1,m);
         //when k is even a sum happens, when k is odd a subtraction happens
	  }
   
   }
    return d;

}


void forwardSubstituition (int n, float a[][n], float b [])
{
 int i,j;
 float c[n];
 
 for(i=0;i<n;i++)
     c[i] = b[i]; 
 
 for(i=0;i<n;i++) // Rt * y = b
     {
        if (i>0)
            for(j=0;j<=(i-1);j++)
                c[i] = c[i] - a[i][j] * c[j];
          
            c[i] = c[i]/a[i][i];
        }
        for(i=0;i<n;i++)
           b[i] = c[i];    
            
         
      }

void backSubstituition (int n, float a[][n], float b [])
{
	int i,j;
        float c[n];
 
        for(i=0;i<n;i++)
            c[i] = b[i]; 
     
	for(i=n-1;i>=0;i--) // R * x  = y
        {
            for(j=n-1;j>=i+1;j--)
                c[i] = c[i] - a[i][j] * c[j];
   
            c[i] = c[i]/a[i][i];
         }
     
     for(i=0;i<n;i++)
           b[i] = c[i]; 
     
}



void cholesky(int n, float a[][n],float at[][n])
{
    int i,j,k;
    float r; //variavel de apoio

    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
            a[i][i] = a[i][i] - pow(a[j][i],2);
        if(a[i][i] <= 0)
        {
            printf("This matriz is not positive definete");
            exit (0);
        }
        a[i][i] = sqrt(a[i][i]);
        for(j=i+1;j<=n;j++)
        {
            for(k=0;k<i;k++)
                a[i][j] = a[i][j] - a[k][i] * a[k][j];
            a[i][j] = a[i][j]/a[i][i];
        }
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i > j)
                a[i][j]=0;
            at[i][j]=a[i][j];
        }
    
    

   
   
    
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
               
                if(i > j)
                {
                    r=at[i][j];
                    a[i][j]=at[j][i];
                    a[j][i]=r;
                }
            }
            
        }
        
    
       
}

int main ()
{
	int n;
    printf("enter the magnitude of the matrix : \n");
    scanf("%d", &n);
    
    // a função do cholesky sobrescreve as matrizes a e o vetor b
    // as variaveis ac e bc servem para guardar os valores iniciais pra fazer o sor.
    float a[n][n], at[n][n];
    float b[n];
   
    float w; // soh usa pro sor
    int i, j;
   
    printf("Enter the A matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
	        scanf("%f", &a[i][j]);
				
            }
        w = det(n,a);
        if(!w)
        {
	    printf("This matrix is singular ");
		return 0;
	}
		
	
		
  
      
       cholesky(n,a,at);
       
       printf("The Rt factor of Cholesky is: \n");
       for (i=0;i<n;i++){
	    for(j=0;j<n;j++)
               printf("%f ",at[i][j]);
             printf("\n");
           }
           printf("\n");
           
       printf("The R factor of Cholesky is: \n");
       for (i=0;i<n;i++){
           for(j=0;j<n;j++)
               printf("%f ",a[i][j]);
             printf("\n");
           }
            printf("\n");
           
       printf("Enter the b vector\n");        
       for(i=0;i<n;i++)
        {
          scanf("%f",&b[i]);
          
       }
    
       printf("\n");
       
       forwardSubstituition(n,a,b);    
       backSubstituition(n,at,b);
        
        

       printf("The x vector is:\n");
        
       for (i=0;i<n;i++) 
       printf("%f\n", b[i]);
  
           
          
       
          
		return 0;
            
	
}

