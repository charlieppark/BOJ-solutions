#include <stdio.h>

int visited[9] = { 0, };

int result[9] = { 0, };
int end = 0;

int N, M;

void dfs(int m, int last) {
    if (!m) {
        for (int i = 0; i < end; i++) printf("%d ", result[i]);
        printf("\n");
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            result[end++] = i;
            dfs(m - 1, i);
            end--;
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    dfs(M, 0);
}