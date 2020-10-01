#include <stdio.h>
#include <math.h>

int counter(int);

int main()
{
    int T, x, y, count;

    while (scanf("%d", &T) != 1);

    for (int i = 0; i < T; i++)
    {
        int distance;

        while (scanf("%d %d", &x, &y) != 2);

        distance = y - x;

        count = counter(distance);

        printf("%d\n", count);
    }


}

int counter(int d)
{
    int count = 0;
    int n;

    n = (int)sqrt((float)d);
    count += 2 * n - 1;
    d -= n * n;

    count += d / n;

    d %= n;
    if (d > 0)
        count++;

    return count;
}
