#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            printf("%c", s[i] + ('A' - 'a'));
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            printf("%c", s[i] + ('a' - 'A'));
        }

    }
}