#include<stdio.h>
#include<omp.h>

int main()
{	
        #pragma omp parallel
{
	int tid=omp_get_thread_num();
	if(tid==0)
	{
		printf(" %d \n",tid);
		printf(" %d \n",omp_get_num_threads());
		printf(" %d \n",omp_get_max_threads());
		printf(" %d \n",omp_get_num_procs());
		printf(" %d \n",omp_get_dynamic());
		printf(" %d \n",omp_in_parallel());
		printf(" %d \n",omp_get_nested());

	}
}
}

