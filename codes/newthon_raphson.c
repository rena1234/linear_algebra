#include <stdio.h>
#include <stdbool.h>
    
float f(float x, float coef[], int order){
    int aux = order; float s = 0;	
    for(int j = 0; j < order; j++){
        float m = 1; for(int i = 0; i < aux; i++) m *= x;
        s += m * coef[j]; aux--;
    } 
    return s + coef[order];	
}

float df(float x,float coef[], int order){
    int aux = order - 1; float s = 0;
    for(int j = 0; j < order; j++){
        float m = 1; for(int i = 0; i < aux; i++) m *= x;
        s += m * (aux + 1) * coef[j]; aux--;
     }
     return s;
}

int main(){
    printf("Enter the function order\n"); int order; scanf("%d", &order);
    printf("Enter an initial x\n"); float x; scanf("%f", &x);
    printf("enter a tolerance number\n"); float t; scanf("%f", &t);
    printf("Set the maximum number of iterations\n");
    int mni; scanf("%d", &mni);
    
    float coef[order+1];
    for(int i = 0; i < order + 1; i++){
        printf("Enter the coeficient of x^%d, type 0 if it doesn't exist\n",
	        order - i);
        scanf("%f", &coef[i]);
    }	
    printf("\n");
    
    float fx = f(x, coef, order);
	bool fail = false;
    if (fx < t){
       printf("%f is a aproximated root of the polynomial\n\n", x);
       printf("f(aproximated root) is %f\n",f(x, coef, order));
    }else{ 
        for(int i = 0; i < mni; i++){       
	    x = x - (fx / df(x, coef, order)); float newFx = f(x, coef, order);
        if(fx <= newFx){
	        printf("it does not converge\n"); fail = true; break;
	    }
	    if(newFx<t) break;
	    fx = newFx;
	}
        if(f(x, coef, order) > t && !fail){
            printf("it does not converge");
            printf("or the number of iterations are insuficient");
        }else if(!fail){
           printf("%f is a aproximated root of its polynomial\n", x);
           printf("f(aproximated root) is %f\n",f(x, coef, order));
        }
    }
}
