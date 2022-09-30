#include <stdio.h>


int main() {
    int N, M;

    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) return 0;
        if (M % N == 0) printf("factor\n");
        else if (N % M == 0) printf("multiple\n");
        else printf("neither\n");
    }    
    
    return 0;
}