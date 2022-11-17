#include <stdio.h>

int stack[100002];

int top = -1;

int main()
{
    int K;
    
    scanf("%d", &K);
    
    for (int i = 0; i < K; i++) {
        int temp;
        
        scanf("%d", &temp);
        
        if (temp == 0) {
            top--;
        } else {
            top++;
            stack[top] = temp;
        }
    }
    
    int sum = 0;
    
    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }
    
    printf("%d", sum);
    
    return 0;
}