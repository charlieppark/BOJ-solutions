#include <stdio.h>
#include <stdlib.h>

// 0 not exists
// 1 positive exists
// 2 negative exists
// 3 both exists

int main() {
    int checker[10000001] = {0,};
    
    int N, M;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        if (num > 0) {
            switch (checker[num]) {
                case 0:
                case 1:
                    checker[num] = 1;
                    break;
                case 2:
                case 3:
                    checker[num] = 3;
                    break;
                default:
                    break;
            }
        } else if (num < 0) {
            num *= -1;
            switch (checker[num]) {
                case 0:
                case 2:
                    checker[num] = 2;
                    break;
                case 1:
                case 3:
                    checker[num] = 3;
                    break;
                default:
                    break;
            }
        } else {
            checker[num] = 1;
        }
    }
    
    scanf("%d", &M);
    
    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        if (num >= 0) {
            switch (checker[num]) {
                case 1:
                case 3:
                    printf("1 ");
                    break;
                default:
                    printf("0 ");
                    break;
            }
        } else {
            num *= -1;
            switch (checker[num]) {
                case 2:
                case 3:
                    printf("1 ");
                    break;
                default:
                    printf("0 ");
                    break;
            }
        }
    }
    
    return 0;
}