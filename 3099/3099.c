#include <stdio.h>

int main()
{
    int x[2] = { 0, };
    int y[2] = { 0, };
    for (int i = 0; i < 3; i++)
    {
        int temp_x, temp_y;
        while (scanf("%d %d", &temp_x, &temp_y) != 2);
        for (int j = 0; j < 2; j++)
        {
            if (x[j] == 0)
            {
                x[j] = temp_x;
                break;
            }
            else if (temp_x == x[j])
            {
                x[j] = -1;
                break;
            }
        }
        for (int j = 0; j < 2; j++)
        {
            if (y[j] == 0)
            {
                y[j] = temp_y;
                break;
            }
            else if (temp_y == y[j])
            {
                y[j] = -1;
                break;
            }
        }
    }

    int result[2] = { 0, };

    for (int k = 0; k < 2; k++)
    {
        if (x[k] != -1)
            result[0] = x[k];
    }

    for (int k = 0; k < 2; k++)
    {
        if (x[k] != -1)
            result[0] = x[k];
    }

    for (int k = 0; k < 2; k++)
    {
        if (y[k] != -1)
            result[1] = y[k];
    }

    printf("%d %d", result[0], result[1]);

    return 0;
}