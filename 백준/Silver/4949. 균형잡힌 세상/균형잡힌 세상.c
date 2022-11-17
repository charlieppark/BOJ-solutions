#include <stdio.h>
#include <string.h>

int stack[102];
int top;

int check() {
    int idx = 0;
    
    char c;
    
    top = -1;
    
    while (1) {
        c = getchar();
        
        if (c == '.') break;
        
        idx++;
        
        if (c == '[' || c == '(') {
            top++;
            stack[top] = c;
        } else if (c == ']') {
            if (top == -1) {
                printf("no\n");
                return 1;
            }
            if (stack[top] == '[') {
                top--;
            } else {
                printf("no\n");
                return 1;
            }
        } else if (c == ')') {
            if (top == -1) {
                printf("no\n");
                return 1;
            }
            if (stack[top] == '(') {
                top--;
            } else {
                printf("no\n");
                return 1;
            }
        }
    }
    
    if (idx == 0) {
        return 0;
    } else {
        if (top == -1)
            printf("yes\n");
        else
            printf("no\n");
        return 1;
    }
}

int main()
{
    while (check()) {
        while(getchar() != '\n') continue;
    }
}