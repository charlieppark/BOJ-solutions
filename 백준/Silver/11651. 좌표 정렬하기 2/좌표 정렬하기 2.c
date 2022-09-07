#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

void heapsort(Point* A);

void build_max_heap(Point* A);

void max_heapify(Point* A, int i);

void swap(Point *A, int i, int j) {
    Point temp = A[i];
    
    A[i] = A[j];
    
    A[j] = temp;
}

int length;

int heapsize;

int main() {
    
    int N;
    
    scanf("%d", &N);
    
    length = N;
    
    Point* point = malloc(sizeof(*point) * (N + 1));
    
    for(int i = 1; i <= N; i++) {
        scanf("%d %d", &(point[i].x), &(point[i].y));
    }
    
    heapsort(point);
    
    for(int i = 1; i <= N; i++) {
        printf("%d %d\n", point[i].x, point[i].y);
    }
    
    return 0;
}

void heapsort(Point* A) {
    build_max_heap(A);
    for (int i = length; i > 1; i--) {
        swap(A, 1, i);
        heapsize--;
        max_heapify(A, 1);
    }
}

void build_max_heap(Point* A) {
    heapsize = length;
    for (int i = length / 2; i >= 1; i--) {
        max_heapify(A, i);
    }
}

void max_heapify(Point* A, int i) {
    int L = 2 * i;
    int R = 2 * i + 1;
    int largest;
    if ((L <= heapsize) && ((A[L].y > A[i].y) || ((A[L].y == A[i].y) && (A[L].x > A[i].x)))) {
        largest = L;
    } else {
        largest = i;
    }
    if ((R <= heapsize) && ((A[R].y > A[largest].y) || ((A[R].y == A[largest].y) && (A[R].x > A[largest].x)))) {
        largest = R;
    }
    if (largest != i) {
        swap(A, i, largest);
        max_heapify(A, largest);
    }
}