#include <stdio.h>

int main()
{
	int temp;
	int arr[10] = { -1, };
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &temp);
		arr[i] = temp % 42;
	}

	for (int k = 0; k < 42; k++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (arr[i] == k)
			{
				count++;
				break;
			}
		}
	}

	printf("%d", count);
}