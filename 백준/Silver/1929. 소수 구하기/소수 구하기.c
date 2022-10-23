#include <stdio.h>

int main()
{
    int M, N;

    char non_prime[1000000] = { 0, };

    while(scanf("%d %d", &M, &N) != 2) continue;

    for (int j = 2; j <= N / 2; j++)
    {
        for (int t = 2; t * j <= N; t++)
        {
            if (non_prime[t * j] != 1)
                non_prime[t * j] = 1;
        }
    }

    non_prime[0] = non_prime[1] = 1;

    for (int i = M; i <= N; i++)
    {
        if (non_prime[i] == 0)
        {
            printf("%d\n", i);
        }
    }
    
}
