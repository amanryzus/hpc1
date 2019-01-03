#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 10000
int main()
{
	int n=10,cur_max=0;
	int a[n];
	
	omp_lock_t lock;
	#pragma omp for
	for(i = 0;i<N;i++)
	a[i] = i;
	omp_init_lock(&lock);
	#pragma omp parallel shared(a) private(i)
	{
		for(i=0;i<N;i++)
		{
			omp_set_lock(&lock);
			if(a[i] > cur_max)
			cur_max = a[i];
			omp_unset_lock(&lock);
		}
	}
	printf("Max is %d\n",cur_max);
}
