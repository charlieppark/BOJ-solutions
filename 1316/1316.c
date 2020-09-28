#include <stdio.h>
#include <string.h>

char group_word(char*);

int main()
{
    int N;

    while (scanf("%d", &N) != 1) continue;

    char str[101] = "";

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        while (scanf("%s", &str) != 1) continue;
        count += group_word(str);
    }

    printf("%d", count);
}

char group_word(char* str)
{
    const int num_to_alpha = 'a';

    char checker['z' - 'a' + 1] = { 0, };

    char str_len = strlen(str);

    for (int i = 0; i < str_len; i++)
    {
        int index = str[i] - num_to_alpha;
        if (checker[index] != 1)
            checker[index] = 1;
        else
            return 0;

        while (str[i] == str[i + 1])
            i++;
    }

    return 1;
}
