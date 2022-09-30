#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    
    scanf("%d", &N);
    
    int min = 1000001;
    int max = -1;
    
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        
        if (max < a) max = a;
        if (min > a) min = a;
    }
    
    printf("%d", min * max);

    return 0;
}