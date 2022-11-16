#include <stdio.h>
#include <math.h>

int prime_check[10000] = { 0 };

int prime[10000] = { 0, };

int visited[10000] = { 0, };

int queue[1000000];
int front = -1;
int back = -1;

int bfs(int b) {
    int count = 0;
    
    int this_dim = 1;
    int next_dim;
    
    while (front <= back) {
        if (this_dim == front) {
            count++;
            this_dim = next_dim;
        }
        
        int v = queue[front++];
        
        visited[v] = 1;
        
        int sum_a = 0;
        int sum_b = 0;
        
        for (int j = 1000; j < 10000; j++) {
            sum_a += visited[j];
            sum_b += prime[j];
        }
        
        if (sum_a == sum_b) return -1;
        
        int v_part[4] = { v % 10, (v % 100) / 10, (v % 1000) / 100, v / 1000};
    
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                if (v_part[i] != j) {
                    int num = j * (int)pow(10, i);
                    for (int k = 0; k < 4; k++) {
                        if (i != k) num += v_part[k] * (int)pow(10, k);
                    }
                    
                    if (num == b) return count;
                    
                    if (visited[num]) continue;
                    
                    if (prime[num]) {
                        back++;
                        queue[back] = num;
                        next_dim = back;
                    }
                }
            }
        }
    }
}

int main() {
    for (int i = 2; i <= 100; i++) {
        int t = 1;
        while (i * t < 10000) {
            prime_check[i * t++] = 1;
        }
    }
    
    for (int i = 1000; i < 10000; i++) {
        if (!prime_check[i]) {
            prime[i] = 1;
        }
    }
    
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        if (a == b) {
            printf("0\n");
            continue;
        }
            
        
        for (int j = 1000; j < 10000; j++) {
            visited[j] = 0;
        }
        
        front = 0;
        back = 0;
        
        queue[back] = a;
        
        int count = bfs(b);
        
        if (count == -1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", count + 1);
        }
    }
}