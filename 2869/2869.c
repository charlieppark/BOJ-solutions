#include <stdio.h>

int main()
{
    int A, B, V;
    int day;

    while(scanf("%d %d %d", &A, &B, &V) != 3);

    if ((V - B) % (A - B) != 0)
        day = (V - B) / (A - B) + 1;
    else
        day = (V - B) / (A - B);

    printf("%d", day);

    return 0;
}