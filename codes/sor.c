
#include<stdio.h>
#include<math.h>

double norm2(int n, float b[]){
    /*
     * vector's norm 2
     */
    double s = 0;
    for(int i = 0; i < n; i++ ) s += b[i] * b[i];
    s = sqrt(s); return s;
}

void sor( int n, double w, float a[][n], float b[], float x[] ){	
    int i,j;
    for(i = 0; i < n; i++){
       double sub1 = 0; float sub2 = 0;
       for(int j = 0; j < i; j++) sub1 += a[i][j] * x[j];
       for(int j = ( i + 1 ); j < n; j++) sub2 += a[i][j] * x[j];
       x[i] = (1 - w) * x[i] + (w / a[i][i]) * (b[i] - (sub1 + sub2 ));
    }	
}

int main(){
    printf("enter the A matrix magnitude :\n"); int n; scanf("%d", &n);
    printf("Enter the elements of A\n"); double a [n][n];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) scanf("%lf", &a[i][j]);
    printf("enter b vector\n"); double b[n];
    for(int i = 0; i < n; i++) scanf("%lf",&b[i]);
    printf("enter a tolerance\n\n"); double tol; scanf("%lf",&tol);
    printf("enter an initial x value\n"); double x[n];
    for(int i = 0; i < n; i++) scanf("%lf",&x[i]);       
    printf("enter w value between 0 and 2\n"); double w;
    do scanf("%lf",&w); while (!(w > 0 && w < 2));
    
    do{
        int resVec; for(int i = 0; i < n; i++) resVec[i]=0;
	sor(n,w,a,b,x);
	for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) resVec[i] += a[i][j] * x[j];
        for(int i=0;i<n;i++) resVec[i] -= b[i];     	  
    }while(norm2(n,resVec) > tol);
    printf("Sor result\n"); for(i=0;i<n;i++) printf("%lf\n",x[i]);
}
