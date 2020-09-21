#include <stdio.h>

int main()
{
	int temp;
	int arr[10] = { -1, };

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &temp);

		arr[i] = temp % 42;
	}


}