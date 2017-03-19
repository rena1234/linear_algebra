
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float norm2(int n, float b[])
{
	//for vectors
  int i;
   float s = 0;
	
   
	for(int i = 0;i<n;i++)
	   s += b[i]*b[i];
	   
	   s = sqrt(s);
	   return s;
		  
}
int main(){
    printf("Enter the magnitude of the matrix A\n");double n; scanf("%d",&n);
    printf("Enter the A matrix elements \n"); double a[n][n];
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) scanf("%f", &a[i][j]);   
    printf("Enter b vector\n"); double b[n];  
    for(int i = 0;i<n;i++) scanf("%f",&b[i]);
    printf("Enter a tolerance number\n"); double tol; scanf("%f", &tol); 
    
    double prevRes = 0; double res = 0; bool nConv = false;
    double x[n]; for(int i = 0; i < n; i++) x[i] = 0;
    do{
        for(int i = 0;i<n;i++){
	    double sum1 = 0; double sum2 = 0;
            for(int j = 0;j<i;j++) sum1 += a[i][j] * x[j];
	    for(j=(i+1);j<n;j++) sum2 += a[i][j] * x[j];
	    x[i] = (1-1)*x[i] + (1/a[i][i])*(b[i]-(sum1+sum2));
	  }
	  double resVec; for(int i = 0;i<n;i++) resVec[i]=0;
	  for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) resVec[i] += a[i][j]*x[j];
          for(int i = 0;i<n;i++) resVec[i]-=b[i];
	  prevRes = res; res = norm2(n,resVec);
          if(res > prevRes){ nConv = true; break; }	
	}
    while(res > tol);
    
    if(nConv) printf("This system does not converge on gauss-seidel");
    else{
        printf("Gauss-Seidel's result\n");
	for(int i = 0;i<n;i++)
        printf("%f\n", x[i]);  
    }
}
