class ponto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # __str__ faz com que quando usarmos print(ponto), ao inves de printar 
    # a identificaçao do objeto como <ponto.ponto object at 0xasfs>, ele executa este membro
    def __str__(self):
        return '({:d}, {:d})'.format(self.x,self.y)
        # printa: (x,y)

    # less than , caso usemos o comparador < entre dois objetos ponto
    # nos permite:
    # p1 = ponto(valor, valor)
    # p2 = ponto(valor2, valor2)
    # p1 < p2
    def __lt__(self, outro):
        # se outro for qualquer objeto de qualquer classe que tenha atributos x e y, funciona
        # python nao verifica mtipos
        z1 = self.x ** 2 + self.y **2
        z2 = outro.x **2 + outro.y**2
        return z1 < z2

    # metodos para comparaçao entre objetos
    # __le__ less equal
    # __eq__ ==
    # __neq__ !=
    # __gt__ >
    # __ge__ >=