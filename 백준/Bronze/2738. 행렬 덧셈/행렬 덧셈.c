#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    scanf("%d %d", &n, &m);
    int** mat_a = malloc(sizeof(*mat_a) * n);
    for (int i = 0; i < n; i++) {
        mat_a[i] = malloc(sizeof(**mat_a) * m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &(mat_a[i][j]));
        }
    }
    
    int** mat_b = malloc(sizeof(*mat_b) * n);
    for (int i = 0; i < n; i++) {
        mat_b[i] = malloc(sizeof(**mat_b) * m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &(mat_b[i][j]));
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat_a[i][j] + mat_b[i][j]);
        }
        printf("\n");
    }
}