#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int a,b,tid;
float x;
#pragma omp threadprivate(a,x)
int main()
{
	//omp_set_dynamic(0);
	printf("1st parallel region\n");
	#pragma omp parallel private(tid,b)
	{
		tid = omp_get_thread_num();
		a = rand();
		b = rand();
		x = 1.1*tid + 1;
		printf("Thread %d ,a,b,x = %d,%d,%f\n",tid,a,b,x);
	}
	printf("\nMaster thread doing serial work\n\n");
	#pragma omp parallel private(tid,b)
	{
		tid = omp_get_thread_num();
		printf("Thread %d ,a,b,x = %d,%d,%f\n",tid,a,b,x);
	}
}
