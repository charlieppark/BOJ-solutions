#include <stdio.h>

void c_to_max(int*, int*, int*);
void swap(int*, int*);

int main()
{
    while (1)
    {
        int a, b, c;
        while (scanf("%d %d %d", &a, &b, &c) != 3) continue;
        if ((a == 0 && b == 0) && c == 0)
            break;

        c_to_max(&a, &b, &c);

        if (a * a + b * b == c * c)
            printf("right\n");
        else
            printf("wrong\n");
    }

    return 0;
}

void c_to_max(int* a, int* b, int* c)
{
    int* nums[3] = { a, b, c };
    for (int i = 0; i < 2; i++)
    {
        if (*nums[i] > * nums[i + 1])
            swap(nums[i], nums[i + 1]);
    }
}

void swap(int* p_a, int* p_b)
{
    int temp;
    temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
}
