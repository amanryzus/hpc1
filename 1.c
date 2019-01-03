#include<stdio.h>
#include<omp.h>
#define N 10
#define CHUNK 1
int main()
{
	int A[N],B[N],C[N];
	int i,tid;
	omp_set_num_threads(10);
	#pragma omp parallel for
	for(i = 0;i<N;i++)
	{
		A[i] = B[i] = 1; C[i] = 0;
	}
	#pragma omp parallel for schedule(static,CHUNK)
	for(i=0;i<N;i++)
	{
		C[i] = A[i] + B[i];
		printf("Thread %d did C[%d] = %d\n",omp_get_thread_num(),i,C[i]);
	}
	for(i=0;i<N;i++)
	{
		printf("C[%d] = %d\n",i,C[i]);
	}
} 
