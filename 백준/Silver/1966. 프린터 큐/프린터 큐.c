#include <stdio.h>
#include <stdlib.h>

int queue[1000];

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
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        back = front = -1;
        
        int N, M;
        
        scanf("%d %d", &N, &M);
        
        for (int j = 0; j < N; j++) {
            int temp;
            
            scanf("%d", &temp);
            
            push(temp);
        }
        
        int* result = malloc(sizeof(*result) * N);
        
        for (int j = 0; j < N; j++) {
            result[j] = -1;
        }
        
        int idx = 0;
        int count = 1;
        
        while (1) {
            
            int front_element = pop();
            
            for (int j = front; j <= back; j++) {
                if (queue[j] > front_element) {
                    push(front_element);
                    front_element = -1;
                    break;
                }
            }
            
            if (front_element != -1) {
                result[idx] = count;
                count++;
            }
            
            if (result[M] != -1) break;
            
            idx++;
            idx = idx % N;
            
            while (result[idx] != -1) {
                idx++;
                idx = idx % N;
            }
        }
        
        printf("%d\n", result[M]);
        
        free(result);
    }
}
