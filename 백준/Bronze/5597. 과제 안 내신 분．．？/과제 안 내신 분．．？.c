#include <stdio.h>

int main() {
    int a[30] = { 0, };
    for (int i = 0; i < 28; i++) {
        int idx;
        scanf("%d", &idx);
        a[idx - 1] = 1;
    }
    
    for (int i = 0; i < 30; i++) {
        if (a[i] == 0) {
            printf("%d\n", i + 1);
        }
    }
}