
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double normaf (int m, int n,float a[][n]){
  /*
   * Frobenius norm
   */
   double r =0;
   for(int i=0;i<m;i++) for(int j=0;j<n;j++) r += pow(a[i][j],2);
   return sqrt(r); 	   
}

int main(){
    printf("vectors size\n"); int n; scanf("%d", &n);
    double vectors [n][n];
    for(int i = 0; i < n; i++){
        printf("Enter the elements of the vector %d\n", i+1);
        for(int j=0;j<n;j++) scanf("%lf", &vectors[i][j]);
    }
    for(int k = 0; k < n; k++){   
        double r[n][n];
        for(int i = 0; i < n; i++) for(int j=0; j < n; j++) r[i][j] = 0;
        for(int i= 0; i < k; i++){
      	    for(int j=0;j<n;j++) r[i][k]+= vectors[k][j] * vectors[i][j];
	    for(j=0;j<n;j++)
		vectors[k][j] = vectors[k][j] - vectors[i][j] * r[i][k];
	}
        double aux[n];
        for(int j = 0; j < n; j++) aux[j] = vectors[k][j];
        r[k][k] = norma2(n,aux);
            
        if (r[k][k] == 0){
	  printf("The vectors are dependent"); return 0;
        }
        for(int j=0; j < n; j++)
	    vectors[k][j] = (1 / r[k][k]) * vectors[k][j];
    }
    printf("Gram-Schmidt result\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) printf("%lf ", vectors[i][j]);       
        printf("\n");
    }
}
