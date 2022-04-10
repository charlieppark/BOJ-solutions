from stack import Stack

n = int(input())

input_bars = [100000001]

for i in input().split():
    input_bars.append(int(i))

cursor_stack = Stack()

result = list()

for i in range(1, n + 1):
    if input_bars[i] < input_bars[i - 1]:
        cursor_stack.push(i - 1)
    else:
        while cursor_stack.top() != -1 and input_bars[cursor_stack.top()] < input_bars[i]:
            cursor_stack.pop()

    result.append(str(cursor_stack.top()))

print(" ".join(result))