#include <stdio.h>

void Hanoi(int, int, int);
int Hanoi_count(int);

int main()
{
    int N;

    while (scanf("%d", &N) != 1) continue;

    printf("%d\n", Hanoi_count(N));
    Hanoi(N, 1, 3);

    return 0;
}

void Hanoi(int n, int from, int to)
{
    if (n == 1)
        printf("%d %d\n", from, to);
    else
    {
        int stopover;
        stopover = 6 - (from + to);
        Hanoi(n - 1, from, stopover);
        printf("%d %d\n", from, to);
        Hanoi(n - 1, stopover, to);
    }
}

int Hanoi_count(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return 2 * Hanoi_count(n - 1) + 1;
    }
}
