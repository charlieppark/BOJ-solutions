#include <stdio.h>

long long sum(int* a, int n);

int main()
{
	return 0;
}

long long sum(int* a, int n)
{
	int sum = 0;

	a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		sum += a[i];

	return sum;
}