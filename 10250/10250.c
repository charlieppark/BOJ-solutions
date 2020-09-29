#include <stdio.h>

int main()
{
    int T, H, W, N;

    while (scanf("%d", &T) != 1) continue;

    for (int i = 0; i < T; i++)
    {
        int temp;
        while (scanf("%d %d %d", &H, &W, &N) != 3) continue;
        if (N % H == 0)
            printf("%d%02d", H, N / H);
        else
            printf("%d%02d", N % H, N / H + 1);
        printf("\n");
    }

    return 0;
}