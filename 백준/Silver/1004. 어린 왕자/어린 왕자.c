#include <stdio.h>

int distance_sqaured(int x, int a, int y, int b) {// (x-a)^2 + (y-b)^2 = r^2
    return (x-a) * (x-a) + (y-b) * (y-b);
}

int main() {
    int T;
    
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int from[2];
        int to[2];
        
        scanf("%d %d %d %d", from, from + 1, to, to + 1);
        
        int n;
        
        scanf("%d", &n);
        
        int count = 0;
        
        for (int j = 0; j < n; j++) {
            int cx, cy, r;
            scanf("%d %d %d", &cx, &cy, &r);
            
            int from_dist = distance_sqaured(from[0], cx, from[1], cy);
            int to_dist = distance_sqaured(to[0], cx, to[1], cy);
            
            if (from_dist < r * r) {
                count++;
            }
            if (to_dist < r * r) {
                count++;
            }
            if (from_dist < r * r && to_dist < r * r) {
                count -= 2;
            }
        }
        
        printf("%d\n", count);
    }
}