#include <stdio.h>
#include <limits.h>

int main()
{
    int A, B, C;
    int difference;
    int break_even_point = 1;
    while (scanf("%d %d %d", &A, &B, &C) != 3) continue;

    if (C - B <= 0)
    {
        break_even_point = -1;
    }
    else
    {
        break_even_point = A / (C - B) + 1;
    }


    printf("%d", break_even_point);

    return 0;
}