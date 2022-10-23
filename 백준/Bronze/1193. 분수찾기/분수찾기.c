#include <stdio.h>

int main() {
    int X;
    
    scanf("%d", &X);
    
    int n = 1;
    
    while(1) {
        if (X > n) {
            X -= n;
            n++;
            continue;
        } else {
            if (n % 2 == 1) {
                printf("%d/%d", n - X + 1, X);
                break;    
            } else {
                printf("%d/%d", X, n - X + 1);
                break;
            }
        }
    }
}