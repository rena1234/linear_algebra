
#include <stdio.h>
#include <math.h>

int main(){
    printf("Enter the A matrix mgnitude\n"); int n; scanf("%d",&n);
    printf("Enter A elements\n"); float a[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%f", &a[i][j]);
  
    float l[n][n],u[n][n];
    for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
            if(j <= i){
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
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++)
            printf("%f ", l[i][j]); printf("\n");
        printf("\n");
    }
    printf("/n");

    printf ("U factor\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%f ", u[i][j]);
        printf("\n");
    }
    printf("\n");
      
    return 0;
}
