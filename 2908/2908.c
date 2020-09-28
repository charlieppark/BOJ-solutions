#include <stdio.h>

int modify(int);

int main()
{
    int A, B;
    while (scanf("%d %d", &A, &B) != 2) continue;
    A = modify(A);
    B = modify(B);

    if (A > B)
    {
        printf("%d", A);
    }
    else
    {
        printf("%d", B);
    }
}

int modify(int n)
{
    int modified = 0;
    while (1)
    {
        modified += n % 10;
        n /= 10;
        if (n == 0)
            break;
        modified *= 10;
    }

    return modified;
}