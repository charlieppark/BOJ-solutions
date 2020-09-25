#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char str[1000001] = "";
	int alpha[26] = { 0, };

	char most_used;
	char overlap_val = 0;

	while (scanf("%s", str) != 1) continue;

	int len = strlen(str);

	for (int k = 0; k < len; k++)
	{
		if (str[k] > 'Z')
			str[k] -= ('a' - 'A');

		for (char i = 0; i < 26; i++)
		{
			if (str[k] == i + 'A')
			{
				alpha[i]++;
			}
		}
	}


	most_used = 0;

	for (int i = 1; i < 26; i++)
	{
		if (alpha[i] > alpha[most_used])
		{
			overlap_val = 0;
			most_used = i;
		}
		else if (alpha[i] == alpha[most_used])
		{
			overlap_val = 1;
		}
	}

	if (overlap_val == 1)
		printf("?");
	else
		printf("%c", most_used + 'A');
}