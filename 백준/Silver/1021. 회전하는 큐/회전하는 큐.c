#include <stdio.h>
#include <stdlib.h>

int dequeue[20000];

int front = 10000;
int back = 10000;
int size = 0;

void push_front(int element) {
    if(!size) {
        back--;
    }
    
    front--;
    dequeue[front] = element;
    size++;
}

void push_back(int element) {
    if(!size) {
        front++;
    }
    
    back++;
    dequeue[back] = element;
    size++;
}

int front_queue() {
    if (!size) {
        return -1;
    } else {
        return dequeue[front];
    }
}

int back_queue() {
    if (!size) {
        return -1;
    } else {
        return dequeue[front];
    }
}

int pop_front() {
    if (!size) {
        return -1;
    } else {
        int ret = dequeue[front++];
        size--;
        if (!size) {
            back = front;
        }
        return ret;
    }
}

int pop_back() {
    if (!size) {
        return -1;
    } else {
        int ret = dequeue[back--];
        size--;
        if (!size) {
            front = back;
        }
        return ret;
    }
}

int empty() {
    if (!size) {
        return 1;
    } else {
        return 0;
    }
}

void left() {
    push_back(pop_front());
}

void right() {
    push_front(pop_back());
}

int main()
{
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++) {
        push_back(i);
    }
    
    int* input = malloc(sizeof(*input) * M);
    
    for (int i = 0; i < M; i++) {
        scanf("%d", input + i);
    }
    
    int right_count, left_count;
    
    right_count = left_count = 0;
    
    for (int i = 0; i < M; i++) {
        if (front_queue() == input[i]) {
            pop_front();
        } else {
            int idx;
            
            for (int j = front; j <= back; j++) {
                if (dequeue[j] == input[i]) {
                    idx = j;
                    break;
                }
            }
            
            if (idx - front <= back - idx) {
                while (front != idx) {
                    left();
                    left_count++;
                }
                pop_front();
            } else {
                while (back != idx) {
                    right();
                    right_count++;
                }
                right();
                right_count++;
                pop_front();
            }
        }
    }
    
    printf("%d", right_count + left_count);
}
