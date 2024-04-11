import math

def remover_nao_primos(lista : list): 
    primos = lista.copy()
    for i in lista:
        # descobrir se eh primo
        if i == 1:
            #primos.append(i)
            continue
        for j in range(2, i):
            if i%j ==0:
                # nao eh primo
                primos.remove(i)
                break 

    return primos

def achar_maior_intervalo_consecutivo(lista : list):
    aux = 0
    for i in range(len(lista)-1):
        if lista[i+1] - lista[i] > aux:
            aux = lista[i+1] - lista[i]

    return aux

        

def achar_maior_intervalo_primos_consecutivos(x: int, y: int):
    lista = []
    for i in range(x,y+1):
        lista.append(i)

    print(lista)
    # removendo primos

    lista_primos = remover_nao_primos(lista)
    print(lista_primos)

    maior_intervalo = achar_maior_intervalo_consecutivo(lista_primos)
    print(maior_intervalo)

x = int(input())
y = int(input())

if x >= y:
    print("X nao é menor que Y")

else:
    achar_maior_intervalo_primos_consecutivos(x,y)

