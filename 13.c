#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 10000
int main() 
{
	int i,k,count = 0;
	double t1,t2;
	int a[N];	
	//a = (int *)malloc(sizeof(int)*(N));
	#pragma omp parallel for
	for(i=0;i<N;i++)
	a[i] = 1;
	k = 2;
	t1 = omp_get_wtime();
	#pragma omp parallel firstprivate(k)private(i)
{
	for (k=2; k*k<=N; k++) 
	{
	        if (a[k] == 1) 
	        {
	        	for (i=k*k; i<=N; i += k) 
	                a[i] = 0; 
	        } 
	}
	t2 = omp_get_wtime();
}
	#pragma omp for
	for(i=2;i<=N;i++)
	{
		if(a[i])
		{
			count++;
		}
	}
	printf("Time %f\n",t2-t1);
	printf("Total prime numbers are %d\n",count);
}
