#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    while(getchar() != '\n') {
        n++;
    }
    printf("%d", n);
}