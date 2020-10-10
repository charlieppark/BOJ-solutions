#include <stdio.h>


int main()
{
    int N;
    while (scanf("%d", &N) != 1) continue;

    int num = 666;
    int num_of_six_nums = 0;
    while (N != 0)
    {
        int six_counter = 0;
        int temp = num;
        while (temp != 0)
        {
            if (temp % 10 == 6)
                six_counter++;
            else
                six_counter = 0;
            temp /= 10;
            if (six_counter == 3)
            {
                num_of_six_nums++;
                if (num_of_six_nums == N)
                {
                    N = 0;
                    printf("%d", num);
                }
                break;
            }
        }
        num++;
    }
}
