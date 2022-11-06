/*
  2447.c
  <별 찍기 - 10>
  Created by Chan Ho Park on 2021.7.4.
*/

#include <stdio.h>
#include <stdlib.h>

void star(int N, char** arr, int size);

int main()
{
    int N;

    while (scanf("%d", &N) != 1) continue;

    char** star_arr = (char**)malloc(sizeof(char*) * N);

    if (star_arr == NULL)
    {
        printf("malloc failed");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        star_arr[i] = (char*)calloc(N, sizeof(char));

        if (star_arr[i] == NULL)
        {
            printf("malloc failed");
            exit(1);
        }
    }

    star(N, star_arr, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (star_arr[i][j])
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
    
    return 0;
}

void star(int N, char** arr, int size)
{
    if (N == 1)
        return;
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (((i / (N / 3)) % 3 == 1) && ((j / (N / 3)) % 3 == 1))
                {
                    arr[i][j] = 1;
                }
            }
        }

        star(N / 3, arr, size);
    }
}