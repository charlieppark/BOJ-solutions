#include <stdio.h>
#include <stdlib.h>

typedef int(*FP)(int, int);

int comparison(int* arr, FP, int);

int bigger(int, int);
int smaller(int, int);

int main()
{
    int N;
    scanf("%d", &N);

    int* arr = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int min = comparison(arr, smaller, N);
    int max = comparison(arr, bigger, N);

    printf("%d %d", min, max);
}


int comparison(int* arr, FP fp, int n)
{
    int result = arr[0];

    for (int i = 1; i < n; i++)
    {
        result = fp(arr[i], result);
    }

    return result;
}

int bigger(int A, int B)
{
    if (A > B)
        return A;
    else
        return B;
}

int smaller(int A, int B)
{
    if (A < B)
        return A;
    else
        return B;
}