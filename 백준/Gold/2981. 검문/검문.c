#include <stdio.h>
#include <stdlib.h>

int arr[100] = { 0, };

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int LCD(int a, int b)
{
    if (a % b == 0)
        return b;

    if (b % a == 0)
        return a;

    int temp_a = a;
    int temp_b = b;
    int smaller = a < b ? a : b;
    int lcd = 1;

    for (int i = 2; i < smaller; i++)
    {
        if (!(temp_a % i) && !(temp_b % i))
        {
            temp_a /= i;
            temp_b /= i;
            smaller /= i;
            lcd *= i;
            i--;
        }
    }

    return lcd;
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &(arr[i]));
    }
    
    qsort(arr, N, sizeof(*arr), compare);
    
    for (int i = 0; i < N - 1; i++) {
        arr[i] = arr[i + 1] - arr[i];
    }
    
    arr[N - 1] = 0;
    
    for (int i = 0; i < N - 2; i++) {
        arr[i + 1] = LCD(arr[i], arr[i + 1]);
    }
    
    for (int i = 2; i < arr[N - 2] / 2 + 1; i++) {
        if (arr[N - 2] % i == 0) {
            printf("%d ", i);
        }
    }
    
    printf("%d", arr[N - 2]);
    
    return 0;
}
