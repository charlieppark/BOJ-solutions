#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int* person;
	int* grade;

	while (scanf("%d", &N) != 1) continue;

	person = (int*)malloc(sizeof(int) * 2 * N);
	grade = (int*)malloc(sizeof(int) * N);
	memset(grade, 0, sizeof(int) * N);

	if ((person == NULL) || (grade == NULL))
	{
		printf("malloc failed. quit program");
		exit(1);
	}

	for (int i = 0; i < N; i++)
	{
		while (scanf("%d %d", &person[i], &person[i + N]) != 2) continue;
	}

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			if ((person[i] < person[k]) && (person[i + N] < person[k + N]))
			{
				grade[i] += 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", grade[i] + 1);
	}
}