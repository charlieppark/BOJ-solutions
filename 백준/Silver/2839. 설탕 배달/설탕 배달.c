#include <stdio.h>

int main()
{
    int fives, threes, N;
    
    scanf("%d", &N);
    
    fives = N / 5;
    
    while (1) {
        if (fives == -1) {
            threes = 0;
            break;
        }
        
        if ((N - fives * 5) % 3 == 0) {
            break;
        }
        
        fives--;
    }
    
    if (fives != -1) {
        threes = (N - fives * 5) / 3;
    }
    
    printf("%d", fives + threes);
}
