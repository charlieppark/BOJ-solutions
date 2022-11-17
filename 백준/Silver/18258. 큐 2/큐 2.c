#include <stdio.h>
#include <string.h>

int queue[2000001];

int front = -1;
int back = -1;

int main()
{
    int N;
    scanf("%d", &N);
    
    char command[10];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", command);
        
        if (!strcmp(command, "push")) {
            int temp;
            scanf("%d\n", &temp);
            
            if (front == -1) {
                front = 0;
            }
            
            back++;
            queue[back] = temp;
        } else if (!strcmp(command, "front")) {
            if (front == -1 || back < front) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", queue[front]);
            }
        } else if (!strcmp(command, "back")) {
            if (back == -1 || back < front) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", queue[back]);
            }
        } else if (!strcmp(command, "size")) {
            if (back == -1 || back < front) {
                printf("%d\n", 0);
            } else {
                printf("%d\n", back - front + 1);
            }
        } else if (!strcmp(command, "pop")) {
            if (back == -1 || back < front) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", queue[front++]);
            }
        } else if (!strcmp(command, "empty")) {
            if (back == -1 || back < front) {
                printf("%d\n", 1);
            } else {
                printf("%d\n", 0);
            }
        } 
    }
}
