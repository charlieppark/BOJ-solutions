from stack import Stack

n = int(input())

switch = {"empty" : Stack.empty, "pop" : Stack.pop, "size" : Stack.size, "top" : Stack.top}

stack = Stack()

for i in range(n):
    inputs = input().split()
    operator = inputs[0]
    
    if len(inputs) > 1:
        operand = inputs[1]
        stack.push(operand)
    else:
        print(switch[operator](stack))