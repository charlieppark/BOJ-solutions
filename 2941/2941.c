#include <stdio.h>
#include <string.h>

int main()
{
    const char* croatian[] = { "c=" , "c-" , "dz=", "d-", "lj", "nj", "s=", "z=" };

    char str[101] = "";

    while (scanf("%s", &str) != 1) continue;

    char str_len = strlen(str);

    char count = 0;

    for (int i = 0; i < str_len; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((str[i] == croatian[j][0]) && (str[i + 1] == croatian[j][1]))
            {
                if (str[i + 2] == '=')
                    i++;
                else if (j == 2)
                    break;
                i++;
                break;
            }
        }
        count++;
    }

    printf("%d", count);
}
