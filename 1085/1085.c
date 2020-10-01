#include <stdio.h>

int smallest(int, int, int, int);

int main()
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d", smallest(x, y, w - x, h - y));

    return 0;
}

int smallest(int a, int b, int c, int d)
{
    int nums[3] = { b, c, d };
    int min = a;
    for (int i = 0; i < 3; i++)
    {
        if (min > nums[i])
            min = nums[i];
    }
    return min;
}