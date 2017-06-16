#include <stdio.h>
# include <math.h>

double norm2(int n, double b[]){
    double s = 0; for(int i = 0; i < n; i++) s += b[i] * b[i];
    return s = sqrt(s);
}

int main(){
    printf("Enter the A matrix magnitude\n"); int n; scanf("%d", &n);
	double t[n];
    printf("Enter the elements of A\n"); double a[n][n];
    for(int i = 0; i < n; i++) 
       for(int j = 0; j < n; j++) scanf("%lf", &a[i][j]);
    printf("Enter the b vector\n"); double b[n];
    for(int i = 0; i < n; i++) scanf("%lf", &b[i]);
    printf("Enter an initial x vector\n"); double x[n];
    for(int i = 0; i < n; i++) scanf("%lf", &x[i]); 
    printf("Enter a tolerance number\n"); double tol; scanf("%lf", &tol);
	
    double r[n]; for(int i = 0; i < n; i++) r[i] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            r[i] += a[i][j] * x[j];
    for(int i = 0; i < n; i++) r[i] = b[i] - r[i];           
    double v = 0; for(int i = 0; i < n; i++) v += r[i]*r[i];  
    double p[n]; for(int i = 0; i < n; i++)  p[i] = r[i];
     do{
         double q[n]; for(int i = 0; i < n; i++) q[i] = 0;
         for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++) q[i] += a[i][j] * p[j];
         double u = 0 ; for(int i = 0; i < n; i++)  u += p[i] * q[i];
         double alfa = v / u;
         for(int i = 0; i < n; i++) x[i] += alfa * p[i];
         for(int i = 0; i < n; i++) r[i] += - alfa * q[i];
         double vPlus = 0; for(int i = 0; i < n; i++) vPlus += pow(r[i], 2);    
         double beta = vPlus/v;
         for(int i = 0; i < n; i++) p[i] = r[i] + beta * p[i];
         v = vPlus;
	     double t[n]; for(int i = 0; i < n; i++) t[i] = 0; 
         for(int i = 0; i < n; i++)
           for(int j = 0; j < n; j++) t[i] += a[i][j] * x[j];        
         for(int i = 0; i < n; i++) t[i] -= b[i];
    }while(norm2(n, t) > tol);
	 
    for(int i = 0;  i < n; i++)
        printf("%lf\n", x[i]);
}
