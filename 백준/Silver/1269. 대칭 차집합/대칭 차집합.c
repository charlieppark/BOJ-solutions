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
        return -1;
    }
    
    int idx = (from + to) / 2;
    
    if (arr[idx] < n) {
        return binary_search(n, arr, idx + 1, to, len);
    } else if (arr[idx] > n) {
        return binary_search(n, arr, from, idx - 1, len);
    } else {
        return idx;
    }
}

int main() {
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    int* arr = malloc(sizeof(*arr) * A);
    
    for (int i = 0; i < A; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, A, sizeof(*arr), compare);
    
    int count = A;
    
    for (int i = 0; i < B; i++) {
        int b;

        scanf("%d", &b);
        
        int search_idx = binary_search(b, arr, 0, A - 1, A);
        
        if (search_idx != -1) {
            count--;
        } else {
            count++;
        }
    }
    
    printf("%d", count);
}