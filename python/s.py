lista = [1, 2, 9, 3, 4, 5,1, 5, 7,1,8,10]


def segundo_maior(lista):
    maior = lista[0]
    menor = lista[0]

    for elemento in lista:
        if elemento > maior:
            maior = elemento
        if elemento < menor:
            menor = elemento
        
    
    segundo_maior = menor

    for elemento in lista:
        if elemento > segundo_maior and elemento != maior:
            segundo_maior = elemento

    return segundo_maior

#print(segundo_maior(lista))

def juncao_listas(lista1, lista2):
    lista_final = lista1+lista2
    print(lista_final)
    lista_final.sort()
    return lista_final
    
    # alterativa: lista_final = lista1+lista2; nao usei pois e uma funcionalidade mais especifica do python
   # for i in lista1+lista2:
    
a = [6,4,2,4,2,43,6]
b = [5,67,2,1,3,6,1]

#print(juncao_listas(a,b)) 


def caractere_mais_comum(string):
    lista_caracteres = [0] * len(string)

    for i in range(len(string)):
        for j in range(len(string)):
            if string[i] == string[j]:
                lista_caracteres[i] +=1

    maxc = lista_caracteres[0]
    i = 0

    for ic, e in enumerate(lista_caracteres):
        if maxc < e:
            maxc = e
            i = ic
    
    return string[i]

print(caractere_mais_comum("abcabscdnsdfffffffffffklklfkslkfl"))
