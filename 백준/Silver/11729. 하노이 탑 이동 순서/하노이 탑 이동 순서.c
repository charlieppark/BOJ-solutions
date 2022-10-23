#include <stdio.h>
#include <stdlib.h>

void move(int N, int from, int via, int to) {
    if (N == 1) {
        printf("%d %d\n", from, to);
    } else {
        move(N - 1, from, to, via);
        move(1, from, via, to);
        move(N - 1, via, from, to);
    }
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    int* move_count = malloc(sizeof(*move_count) * (N + 1));
    
    move_count[1] = 1;
    for (int i = 2; i <= N; i++) {
        move_count[i] = move_count[i - 1] * 2 + 1;
    }
    
    printf("%d\n", move_count[N]);
    
    move(N, 1, 2, 3);

    return 0;
}
