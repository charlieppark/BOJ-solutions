#include <stdio.h>
#include <stdlib.h>

int main() {
    int space[100][100];
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            space[i][j] = 0;
        }
    }
    
    int N;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                space[j][k] = 1;
            }
        }
    }
    
    int area = 0;
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (space[i][j]) area += 1;
        }
    }
    
    printf("%d", area);
}