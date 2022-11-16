#include <stdio.h>
#include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int binary_search(int n, int* arr, int from, int to, int len) {
    if (from > to || from >= len || to < 0) {
        return 0;
    }
    
    int idx = (from + to) / 2;
    
    if (arr[idx] < n) {
        return binary_search(n, arr, idx + 1, to, len);
    } else if (arr[idx] > n) {
        return binary_search(n, arr, from, idx - 1, len);
    } else {
        return 1;
    }
}

int main() {
    int N;
    
    scanf("%d", &N);
    
    int* arr = malloc(sizeof(*arr) * N);
    
    for (int i = 0; i < N; i++) {
        int temp;
        
        scanf("%d", &temp);
        
        arr[i] = temp;
    }
    
    qsort(arr, N, sizeof(*arr), compare);
    
    int M;
    
    scanf("%d", &M);
    
    for (int i = 0; i < M; i++) {
        int temp;
        
        scanf("%d", &temp);
        
        printf("%d\n", binary_search(temp, arr, 0, N - 1, N));
    }
}