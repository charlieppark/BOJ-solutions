#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_compare(const void *str1, const void *str2 )
{
    char *const *pointer1 = str1;
    char *const *pointer2 = str2;
    return strcmp(*pointer1, *pointer2);
}

int binary_search(char* c, char** arr, int from, int to, int len) {
    if (from > to || from >= len || to < 0) {
        return 0;
    }
    
    int idx = (from + to) / 2;
    
    if (strcmp(arr[idx], c) < 0) {
        return binary_search(c, arr, idx + 1, to, len);
    } else if (strcmp(arr[idx], c) > 0) {
        return binary_search(c, arr, from, idx - 1, len);
    } else {
        return 1;
    }
}

int main() {
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    char** arr = malloc(sizeof(*arr) * N);
    
    for (int i = 0; i < N; i++) {
        arr[i] = malloc(sizeof(**arr) * 21);
        
        scanf("%s", arr[i]);
    }
    
    qsort(arr, N, sizeof(*arr), string_compare);
    
    char** result = malloc(sizeof(*result) * M);
    
    int idx = 0;
    
    for (int i = 0; i < M; i++) {
        char* s = malloc(sizeof(*s) * 21);
        
        scanf("%s", s);
        
        if (binary_search(s, arr, 0, N - 1, N)) {
            result[idx++] = s;
        }
    }
    
    qsort(result, idx, sizeof(*result), string_compare);
    
    printf("%d\n", idx);
    
    for (int i = 0; i < idx; i++) {
        printf("%s\n", result[i]);
    }
}