#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int five_count = 1;
    
    while(1) {
        if ((int)pow(5, five_count) >= N) {
            break;
        }
        five_count++;
    }
    
    int divider = 5;
    
    int count = 0;
    
    for (int i = 1; i <= five_count; i++) {
        count += N / divider;
        divider *= 5;
    }
    
    printf("%d", count);
}