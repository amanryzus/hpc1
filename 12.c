#include<stdio.h>
#include<omp.h>
long long factorial(long long n)
{
	int i;
	long result = 1;
	for(i=1;i<=n;i++)
	result *= i;
	return result;
}
int main()
{
	int i,j,n_threads;
	int n=12;
	long long x[n];
	omp_set_num_threads(5);
	printf("Max threads %d\n",omp_get_max_threads());
	for(i=0;i<n;i++)
	{
		x[i] = factorial(i);
	}
	j = 0;
	#pragma omp parallel for firstprivate(x,j)
	for(i=1;i<n;i++)
	{
	
		j+=i;
		x[i] = j*x[i-1];

	}
	for(i=1;i<n;i++)
	printf("factorial %d is %lld %lld\n",i,factorial(i),x[i]);


	return 0;
}
