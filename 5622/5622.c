#include <stdio.h>
#include <string.h>

enum dial { ABC = 2, DEF, GHI, JKL, MNO, PQRS, TUV, WXYZ };

int main()
{
    const char* dial_str[] = { "" , "" , "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
    const char dial_str_len[] = { 0, 0, 4, 4, 4, 4, 4, 5, 4, 5 };

    char str[16] = "";

    while (scanf("%s", &str) != 1) continue;

    char str_len = strlen(str);

    char time = 0;

    for (int i = 0; i < str_len; i++)
    {
        for (int j = ABC; j <= WXYZ; j++)
        {
            for (int k = 0; k < dial_str_len[j]; k++)
            {
                if (str[i] == dial_str[j][k])
                    time += 1 + j;
            }
        }
    }


    printf("%d", time);

}
