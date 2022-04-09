from stack import Stack

bars = list()

n = int(input())

for i in range(n):
    bars.append(int(input()))

stack = Stack()
stack.push(bars[-1])

for bar in bars[-2::-1]:
    if bar > stack.top():
        stack.push(bar)

print(stack.size())
