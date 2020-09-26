#include <stdio.h>
#include <string.h>

int main()
{
	char str[1000001] = "";
	int num = 0;

	while (scanf("%[ AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz]", str) != 1) continue;

	int len = strlen(str);

	for (int k = 0; k < len; k++)
	{
		if (str[k] == ' ' && ((k != 0) && (k != len - 1)))
			num++;
	}

	if ((strlen(str) != 1) || (str[0] != ' '))
		num++;

	printf("%d", num);
}