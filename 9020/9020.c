#include <stdio.h>

int main()
{
    int T, n;

    char non_prime[1000000] = { 0, };

    while (scanf("%d", &T) != 1) continue;

    for (int k = 0; k < T; k++)
    {
        while (scanf("%d", &n) != 1) continue;

        for (int j = 2; j <= n / 2; j++)
        {
            for (int t = 2; t * j <= n; t++)
            {
                if (non_prime[t * j] != 1)
                    non_prime[t * j] = 1;
            }
        }

        non_prime[0] = non_prime[1] = 1;

        for (int i = n / 2; i >= 2; i--)
        {
            if ((non_prime[i] == 0) && (non_prime[n - i] == 0))
            {
                printf("%d %d\n", i, n - i);
                break;
            }
        }
    }
}