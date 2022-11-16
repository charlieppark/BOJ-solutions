#include <stdio.h>

long long result[21][21][21] = { 0, };

long long w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0){
        return 1;
    }

    if (a > 20 || b > 20 || c > 20) {
        if (!result[20][20][20]) result[20][20][20] = w(20, 20, 20);
        return result[20][20][20];
    }

    if (a < b && b < c) {
        if (!result[a][b][c-1]) result[a][b][c-1] = w(a, b, c-1);
        if (!result[a][b-1][c-1]) result[a][b-1][c-1] = w(a, b-1, c-1);
        if(!result[a][b-1][c]) result[a][b-1][c] = w(a, b-1, c);
        return result[a][b][c-1] + result[a][b-1][c-1] - result[a][b-1][c];
    } else {
        if (!result[a-1][b][c]) result[a-1][b][c] = w(a-1, b, c);
        if (!result[a-1][b-1][c]) result[a-1][b-1][c] = w(a-1, b-1, c);
        if (!result[a-1][b][c-1]) result[a-1][b][c-1] = w(a-1, b, c-1);
        if (!result[a-1][b-1][c-1]) result[a-1][b-1][c-1] = w(a-1, b-1, c-1);
        return result[a-1][b][c] + result[a-1][b-1][c] + result[a-1][b][c-1] - result[a-1][b-1][c-1];
    }
}

int main() {
    
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    while (!(a == -1 && b == -1 && c == -1)) {
        printf("w(%d, %d, %d) = %lld\n", a, b, c, w(a, b, c));
        scanf("%d %d %d", &a, &b, &c);
    }
}