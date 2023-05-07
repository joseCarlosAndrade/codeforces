def passandoTuple(p1, p2, *args, p3 = 10):
    # caso o ultimo parametro tenha um valor padrao, o ultimo parametro passado na funcao 
    # vai ser deste argumento
    print(p1,p2,p3)

    p2[0] = args[0]
    return 
p2 = [1,2,3]
passandoTuple(0, p2, 100, 'a', 'bds', 10)

print(p2)

def passandoDict(p1, p2, **kwargs):
    print(p1, p2, kwargs)


# passando dicionario 

passandoDict(10, 11, Chave='valor', Chave2=10, Onze = 6.8)


# full: 2 de um numero e 3 de outro -> 15 pontos se tiver um full
# seq: sequencia, 1,2 ,3 ,4,5 ou 2,3,4,5,6 -> faz 20
# quadra: 4 dados iguais -> 30 pontos
# quina: 5 dados iguais -> 40 pontos

# classes definidas no javadoc -> implementa-las


#dois pares = 2 '6' e 2 valetes -> o valor da aposta
#trinca = 3 valetes e o resto distintas -> 2x o valor da aposta
