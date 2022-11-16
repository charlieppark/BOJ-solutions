#include <stdio.h>

int visited[9] = { 0, };

int N, M;

void dfs(int m, int last) {
    if (!m) {
        for (int i = 1; i <= N; i++) {
            if (visited[i]) printf("%d ", i);
        }
        printf("\n");
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (i > last) {
            visited[i] = 1;
            dfs(m - 1, i);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    dfs(M, 0);
}