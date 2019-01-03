#include<stdio.h>
#include<omp.h>
#define A_rows 3
#define A_columns 3
#define B_rows 3
#define B_columns 3
int main()
{
	int i,j,k,chunk=3,tid,n_threads;
	int A[A_rows][A_columns], B[B_rows][B_columns], C[A_rows][B_columns];
	#pragma omp parallel shared(A,B,chunk,n_threads) private(tid,i,j,k)
	{
		tid = omp_get_thread_num();
		if(tid == 0)
		{
			n_threads = omp_get_num_threads();
			printf("Number of threads = %d\n",n_threads);
		}
		#pragma omp for schedule(static,chunk)
		for(i=0;i<A_rows;i++)
		for(j=0;j<A_columns;j++)
		A[i][j] = 1;
		#pragma omp for schedule(static,chunk)
		for(i=0;i<B_rows;i++)
		for(j=0;j<B_columns;j++)
		B[i][j] = 1;
		#pragma omp for schedule(static,chunk)
		for(i=0;i<A_rows;i++)
		for(j=0;j<B_columns;j++)
		C[i][j] = 0;
		#pragma omp for schedule(static, chunk)
		for(i=0;i<A_rows;i++)
		{
			printf("Thread %d did row %d\n",tid,i);
			for(j=0;j<B_columns;j++)
			for(k=0;k<A_columns;k++)
			C[i][j] += A[i][k] * B[k][j];
		}
	}
	for(i=0;i<A_rows;i++)
	{
		for(j=0;j<B_columns;j++)
		printf("%d ",C[i][j]);
		printf("\n");
	}
}
