bars = list()

n = int(input())

for i in range(n):
    new_bar = int(input())
    
    while True:
        if len(bars) is 0 or bars[-1] > new_bar:
            break

        bars.pop()
        
    bars.append(new_bar)

print(len(bars))
