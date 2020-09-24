#include <stdio.h>
#include <string.h>



int main()
{
	char s[100] = { 0, };
	char alpha[26];

	const int num_to_alpha_by_ascii = 97;

	while (scanf("%s", &s) != 1) continue;

	for (int i = 0; i < 26; i++)
	{
		alpha[i] = -1;
	}

	for (char i = 0; i < 26; i++)
	{
		for (int j = 0; j < strlen(s); j++)
		{
			if (s[j] == i + num_to_alpha_by_ascii)
			{
				alpha[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", alpha[i]);
	}
}