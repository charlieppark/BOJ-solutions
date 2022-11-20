#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int count;
} Type;

int string_compare(const void *type1, const void *type2)
{
    char *const *pointer1 = ((Type*)type1)->name;
    char *const *pointer2 = ((Type*)type2)->name;
    return strcmp(*pointer1, *pointer2);
}

int binary_search(char* c, Type** arr, int from, int to, int len) {
    if (from > to || from >= len || to < 0) {
        return -1;
    }
    
    int idx = (from + to) / 2;
    
    if (strcmp(arr[idx]->name, c) < 0) {
        return binary_search(c, arr, idx + 1, to, len);
    } else if (strcmp(arr[idx]->name, c) > 0) {
        return binary_search(c, arr, from, idx - 1, len);
    } else {
        return idx;
    }
}

int main()
{
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int n;
        
        scanf("%d", &n);
        
        int idx = -1;
        
        Type** arr = malloc(sizeof(*arr) * n);
        
        for (int j = 0; j < n; j++) {
            char temp[21];
            char name[21];
            
            scanf("%s %s", temp, name);
            
            int search_idx = binary_search(name, arr, 0, idx, idx + 1);
            
            if (search_idx != -1) {
                arr[search_idx]->count++;
            } else {
                idx++;
                arr[idx] = malloc(sizeof(**arr));
                arr[idx]->name = malloc(sizeof(*(arr[idx]->name)) * 21);
                strcpy(arr[idx]->name, name);
                arr[idx]->count = 1;
                qsort(arr, idx + 1, sizeof(*arr), string_compare);
            }
        }
        
        long long count = 1;
        
        for (int j = 0; j <= idx; j++) {
            count *= arr[j]->count + 1;
        }
        
        count--;
        
        printf("%lld\n", count);
    }

    return 0;
}
