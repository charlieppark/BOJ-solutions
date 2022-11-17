#include <stdio.h>
#include <stdlib.h>

int queue[10000000];

int N;

int front = -1;
int back = -1;

void push(int element) {
    if (front == -1) {
        front = 0;
    }
    
    back++;
    queue[back] = element;
}

int front_queue() {
    if (front == -1 || back < front) {
        return -1;
    } else {
        return queue[front];
    }
}

int back_queue() {
    if (back == -1 || back < front) {
        return -1;
    } else {
        return queue[back];
    }
}

int size() {
    if (back == -1 || back < front) {
        return 0;
    } else {
        return back - front + 1;
    }
}

int pop() {
    if (back == -1 || back < front) {
        return -1;
    } else {
        return queue[front++];
    }
}

int empty() {
    if (back == -1 || back < front) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    scanf("%d", &N);
    
    int packet;
    
    scanf("%d", &packet);
    
    while (packet != -1) {
        if (packet == 0) {
            pop();
        } else if (size() < N) {
            push(packet);
        }
        
        scanf("%d", &packet);
    }
    
    if (size() > 0) {
        for (int i = front; i <= back; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        printf("empty");
    }
    
}
