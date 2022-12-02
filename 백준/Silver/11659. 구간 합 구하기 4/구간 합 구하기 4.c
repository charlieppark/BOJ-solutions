#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int* arr = malloc(sizeof(*arr) * (N + 1));
    int* sum = malloc(sizeof(*sum) * (N + 1));
        
    sum[0] = arr[0] = 0;
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", arr + i);
        sum[i] = sum[i - 1] + arr[i];
    }
    
    for (int k = 0; k < M; k++) {
        int i, j;
        scanf("%d %d", &i, &j);
        
        printf("%d\n", sum[j] - sum[i-1]);
    }
}