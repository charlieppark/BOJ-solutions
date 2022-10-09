#include <stdio.h>

int main() {
    char s[4];
    scanf("%s", s);
    float score;
    switch(s[0]) {
        case 'A':
            score = 4;
            break;
        case 'B':
            score = 3;
            break;
        case 'C':
            score = 2;
            break;
        case 'D':
            score = 1;
            break;
        case 'F':
            score = 0;
            printf("%.1f", score);
            return 0;
        default:
            break;
    }

    switch(s[1]) {
        case '+':
            score += 0.3;
            break;
        case '0':
            break;
        case '-':
            score -= 0.3;
            break;
        default:
            break;
    }
    
    printf("%.1f", score);
}