#include <stdio.h>

int count = 0;

int fib (int n) {
    if (n == 1 || n == 2) {
        count++;
        return 1;
    } else {
        return (fib(n - 1) + fib(n - 2));
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    fib(n);
    
    printf("%d %d", count, n - 2);
}