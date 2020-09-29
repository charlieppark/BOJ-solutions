#include <stdio.h>

int main()
{
    int X;
    int sum = 0;
    int n = 1;

    while (scanf("%d", &X) != 1) continue;

    while (1)
    {
        sum += n;
        if (sum >= X)
            break;
        n++;
    }

    int temp = sum - X;

    if (n % 2 == 1)
    {
        printf("%d/%d", 1 + temp, n - temp);
    }
    else
    {
        printf("%d/%d", n - temp, 1 + temp);
    }

    return 0;
}