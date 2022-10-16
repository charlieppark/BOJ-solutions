#include <stdio.h>

int simple_queue[2000000];

int front = 0;
int back = 0;

int main()
{
    int N;
    scanf("%d", &N);
    
    back = N - 1;
    
    for (int i = 0; i < N; i++) {
        simple_queue[i] = i + 1;
    }
        
    while (front != back) {
        if (front % 2 == 1) {
            back++;
            simple_queue[back] = simple_queue[front];
        }
        front++;
    }
    
    printf("%d", simple_queue[front]);
}
