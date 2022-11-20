from collections import deque

def swap(arr, from_idx, to_idx, N):
    f, t = sorted((from_idx, to_idx))
    arr = arr[:f] + list(reversed(arr[f: t + 1])) + arr[t+1:]
    return arr

def main():
    N = int(input())
    
    darr = deque(map(int, input().split(' ')))
    
    darr.insert(0, -1)
    darr.insert(N + 1, -1)
    arr = list(darr)
    
    idx = 1
    
    sorted_arr = [i for i in range(1, N+1)]
    
    if arr[1:N+1] == sorted_arr:
        print(f'1 1\n1 1')
        return
    elif arr[1:N+1] == reversed(sorted_arr):
        print(f'1 {N}\n1 1')
        return
    
    for a in range(1, N+1):
        if arr[a] != a:
            b = arr.index(a)
            arr = swap(arr, a, b, N)
            
            if arr[1:N+1] == sorted_arr:
                a, b = sorted((a, b))
                print(f'{a} {b}\n1 1')
                return
            elif arr[1:N+1] == reversed(sorted_arr):
                a, b = sorted((a, b))
                print(f'{a} {b}\n1 {N}')
                return
            
            for c in range(a+1, N+1):
                if arr[c] != c:
                    d = arr.index(c)
                    arr = swap(arr, c, d, N)
                    if arr[1:N+1] == sorted_arr:
                        a, b = sorted((a, b))
                        c, d = sorted((c, d))
                        print(f'{a} {b}\n{c} {d}')
                        return
                    
                    arr = swap(arr, c, d, N)
                    break
            arr = swap(arr, a, b, N)
            
    for a in reversed(range(1, N+1)):
        if arr[a] != a:
            b = arr.index(a)
            arr = swap(arr, a, b, N)
            
            if arr[1:N+1] == sorted_arr:
                a, b = sorted((a, b))
                print(f'{a} {b}\n1 1')
                return
            elif arr[1:N+1] == reversed(sorted_arr):
                a, b = sorted((a, b))
                print(f'{a} {b}\n1 {N}')
                return
            
            for c in reversed(range(1, a)):
                if arr[c] != c:
                    d = arr.index(c)
                    arr = swap(arr, c, d, N)
                    if arr[1:N+1] == sorted_arr:
                        a, b = sorted((a, b))
                        c, d = sorted((c, d))
                        print(f'{a} {b}\n{c} {d}')
                        return
                    
                    arr = swap(arr, c, d, N)
                    break
            arr = swap(arr, a, b, N)
            
if __name__ == "__main__":
    main()