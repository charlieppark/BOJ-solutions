#include <stdio.h>

long long count_base(int base, int num) {
    long long key = base;
    
    long long count = 0;
    
    while (key <= (long long)num) {
        count += num / key;
        key *= base;
    }
    
    return count;
}

int main() {
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    long long five = count_base(5, n) - count_base(5, m) - count_base(5, n - m);
    five = five > 0 ? five : -five;
    
    long long two = count_base(2, n) - count_base(2, m) - count_base(2, n - m);
    two = two > 0 ? two : -two;
    
    long long res = five > two ? two : five;
    
    printf("%lld", res);
}