#include <stdio.h>

long long combination(int, int);

long long factorial(int);

int main()
{
    int T, k, n;
    while (scanf("%d", &T) != 1) continue;

    for (int i = 0; i < T; i++)
    {
        long long num_of_people;

        while (scanf("%d\n%d", &k, &n) != 2) continue;

        num_of_people = combination(n + k, 1 + k);

        printf("%lld\n", num_of_people);
    }
}

long long combination(int m, int n)
{
    if (n > m / 2)
        n = m - n;

    if (m > n && n > 1)
        return combination(m - 1, n - 1) + combination(m - 1, n);
    else
        return factorial(m) / (factorial(n) * factorial(m - n));
}

long long factorial(int N)
{
    long long result = 1;

    for (int i = 1; i <= N; i++)
        result *= i;

    return result;
}