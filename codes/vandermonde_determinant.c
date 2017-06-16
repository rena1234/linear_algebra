#include <stdio.h>
#include <math.h>

double det(int n , double a [][n] ){
    double r = 1;
	for (int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++)
		if(i > j) r*= (a[i][1] - a[j][1]); else break;
    return r;    
}

int main(){	
    printf("enter the matrix mgnitude\n"); int n; scanf("%d",&n); 
    printf("enter the matrix elements\n"); double a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
	        scanf("%lf", &a[i][j]);
            if (j == 0 && a[i][j] != 1){
                printf("it's not a vandermonde matrix\n"); return 0;
            }
	         if(j > 1 && pow(a[i][1],j) != a[i][j]){
                printf("its not a vandermonde matrix\n"); return 0;
            }                  
        } 
    printf("determinant\n"); printf ("%lf\n",det(n,a));	
}
