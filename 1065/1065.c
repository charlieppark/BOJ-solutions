#include <stdio.h>
#include <math.h>

int main()
{
	int count = 0;

	int N, index;

	index = 0;

	char arr[3] = { 0, };

	while (scanf("%d", &N) != 1) continue;

	for (int n = 1; n <= N; a++)
	{
		for (int i = 0; i < 3; i++)
		{
			arr[i] = n % 10;
			n /= 10;
			if (n == 0)
				break;
		}
	}

	printf("%d", count);

	return 0;
}