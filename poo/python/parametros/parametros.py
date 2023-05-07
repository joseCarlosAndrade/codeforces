def metodo1(p1, p2):
    p1 = 10
    p2[0] = 10
    return

r = 0
v = [0,0,0,0]
metodo1(r,v)

print(r,v)
# r continua com o mesmo valor, pois os parametros sao passados como valores para variaveis simples
# ja para a lista, é passado uma referencia ao objeto, portanto é alterado.
# isso se aplica a qualquer passagem de objetos

# para quebrar linhas mas continuar o comando podemos usar a barra invertida \

if r ==0 and v[0] ==\
    9:
    print("entrou na condiçao do if")

# sobrecarga de metodos nao é possivel em python como java.
# porem podemos atribuir valores default