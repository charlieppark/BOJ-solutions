#include <stdio.h>

int main()
{
    int N;

    while (scanf("%d", &N) != 1) continue;

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < i; k++)
            printf(" ");
        for (int k = N; k > i; k--)
            printf("*");
        for (int k = N; k > i + 1; k--)
            printf("*");
        printf("\n");
    }
    for (int i = 1; i < N; i++)
    {
        for (int k = N - 1; k > i; k--)
            printf(" ");
        for (int k = 0; k < i; k++)
            printf("*");
        for (int k = 0; k <= i; k++)
            printf("*");
        printf("\n");
    }

    return 0;
}
