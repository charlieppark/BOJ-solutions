#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    
    scanf("%d", &n);
    
    int* arr = malloc(sizeof(*arr) * n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &(arr[i]));
    }
    
    int* dp = malloc(sizeof(*dp) * n);
    
    dp[0] = arr[0];
    
    int max = dp[0];
    
    for (int i = 0; i < n; i++) {
        dp[i] = dp[i-1] + arr[i] > arr[i] ?  dp[i-1] + arr[i] : arr[i];
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    
    printf("%d", max);

    return 0;
}
