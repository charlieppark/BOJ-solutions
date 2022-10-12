#include <stdio.h>
#include <string.h>

int main()
{
    int stopper;
    char str[501];
    while (gets(str)) {
        if (!strcmp(str, "END")) break;
        int len = strlen(str);
        for (int i = 0; i < len/2; i++) {
            char temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
        printf("%s\n", str);
    }
}