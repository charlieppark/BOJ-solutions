#include <stdio.h>
#include <string.h>

int dequeue[200000];

int front = 100000;
int back = 100000;
int size = 0;

int main()
{
    int N;
    scanf("%d", &N);
    
    char command[13];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", command);
        
        if (!strcmp(command, "push_front")) {
            int temp;
            scanf("%d\n", &temp);
            
            if(!size) {
                back--;
            }
            
            front--;
            dequeue[front] = temp;
            size++;
        } else if (!strcmp(command, "push_back")) {
            int temp;
            scanf("%d\n", &temp);
            
            if(!size) {
                front++;
            }
            
            back++;
            dequeue[back] = temp;
            size++;
        } else if (!strcmp(command, "front")) {
            if (!size) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", dequeue[front]);
            }
        } else if (!strcmp(command, "back")) {
            if (!size) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", dequeue[back]);
            }
        } else if (!strcmp(command, "size")) {
            printf("%d\n", size);
        } else if (!strcmp(command, "pop_front")) {
            if (!size) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", dequeue[front++]);
                size--;
                if (!size) {
                    back = front;
                }
            }
        } else if (!strcmp(command, "pop_back")) {
            if (!size) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", dequeue[back--]);
                size--;
                if (!size) {
                    front = back;
                }
            }
        } else if (!strcmp(command, "empty")) {
            if (!size) {
                printf("%d\n", 1);
            } else {
                printf("%d\n", 0);
            }
        } 
    }
}
