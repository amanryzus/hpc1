#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define CHUNK 2
int main()
{
	char c;
	omp_set_num_threads(5);
	#pragma omp parallel for schedule(static,CHUNK)
	for(c='A';c<='Z';c++)
	{
		printf("Thread %d print %c\n",omp_get_thread_num(),c);
	}
}
