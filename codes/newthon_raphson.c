#include <stdio.h>

float f(float x,float coef[],int g)
{
	int i,j;
	int gc = g;
	float m=1;
	float s=0;
	
	for(j=0;j<g;j++)
	   {
		   for(i=0;i<gc;i++)
	          m*=x;
	       s+=m*coef[j];   
	       m=1;   
	       gc--;
	   } 
	s+=1*coef[g];
	return s;
	
}
float df(float x,float coef[], int g)
{
	int i, j;
	float m=1;
	int gc = g-1;
	float s=0;
	
	for(j=0;j<g;j++)
	{
		for(i=0;i<gc;i++)
		    m*=x;
		s+=m*(gc+1)*coef[j];
		m = 1;
		gc--;
	}
	//s+=1;
	return s;
}

int main()
{
	int g,i;
	float x;
	float x1;
	float fx,fxb; // fxb stores fx in the previous iteration
	float flag=0;
	float t;
	int mni;
	printf("Digite o grau\n");
	scanf("%d", &g);
	float coef[g+1];
	printf("Enter an initial x\n");
	scanf("%f", &x);
	printf("enter a tolerance number\n");
	scanf("%f", &t);
	printf("Set the maximum number of iterations\n");
	scanf("%d", &mni);
	for(i=0;i<g+1;i++)
	    {
			printf("Enter the coeficient of x^%d, type 0 if it doesn't exist\n", g-i);
			scanf("%f", &coef[i]);
		}	
	    
	    printf("\n");
	
	fx = f(x,coef,g);
	if (fx<t)
	{
		printf("%f is a aproximated root of this polynomial\n\n", x);
	    printf("f(aproximated root) is %f\n",f(x,coef,g));
	} 
	else
	{ 
	for(i=0;i<mni;i++)
	{
		
		x1 = x-(fx/df(x,coef,g));
		x = x1;
		fxb = fx;
		fx = f(x,coef,g);
		
		if(fxb <= fx)
		{
			printf("it does not converge\n");
			flag = 1;
			break;
		}
		
		if(fx<t)
		break;
	}
	
	if(!flag)
	{
	
	    printf("%f is a aproximated root of this polynomial\n", x);
	    printf("f(aproximated root) is %f\n",f(x,coef,g));
	}
	if(f(x,coef,g)> t && !flag)
	{
		printf("it does not converge or the number of iterations are insuficient");
	}
} 
	return 0;
}

