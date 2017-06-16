#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double det(int n , double a [][n] ){
    double d = 0; double m[n - 1][n - 1];
    if(n == 2){d = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]); return d;}
    else{
        for(int k = 0; k < n; k++){
		   
            /*
             * i starts on 1 in order to "trhow away" the line 0
             */
            for(int i = 1; i < n; i++) {
                int l = 0;
                for (int j = 0; j < n; j++){
               
                    /*
                     * loop does not execute when "j == k" in order to
                     * "trhow away" the column k
                     */
                    if (j == k) continue;
                    m[i-1][l] = a[i][j];l++;
                }
            }
          
            /*
             * pow(-1.0, k) because when k is even a sum happens and when k is
             * odd a subtraction happens
             */
            d += pow(-1.0, k) * a[0][k] * det(n - 1, m);
	    }
    }
    return d;
}

void cholesky(int n, double a[][n], double at[][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++) a[i][i] = a[i][i] - pow(a[j][i] ,2);
        if(a[i][i] <= 0){
            printf("This matriz is not positive defined"); exit(0);
        }
        a[i][i] = sqrt(a[i][i]);
        for(int j = i + 1;j <= n; j++){
            for(int k = 0; k < i; k++) a[i][j] = a[i][j] - a[k][i] * a[k][j];
            a[i][j] = a[i][j] / a[i][i];
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(i > j) a[i][j] = 0;
            at[i][j] = a[i][j];
        }
     for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i > j){ 
                    double r = at[i][j]; a[i][j] = at[j][i]; a[j][i] = r;
                }
}

int main(){
    printf("enter the magnitude of the matrix : \n");int n;
    scanf("%d", &n);
    
    
    // a função do cholesky sobrescreve as matrizes a e o vetor b
    double a[n][n], at[n][n];
    double b[n];
   
    double w; // soh usa pro sor
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
           
		return 0;
}
