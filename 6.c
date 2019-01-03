#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main()
{
	int tid,nthreads,procs,maxt,inpar,dynamic,nested;
	#pragma omp parallel private(nthreads,tid)
	{
		tid = omp_get_thread_num();
		procs = omp_get_num_procs();
		nthreads = omp_get_num_threads();
		maxt = omp_get_max_threads();
		inpar = omp_in_parallel();
		dynamic = omp_get_dynamic();
		nested = omp_get_nested();
		if(tid==0)
		{
			printf("Thread %d getting env info\n",tid);
			printf("Env info:-\n");
			printf("Number of processes = %d\n",procs);
			printf("Number of threads = %d\n",nthreads);
			printf("Max threads = %d\n", maxt);
			printf("In parallel? = %d\n", inpar);
			printf("Dynamic threads enabled? = %d\n", dynamic);
			printf("Nested parallelism supported? = %d\n", nested);
		}
	}
}
 
