n = int(input())

input_bars = [100000001]

for i in input().split():
    input_bars.append(int(i))

cursor_stack = list()

result = list()

for i in range(1, n + 1):
    if input_bars[i] < input_bars[i - 1]:
        cursor_stack.append(i - 1)
    else:
        j = 2
        while i - j > 0 and input_bars[i - j] < input_bars[i]:    
            cursor_stack.pop()
            j += 1

    result.append(str(cursor_stack[-1]))

print(" ".join(result))