#include <stdio.h>
#include <stdlib.h>

int main() {
    int prime[10001] = { 0, };
    
    int T;
    
    scanf("%d", &T);
    
    prime[2] = 1;
    
    for (int i = 3; i <= 10000; i++) {
        if (i % 2 == 0) continue;
        
        int isPrime = 1;
        
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        
        prime[i] = isPrime;
    }
    
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        int a, b;
        for (int j = 0; j <= n/2; j++) {
            if (prime[j] && prime[n - j]) {
                a = j;
                b = n - j;
            }
        }
        printf("%d %d\n", a, b);
    }
}