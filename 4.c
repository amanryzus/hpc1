#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 1000
int main()
{
	int a[N],b[N],i,result;
	#pragma omp for
	for(i=0;i<N;i++)
	{
		a[i] = b[i] = i;
	}
	#pragma omp parallel for reduction(+:result)
	for(i=0;i<N;i++)
	{
		result += a[i] + b[i];
	}
	printf("%d\n",result);
}

