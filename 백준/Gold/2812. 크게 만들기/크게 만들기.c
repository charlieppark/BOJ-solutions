#include <stdio.h>
#include <stdlib.h>

int stack[500002];

int top = -1;

int pop() {
    int ret = stack[top];
    top--;
    return ret;
}

void push(int element) {
    top++;
    stack[top] = element;
}

int main()
{
    int N, K;
    
    scanf("%d %d ", &N, &K);
    
    char first;
    
    scanf("%c", &first);
        
    first -= '0';
    
    top++;
    stack[top] = first;
    
    for (int i = 1; i < N; i++) {
        char temp;
        
        scanf("%c", &temp);
        
        temp -= '0';
        
        if (stack[top] < temp && K > 0) {
            while (top > -1 && stack[top] < temp && K > 0) {
                top--;
                K--;   
            }
            top++;
            stack[top] = temp;
        } else {
            top++;
            stack[top] = temp;
        }
    }
    
    while (K > 0) {
        top--;
        K--;
    }
    
    
    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);
    }
}