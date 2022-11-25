#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1234567891

unsigned long hash_func (char* str, int len)
{
    unsigned long hash = 0;
    int c;
    for (int i = len - 1; i >= 0; i--)
    {
        c = str[i] - 'a' + 1;
        hash = (((hash << 5) - hash) + c) % TABLE_SIZE;
        continue;
    }
    return hash % TABLE_SIZE;
}

int main()
{
    int L;
    
    scanf("%d", &L);
    
    char* s = malloc(sizeof(*s) * (L + 1));
    
    scanf("%s", s);
    
    printf("%ld", hash_func(s, L));

    return 0;
}
