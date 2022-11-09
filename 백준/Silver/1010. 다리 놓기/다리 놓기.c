#include <stdio.h>
#include <stdlib.h>

// recursive
int combination(int n, int r, int** arr) {
    if (n == r) return 1;
    
    if (r == 0) {
        return 1;
    } else if (r == 1) {
        return n;
    } else {
        if (!arr[n-1][r-1]) {
            arr[n-1][r-1] = arr[n-1][n-r] = combination(n-1, r-1, arr);
        }
        if (!arr[n-1][r]) {
            arr[n-1][r] = arr[n-1][n-r-1] = combination(n-1, r, arr);
        }
        
        return arr[n-1][r-1] + arr[n-1][r];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int N, M;
        
        scanf("%d %d", &N, &M);
        
        int** arr = malloc(sizeof(*arr) * M);
        
        for (int j = 0; j < M; j++) {
            arr[j] = calloc(M, sizeof(**arr));
        }
        
        printf("%d\n", combination(M, N, arr));
    }
}