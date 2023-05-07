# def check(lista):
#     aux = 0
#     for i in range(lista):
#         for j in range(lista):
#             if i==j:
#                 continue
            
#             if (lista[i]-lista[j] == 0):
#                 pass
#             else:
#                 aux = lista[j]


# def check_points(lista):
#     aux = 0
#     second= 0
#     for i in range(1,len(lista)):
#         if (lista[0] != lista[i]):
#             aux += 1
#             second = lista [i]
#         if aux > 2:
#             return "No points!"

#         if aux == 2:

        

def check_by_sum(lista):
    score =[]
    old_list = list()

    for i in range (len(lista)):
        if lista[i] in old_list:
                continue
    
        buffer = list()
        for j in range(len(lista)):
            
            if (lista[i] == lista[j]):
                
                buffer.append(lista[j])
                old_list.append(lista[j])
        score.append(buffer)
    print(score)

check_by_sum([2 ,4, 2 , 2, 4])
check_by_sum([1,1,1,1,1])
check_by_sum([1,2,3,4,5])
check_by_sum([4, 5, 4, 4, 4])
