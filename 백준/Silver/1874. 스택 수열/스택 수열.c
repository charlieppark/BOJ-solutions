#include <stdio.h>
#include <stdlib.h>

int stack[100002];

int top = 0;

int main()
{
    int n;
    
    scanf("%d", &n);
    
    char* result = malloc(sizeof(*result) * (n * 3));
    
    int* arr = malloc(sizeof(*arr) * (n + 1));
    
    int idx = 0;
    
    int n_used = 1;
    
    stack[top] = 1;
    
    result[idx++] = '+';
    
    for (int i = 0; i < n; i++) {
    
        int temp;
        
        scanf("%d", arr + i);
    }
    
    for (int i = 0; i < n; i++) {  
        if (arr[i] > stack[top]) {
            for (int j = n_used + 1; j <= arr[i]; j++) {
                top++;
                stack[top] = j;
                result[idx++] = '+';
            }
            
            n_used = arr[i];
            
            top--;
            result[idx++] = '-';
        } else if (arr[i] == stack[top]) {
            top--;
            result[idx++] = '-';
        } else {
            printf("NO\n");
            return 0;
        }
    }
    
    for (int i = 0; i < idx; i++) {
        printf("%c\n", result[i]);
    }
}