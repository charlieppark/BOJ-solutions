#include <stdio.h>

int count_zeros[41] = { 0, };
int count_ones[41] = { 0, };

int main()
{
    count_zeros[0] = 1; count_ones[0] = 0;
    count_zeros[1] = 0; count_ones[1] = 1;
    for (int i = 2; i < 41; i++) {
        count_ones[i] = count_ones[i - 1] + count_ones[i - 2];
        count_zeros[i] = count_zeros[i - 1] + count_zeros[i - 2];
    }
    
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int num;
        scanf("%d", &num);
        printf("%d %d\n", count_zeros[num], count_ones[num]);
    }
}