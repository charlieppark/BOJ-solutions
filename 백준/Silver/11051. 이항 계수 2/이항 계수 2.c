#include <stdio.h>
#include <stdlib.h>

long long arr[1000][1000] = { 0, };

// recursive
long long combination(int n, int r) {
    if (n == r) return 1;
    
    if (r == 0) {
        return 1;
    } else if (r == 1) {
        return n;
    } else {
        if (!arr[n-1][r-1]) {
            arr[n-1][r-1] = arr[n-1][n-r] = combination(n-1, r-1) % 10007;
        }
        if (!arr[n-1][r]) {
            arr[n-1][r] = arr[n-1][n-r-1] = combination(n-1, r) % 10007;
        }
        
        return (arr[n-1][r-1] + arr[n-1][r]) % 10007;
    }
}

int main() {

    int N, K;

    scanf("%d %d", &N, &K);

    printf("%lld\n", combination(N, K) % 10007);
}