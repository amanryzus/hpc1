#include<stdio.h>
#include<omp.h>
#define N 5
#define CHUNK 3


int fac(int n)
{
	int result=1;
	int i;
	for(i=1;i<=n;i++)
	result*= i;

	return result;
}

int main()
{
//	int tid=omp_get_num_threads();
//	printf("\n no of threads :%d \n",tid);
	int x[5];
	int i=0,j=0;
	//printf(" testting fac or 7 %d",fac(6));
	
	#pragma omp parallel for
	for (i=0;i<N;i++)
	x[i]=fac(i);
	
	for(i=0;i<N;i++)
	printf("array [%d] %d \n",i,x[i]);
	j=0;
	#pragma omp parallel for firstprivate(x,j)
	for(i=1;i<N;i++)
	{
		j+=i;
		x[i]=j*x[i-1];
	}
	for(i=0;i<N;i++)
	printf("%d %d \n",x[i],fac(i));

}

