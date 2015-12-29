#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float norma2(int n, float b[])
{
  int i;
   float s=0;
	
   
	for(i=0;i<n;i++)
	   s += b[i]*b[i];
	   
	   s = sqrt(s);
	   return s;
		  
}

int main()
{
	float li,ls,t,rnd,rnd1,rnd2;
	int nr,n,i,j,k,y,w;
	printf("entre com o limite superior (sugestão 3)\n");
	scanf("%f", &ls );
	t = ls;
	printf("entre com o limite inferior (sugestão 0)\n");
	scanf("%f", &li );
	printf("entre com o NR (sugestão 100000\n");
	scanf("%d", &nr);
	printf("digite o tamanho de A\n");
	scanf("%d", &n);
	
	float a[n][n],ac[n][n],s[n][n],si[n][n],v[n][n];
	float b[n],c[n],cc[n],cg[n],cgf[n];
	float nm;

	
	printf("digite A\n");
	
	for(i=0;i<n;i++)
        for(j=0;j<n;j++)
   		{
		    scanf("%f", &a[i][j]);
		    ac[j][i] = a[i][j];
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j] = ac[i][j];
            
    printf("digite b\n");
   	for(i=0;i<n;i++)
        scanf("%f", &b[i]);
        
        
    srand( (unsigned)time(NULL) );
    
    for(j=0;j<n;j++)
	   {
		    c[j]=rand()%101;
	   }
	   	 
	 for(k=0;k<n;k++)
           for(y=0;y<n;y++)
               cc[k]+= a[k][y] * c[y];
      
     for(j=0;j<n;j++)
           cc[j]-= b[j];
     
     nm = norma2(n,cc);          
			  
    while (t>li)
    {
		for(i=0;i<nr;i++)
		{
			for(j=0;j<n;j++)
			  {    int x;
				   while(1)
				   {
					   x = - 1 + rand() %3;
					   if (x) 
					   break;
				   }
				   c[j]=(rand())/(rand() * (float)x);
			  }	   
			  
			  
			   
			for(k=0;k<n;k++)
                for(y=0;y<n;y++)
                   cc[k]+= a[k][y] * c[y];
              
            for(j=0;j<n;j++)
                cc[j]-= b[j];
                
            //if ((norma2(n,cc)) < nm )  
                //{
					   //for(k=0;k<n;k++)
                           //{
							   //cg[k]=c[k];
                               //cgf[k] = c[k];
                           //}
                       //nm = norma2(n,cc);                    
                //}

				
			   rnd = rand() % 101;
			   rnd/=100;
			   if(rnd < ((float)exp((norma2(n,cc)))/t))
			   {
				   for(k=0;k<n;k++)
                           cg[k]=c[k];
			   }
			   
			
			 
			for(k=0;k<n;k++)
                for(y=0;y<n;y++)
                   cc[k] = 0 ;
			}
			
			t*=0.5; 
		}
		
	
	
	
	printf ("Resultado Simulated Anneling:\n");
	for(i=0;i<n;i++)
	    printf("%f\n", cg[i]);   
	   
	   
	
	printf("\n");
	return 0;
}
