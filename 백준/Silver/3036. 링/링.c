#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    int* arr = malloc(sizeof(*arr) * N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &(arr[i]));
    }
    
    for (int i = 1; i < N; i++) {
        int a, b;
        a = arr[0];
        b = arr[i];
        
        int divider = 1;
        
        int larger = a > b ? a : b;
        
        for (int j = 2; j <= a && j <= b; j++)
        {
            if ((a % j == 0) && (b % j == 0))
            {
                divider *= j;
                a /= j;
                b /= j;
                j = 1;
            }
    
        }
        
        printf("%d/%d\n", a, b);
    }
}