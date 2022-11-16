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

int lower_bound_binary_search(int n, int* arr, int from, int to, int len) {
    if (from > to || from >= len || to < 0) {
        return -1;
    }
    
    int idx = (from + to) / 2;
    
    if (arr[idx] < n) {
        return lower_bound_binary_search(n, arr, idx + 1, to, len);
    } else if (arr[idx] > n) {
        return lower_bound_binary_search(n, arr, from, idx - 1, len);
    } else {
        int ret_idx = lower_bound_binary_search(n, arr, 0, idx - 1, len);
        if (ret_idx == -1) return idx;
        else return ret_idx;
    }
}

int upper_bound_binary_search(int n, int* arr, int from, int to, int len) {
    if (from > to || from >= len || to < 0) {
        return -1;
    }
    
    int idx = (from + to) / 2;
    
    if (arr[idx] < n) {
        return upper_bound_binary_search(n, arr, idx + 1, to, len);
    } else if (arr[idx] > n) {
        return upper_bound_binary_search(n, arr, from, idx - 1, len);
    } else {
        int ret_idx = upper_bound_binary_search(n, arr, idx + 1, len - 1, len);
        if (ret_idx == -1) return idx;
        else return ret_idx;
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
        
        int lower_bound = lower_bound_binary_search(temp, arr, 0, N - 1, N);
        
        if (lower_bound == -1) {
            printf("0\n");
        } else {
            int upper_bound = upper_bound_binary_search(temp, arr, 0, N - 1, N);
            printf("%d\n", upper_bound - lower_bound + 1);
        }
    }
}