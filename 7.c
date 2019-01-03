#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define MAXIMUM 65536
int main()
{
	int *array, i, n_elements, cur_max, current_value;
	printf("Enter the number of elements\n");
	scanf("%d", &n_elements);
	if (n_elements <= 0)
	{
		printf("The array elements cannot be stored\n");
		exit(1);
	}
	array = (int*)malloc(sizeof(int)*n_elements);
	for(i=0;i<n_elements;i++)
	array[i] = i;
	cur_max = 0;
	#pragma omp parallel for
	for(i=0;i<n_elements;i++)
	{
		#pragma omp critical
		if(array[i] > cur_max)
		cur_max = array[i];
	}
	current_value = 0;
	for(i=0;i<n_elements;i++)
	{
		if(array[i] > current_value)
		current_value = array[i];
	}
	printf("%d %d\n",cur_max,current_value);
	for(i=0;i<n_elements;i++)
	printf("%d ",array[i]);
	printf("\n");
}
