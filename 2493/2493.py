# from stack import Stack

# def flush(self):
#     self.elements.clear()
#     self.top = -1
#     return

# Stack.flush = flush

n = int(input())

input_bars = list(map(int, input().split()))

result = list()

for i in range(n - 1, -1, -1):
    bars = input_bars[:i + 1]
    
    # index_stack = Stack()
    # index_stack.push(i)

    index_stack = list()
    index_stack.append(i)

    for j in range(i - 1, -1, -1):
        # if bars[j] < bars[index_stack.top()]:
            # index_stack.push(j)

        if bars[j] < bars[index_stack[-1]]:
            index_stack.append(j)

    result.append(str(index_stack.top()))

    index_stack.flush()

out = " ".join(reversed(result))

print(out)