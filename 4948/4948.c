#include <stdio.h>

int main()
{
    int n;

    char non_prime[1000000] = { 0, };

    while (1)
    {
        while (scanf("%d", &n) != 1) continue;

        if (n == 0)
            break;

        for (int j = 2; j <= 2 * n; j++)
        {
            for (int t = 2; t * j <= 2 * n; t++)
            {
                if (non_prime[t * j] != 1)
                    non_prime[t * j] = 1;
            }
        }

        non_prime[0] = non_prime[1] = 1;

        int count = 0;

        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (non_prime[i] == 0)
            {
                count++;
            }
        }

        printf("%d\n", count);
    }
}