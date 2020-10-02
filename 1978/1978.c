#include <stdio.h>

int main()
{
    int N;

    int non_prime[1000] = { 0, };

    while (scanf("%d", &N) != 1) continue;

    for (int j = 2; j <= 499; j++)
    {
        for (int t = 2; t * j < 1000; t++)
            non_prime[t * j] = 1;
    }

    non_prime[0] = non_prime[1] = 1;

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        int temp;
        while (scanf(" %d", &temp) != 1) continue;
        if (non_prime[temp] == 0)
        {
            count++;
        }
    }
    printf("%d", count);
}
