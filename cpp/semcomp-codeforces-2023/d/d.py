
n = int(input())
max = 0
min = 0

for i in range(n):
    v= int(input())
    if v > max:
        max = v
        min = v

    elif v< min:
        min=v


print(max-min)
