import sys

n = int(sys.stdin.readline())

a = list()

sum = 0

count = dict()

for i in range(n):
    temp = int(sys.stdin.readline())
    
    a.append(temp)
    sum += temp
    
    if temp in count.keys():
        count[temp] += 1
    else:
        count[temp] = 1

print(round(sum/n))

a.sort()

print(a[n//2])

if len(count.keys()) == 1:
    print(a[0])

else:
    max_num = 0

    for v in count.values():
        if max_num < v:
            max_num = v

    max_list = list()
            
    for k,v in count.items():
        if v == max_num:
            max_list.append(k)

    max_list.sort()

    if (len(max_list) > 1):
        print(max_list[1])
    else:
        print(max_list[0])
    
print(a[n-1] - a[0])