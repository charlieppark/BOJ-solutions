#include <stdio.h>

int main() {
    int max = -1;
    int row, col;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int a;
            scanf("%d", &a);
            if (a > max) {
                max = a;
                row = i;
                col = j;
            }
        }
    }
    printf("%d\n%d %d", max, row, col);
}