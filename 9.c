#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 1000
int main()
{
	int a[N],i,result=0;
	#pragma omp for
	for(i=0;i<N;i++)
	{
		a[i]=i;
	}
	#pragma omp parallel for reduction(+:result)
	for(i=0;i<N;i++)
	{
		result+=a[i];
	}
	printf("%d\n",result);
}
