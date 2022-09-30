#include <stdio.h>
#include <stdlib.h>

void merge_sort(int* A, int p, int r, int* K);

void merge(int* a, int p, int q, int r, int* K);

int res = -1;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int* arr = malloc(sizeof(*arr) * (N + 1));
    for (int i = 1; i <= N; i++) {
        scanf("%d", arr + i);
    }
    
    merge_sort(arr, 1, N, &K);
    free(arr);
    printf("%d", res);
}

void merge_sort(int* A, int p, int r, int* K) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q, K);
        merge_sort(A, q + 1, r, K);
        merge(A, p, q, r, K);
    }
}

void merge(int* A, int p, int q, int r, int* K) {
    int i = p;
    int j = q + 1;
    int t = 1;
    int* tmp = malloc(sizeof(*tmp) * (r + 1));
    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        } else {
            tmp[t++] = A[j++];
        }
    }
    while (i <= q) {
        tmp[t++] = A[i++];
    }
    while (j <= r) {
        tmp[t++] = A[j++];
    }
    i = p;
    t = 1;
    while (i <= r) {
        (*K)--;
        if (*K == 0) {
            res = tmp[t];
        }
        A[i++] = tmp[t++];
    }
    free(tmp);
}