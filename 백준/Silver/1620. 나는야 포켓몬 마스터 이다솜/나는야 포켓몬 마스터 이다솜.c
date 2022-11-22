#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _type{
    char* name;
    int key;
} Type;

int string_compare(const void *type1, const void *type2)
{
    char *const *pointer1 = &((*((Type**)type1))->name);
    char *const *pointer2 = &((*((Type**)type2))->name);
    return strcmp(*pointer1, *pointer2);
}

int num_compare (const void* first, const void* second)
{
    return (*((Type**)first))->key - (*((Type**)second))->key;
}


int binary_search_num(int c, Type** arr, int from, int to, int len) {
    if (from > to || from >= len || to < 0) {
        return -1;
    }

    int idx = (from + to) / 2;

    if (arr[idx]->key < c) {
        return binary_search_num(c, arr, idx + 1, to, len);
    } else if (arr[idx]->key > c) {
        return binary_search_num(c, arr, from, idx - 1, len);
    } else {
        return idx;
    }
}

int binary_search_str(char* c, Type** arr, int from, int to, int len) {
    if (from > to || from >= len || to < 0) {
        return -1;
    }

    int idx = (from + to) / 2;

    if (strcmp(arr[idx]->name, c) < 0) {
        return binary_search_str(c, arr, idx + 1, to, len);
    } else if (strcmp(arr[idx]->name, c) > 0) {
        return binary_search_str(c, arr, from, idx - 1, len);
    } else {
        return idx;
    }
}

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);
    
    Type** arr_str = malloc(sizeof(*arr_str) * N);
    Type** arr_num = malloc(sizeof(*arr_num) * N);

    for (int i = 0; i < N; i++) {
        arr_str[i] = malloc(sizeof(*(arr_str[i])));
        arr_num[i] = malloc(sizeof(*(arr_num[i])));
        
        arr_str[i]->name = malloc(sizeof(*(arr_str[i]->name)) * 22);
        arr_num[i]->name = malloc(sizeof(*(arr_num[i]->name)) * 22);
        
        scanf("%s", arr_str[i]->name);
        strcpy(arr_num[i]->name, arr_str[i]->name);
        
        arr_str[i]->key = i + 1;
        arr_num[i]->key = i + 1;
        //printf("s %d %d\n", arr_num[i], arr_num[i]->key);
    }
    
    qsort(arr_str, N, sizeof(Type*), string_compare);
    qsort(arr_num, N, sizeof(Type*), num_compare);

    for (int i = 0; i < M; i++) {
        char input[22];
        scanf("%s ", input);
        if (*input >= '0' && *input <= '9') {
            int idx = binary_search_num(atoi(input), arr_num, 0, N-1, N);
            //printf("%s, %d, %d", input, atoi(input), idx);
            char* s = arr_num[idx]->name;
            printf("%s\n", s);
        } else {
            int idx = binary_search_str(input, arr_str, 0, N-1, N);
            //printf("%s, %d", input, idx);
            int key = arr_str[idx]->key;
            printf("%d\n", key);
        }
    }

    return 0;
}