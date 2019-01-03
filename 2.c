#include<stdio.h>
#include<omp.h>
#define N 10
int main()
{
	int A[N],B[N],C[N],D[N];
	int tid,n_threads,i,j;
	//init
	for(i=0;i<N;i++)
	{
		A[i] = B[i] = i;
		C[i] = D[i] = 0;
	}
	#pragma omp parallel shared(A,B,C,D,n_threads) private(i,j,tid)
	{
		tid = omp_get_thread_num();
		n_threads = omp_get_num_threads();
		if(tid == 0)
		printf("Number of threads = %d\n",n_threads);
		#pragma omp sections nowait
		{
			#pragma omp section
			{
				printf("Thread %d doing section 1\n",tid);
				for(i=0;i<N;i++)
				C[i] = A[i] + B[i];
				//printf("C[%d] = %d\n",i,C[i]);
			}
			#pragma omp section
			{
				printf("Thread %d doing section 2\n",tid);
				for(i=0;i<N;i++)
				D[i] = A[i] - B[i];
			}
		}
		printf("Thread %d done\n",tid);
	}
	printf("Finally:-\n");
	printf("C is \n");
	for(i = 0;i<N;i++)
	printf("%d ",C[i]);
	printf("\nD is \n");
	for(i = 0;i<N;i++)
	printf("%d ",D[i]);
}

