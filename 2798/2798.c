#include <stdio.h>
#include <stdlib.h>


int main()
{
	int N, M;

	while (scanf("%d %d", &N, &M) != 2) continue;

	int* arr = (int*)malloc(sizeof(int) * N);

	if (arr == NULL)
	{
		printf("malloc failed. program will be shut down");
		exit(1);
	}

	for (int i = 0; i < N; i++)
	{
		while (scanf("%d", &arr[i]) != 1) continue;
	}

	int size = 1;

	for (int i = 0; i < 3; i++)
		size *= (N - i);

	size /= 6;

	int* sum_arr = (int*)malloc(sizeof(int) * size);
	int* dif_arr = (int*)malloc(sizeof(int) * size);

	if (sum_arr == NULL)
	{
		printf("malloc failed. program will be shut down");
		exit(1);
	}

	if (dif_arr == NULL)
	{
		printf("malloc failed. program will be shut down");
		exit(1);
	}

	int index = 0;

	for (int i = 2; i < N; i++)
	{
		for (int k = 1; k < i; k++)
		{
			for (int j = 0; j < k; j++)
			{
				sum_arr[index] = arr[j] + arr[k] + arr[i];
				dif_arr[index] = M - sum_arr[index];
				index++;
			}
		}
	}

	int min_index = 0;

	while (dif_arr[min_index] < 0)
		min_index++;


	if (min_index < size - 1)
	{
		for (int i = min_index + 1; i < size; i++)
		{
			if (dif_arr[i] >= 0)
			{
				if (dif_arr[min_index] > dif_arr[i])
					min_index = i;
			}
		}
	}
	printf("%d", sum_arr[min_index]);

	free(arr);
	free(sum_arr);
	free(dif_arr);

	return 0;
}
