#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
        return -1;

    if (*(int *)a > *(int *)b)
        return 1;

    return 0;
}

int main()
{
    int nums[5];
    
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", nums + i);
        sum += nums[i];
    }
    
    qsort(nums, 5, sizeof(int), compare);
    
    printf("%d\n%d", sum/5, nums[2]);
}
