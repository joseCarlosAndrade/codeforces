class Carro:
    def __init__(self, nome = '', modelo = '', ano = 0, preco = 0) -> None:
        self.nome = nome
        self.modelo = modelo
        self.ano = ano
        self._preco = preco

    def returnInfo(self):
        print(self.nome, self.modelo, self.ano, self._preco)



class Veiculo(Carro):
    def __init__(self, nome='', modelo='', ano=0, preco=0) -> None:
        super().__init__(nome, modelo, ano, preco)
        # super funciona para inicializar o construtor da classe herdada, passando como parametro
        # o que foi passado no primeiro construtor

    



