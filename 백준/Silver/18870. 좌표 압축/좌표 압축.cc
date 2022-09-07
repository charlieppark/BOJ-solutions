#include <cstdio>
#include <cstdlib>
#include <map>

void heapsort(int* A);

void build_max_heap(int* A);

void max_heapify(int* A, int i);

void swap(int *A, int i, int j) {
    int temp = A[i];
    
    *(A + i) = A[j];
    
    *(A + j) = temp;
}

int length;

int heapsize;

int main() {
    
    int N;
    
    scanf("%d", &N);
    
    length = N;
    
    int* array = (int*)malloc(sizeof(*array) * (N + 1));
    int* original = (int*)malloc(sizeof(*original) * (N + 1));
    
    for(int i = 1; i <= N; i++) {
        int temp;
        scanf("%d", &temp);
        
        array[i] = original[i] = temp;
    }
    
    heapsort(array);
    
    int count = 0;
    
    std::map<int, int> result;
    
    result[1] = count;
    
    for(int i = 2; i <= N; i++) {
        if (array[i] != array[i - 1]) {
            count++;
            result[array[i]] = count;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        printf("%d ", result[original[i]]);
    }
    
    return 0;
}

void heapsort(int* A) {
    build_max_heap(A);
    for (int i = length; i > 1; i--) {
        swap(A, 1, i);
        heapsize--;
        max_heapify(A, 1);
    }
}

void build_max_heap(int* A) {
    heapsize = length;
    for (int i = length / 2; i >= 1; i--) {
        max_heapify(A, i);
    }
}

void max_heapify(int* A, int i) {
    int L = 2 * i;
    int R = 2 * i + 1;
    int largest;
    if ((L <= heapsize) && (A[L] > A[i])) {
        largest = L;
    } else {
        largest = i;
    }
    if ((R <= heapsize) && (A[R] > A[largest])) {
        largest = R;
    }
    if (largest != i) {
        swap(A, i, largest);
        max_heapify(A, largest);
    }
}