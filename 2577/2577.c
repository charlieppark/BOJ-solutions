#include <stdio.h>

int main()
{
	int num[10] = { 0, };

	int A, B, C;

	int multi, digit;

	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	multi = A * B * C;

	while (multi != 0)
	{
		digit = multi % 10;
		multi /= 10;

		switch (digit)
		{
		case 0:
			(num[0])++;
			break;
		case 1:
			(num[1])++;
			break;
		case 2:
			(num[2])++;
			break;
		case 3:
			(num[3])++;
			break;
		case 4:
			(num[4])++;
			break;
		case 5:
			(num[5])++;
			break;
		case 6:
			(num[6])++;
			break;
		case 7:
			(num[7])++;
			break;
		case 8:
			(num[8])++;
			break;
		case 9:
			(num[9])++;
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;
}