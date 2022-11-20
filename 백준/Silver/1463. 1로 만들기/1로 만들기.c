#include <stdio.h>

int dp[1000001] = { 0, };

int main()
{
    int X;
    
    scanf("%d", &X);
    
    dp[1] = 0;
    
    for (int i = 2; i <= X; i++) {
        dp[i] = dp[i - 1] + 1;
        
        int val2, val3;
        val2 = val3 = dp[i];
        
        if (i % 2 == 0) {
            int value = dp[i / 2] + 1;
            val2 = value < dp[i] ? value : dp[i];

        }
        
        if (i % 3 == 0) {
            int value = dp[i / 3] + 1;
            val3 = value < dp[i] ? value : dp[i];
        }
        
        dp[i] = val2 < val3 ? val2 : val3;
    }
    
    printf("%d", dp[X]);
    
    return 0;
}
