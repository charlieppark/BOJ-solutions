#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int* count){
    (*count)++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, count);
}

int isPalindrome(const char *s, int* count){
    return recursion(s, 0, strlen(s)-1, count);
}

int main(){
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        char s[1005];
        int count = 0;
        scanf("%s", s);
        int a = isPalindrome(s, &count);
        printf("%d %d\n", a, count);
    }
}