#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dequeue[2000000];

int front = 1000000;
int back = 1000000;
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

int pop(int way) {
    if (way) {
        return pop_front();
    }
    else {
        return pop_back();
    }
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        char p[100003];
        
        scanf("%s", p);
        
        int n;
        
        scanf("%d", &n);
        
        front = back = 1000000;
        size = 0;
        
        char* input = malloc(sizeof(*input) * (n * 3 + 4));
        
        scanf("%s", input);
        
        if (n != 0) {
            input[0] = ' ';
            input[strlen(input) - 1] = '\0';
            
            char *ptr = strtok(input, ",");
            
            while (ptr != NULL) {
                push_back(atoi(ptr));
                ptr = strtok(NULL, ",");
            }
        }
        
        int way = 1; // 1 for pop_front --- 0 for pop_back
        
        int len = strlen(p);
        
        for (int j = 0; j < len; j++) {
            char c = p[j];
            
            if (c == 'R') {
                way ^= 1;
            } else {
                if (empty()) {
                    way = -1;
                    break;
                }
                
                pop(way);
            }
        }
        
        if (way == -1) {
            printf("error\n");
            continue;
        }
        
        printf("[");
        while (size > 0) {
            printf("%d", pop(way));
            
            if (!empty()) {
                printf(",");
            }
        }
        printf("]\n");
    }
}
