t = int(input())

for i in range(t):
    arr= [2, 1]
    tam = 3
    

    n = int(input())

    if n == 1:
        print(2)
        continue

    for j in range(n-2):
        o = j+3

        id=0
        while True:
            print(j)
            if arr[id] + arr[id+1] == o:
                tam += 2
                arr.insert(id+1, o)
                id+=1

            id +=1
            if id >= len(arr)-1:
                break
        
    print(tam)