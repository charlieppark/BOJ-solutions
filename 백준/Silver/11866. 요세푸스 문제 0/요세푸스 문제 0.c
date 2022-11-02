#include <stdio.h>
#include <stdlib.h>

int simple_queue[2000000];

int front = 1;
int back = 1;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int* result = malloc(sizeof(*result) * N);
    
    back = N;

    for (int i = 1; i <= N; i++) {
        simple_queue[i] = i;
    }
    
    int idx = 0;

    while (front != back) {
        if (front % K != 0) {
            back++;
            simple_queue[back] = simple_queue[front];
        } else {
            result[idx++] = simple_queue[front];
        }
        front++;
    }
    
    result[idx] = simple_queue[back];

    printf("<");
    for (int i = 0; i < N - 1; i++) {
        printf("%d, ", result[i]);
    }
    printf("%d>", result[N-1]);
}