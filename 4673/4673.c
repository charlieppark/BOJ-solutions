#include <stdio.h>
#include <stdlib.h>

typedef char* (FP)();

char* d();

int main()
{

	char* arr = (char*)malloc(sizeof(int) * 10000);
	memset(arr, 0, sizeof(int) * 10000);

	arr[0] = 1;
	arr[2] = 1;
	arr[4] = 1;
	arr[6] = 1;
	arr[8] = 1;

	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			for (int c = 0; c < 10; c++)
			{
				for (int d = 0; d < 10; d++)
				{
					int num = a * 1001 + b * 101 + c * 11 + d * 2;

					if (num <= 10000)
					{
						arr[num] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < 10000; i++)
	{
		if (arr[i] == 0)
			printf("%d\n", i);
	}

	free(arr);

	return 0;
}


