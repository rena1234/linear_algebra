#include <stdio.h>
#include <math.h>

double infinitnorm (int n, double b []){
	double c[n];
	for(int i = 0; i < n; i++) c[i] = b[i];
	double m = c[1];   
	for(int i = 0; i < n; i++){c[i] = (c[i] * c[i]); c[i] = sqrt(c[i]);}
	for(int i = 0; i < n; i++) if(m < c[i]) m = c[i];
	return m;
}
int main(){
    printf("Enter the matrix size\n"); int n; scanf("%d", &n);
    printf("Enter A matrix values\n"); 
    double a[n][n];
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) scanf("%f", &a[i][j]);
    printf("Enter a initial eigen-vector\n");
    double eigenVec[n];
    for(int i = 0; i < n; i++) scanf("%f", &eigenVec[i]);
    double norm;
    do{
        double newEigenVec[n]; for(int i = 0; i < n; i++) newEigenVec[i] = 0;     
        // finding eigen-vector 
        for(int i = 0;i<n;i++) 
            for(int j = 0;j<n;j++) newEigenVec[i] += a[i][j] * eigenVec[j];
             
        norm = infinitnorm(n,newEigenVec);         
       // vector normalization       
       for(int i = 0;i<n;i++) newEigenVec[i]=(newEigenVec[i]/norm);
      
       double aux[n];
       for(int i = 0;i<n;i++)
           aux[i] = sqrt(newEigenVec[i]*newEigenVec[i]) 
              - sqrt(eigenVec[i] * eigenVec[i]);
      
       norm = infinitnorm(n,aux);	       
       for(int i = 0;i<n;i++) eigenVec[i] = newEigenVec[i];
    }while ( norm > 0.0000001 );
    
   // finding eigen-value
   double eigenValue[n] ; for(int i = 0; i < n; i++) eigenValue[i] = 0;
   for(int i = 0;i<n;i++) 
       for(int j = 0;j<n;j++) eigenValue[i] += a[i][j] * eigenVec[j];
   double acm = 0;
   for(int i = 0; i < n; i++) acm += eigenValue[i] * eigenVec[i];
   double pInternoEvec = 0; 
   for (int i = 0; i < n; i++)  pInternoEvec += pow(eigenVec[i], 2);	
        
 printf("aproximated dominant eigen-value is: \n");        
 printf("%f\n", acm / pInternoEvec);        
}
