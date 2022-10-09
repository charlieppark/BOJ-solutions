#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        char s[1001];
        scanf("%s", s);
        printf("%c%c\n", s[0], s[strlen(s) - 1]); 
    }
}