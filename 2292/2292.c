#include <stdio.h>

int main()
{
    int N;
    int num = 0;

    while (scanf("%d", &N) != 1) continue;

    while (1)
    {
        int temp = 1 + 6 * num * (num + 1) / 2;
        if (temp >= N)
            break;
        num++;
    }

    num++;

    printf("%d", num);
    return 0;
}