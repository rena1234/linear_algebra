
#include <stdio.h>
#include <math.h>

void substituicaofrente (int n, float a[][n], float b [])
{
 int i,j;
 float c[n];
 
 for(i=0;i<n;i++)
     c[i] = b[i]; 
 
 for(i=0;i<n;i++) 
        {
			if (i>0)
            for(j=0;j<=(i-1);j++)
                c[i] = c[i] - a[i][j] * c[j];
                
            c[i] = c[i]/a[i][i];
        }
        for(i=0;i<n;i++)
           b[i] = c[i];    
            
         
}

void substituicaotras (int n, float a[][n], float b [])
{
	int i,j;
 float c[n];
 
 for(i=0;i<n;i++)
     c[i] = b[i]; 
     
	for(i=n-1;i>=0;i--) 
        {
            for(j=n-1;j>=i+1;j--)
                c[i] = c[i] - a[i][j] * c[j];
           
            c[i] = c[i]/a[i][i];
         }
     
     for(i=0;i<n;i++)
           b[i] = c[i]; 
     
}
int main(){
    printf("Enter the A matrix mgnitude\n"); int n; scanf("%d",&n);
    printf("Enter A elements\n"); float a[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%f", &a[i][j]);
  
    float l[n][n],u[n][n];
    for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
            if(int j <= i){
                u[j][i] = a[j][i];
                for(int k = 0; k <= j - 1; k++) 
                    u[j][i] -= l[j][k] *u [k][i];
                
                if(j == i) l[j][i] = 1;
                else l[j][i]=0;
            }else{
                l[j][i]=a[j][i];
                for(int k = 0; k <= i - 1; k++)
                    l[j][i]-=l[j][k]*u[k][i];
                
                l[j][i] /= u[i][i]; u[j][i] = 0;
            }
        }
    }
   printf ("L factor\n");
   for(int i = 0; i < n; i++)
        {
            for(int j = 0;j < n; j++)
            
                printf("%f ", l[i][j]);
             printf("\n");
         }
         printf("\n");
        
    printf ("U factor\n");
    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            
                printf("%f ", u[i][j]);
             printf("\n");
          }
        printf("\n");
      
    printf("Enter b vector\n" ); float b[n];
     
    for (int i = 0; i < n; i++)
        {
			scanf("%f",&b[i]);
			
	    }         
    substituicaofrente(n,l,b);    
    substituicaotras(n,u,b);
    
    printf("result\n");   
    for (i=0;i<n;i++) 
    printf("%f\n", b[i]);
	
    return 0;
}
