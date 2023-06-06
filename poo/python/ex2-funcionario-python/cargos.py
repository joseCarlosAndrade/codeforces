from funcionario import Funcionario

'''
Classe Gerente, que herda Funcionario.
'''
class Gerente(Funcionario):
    'Gerente'
    def __init__(self, nome, cpf, salarioBase):
        super().__init__(nome, cpf, salarioBase)

    def calculaSalario(self):
        return 2*float(self._salarioBase)
    


'''
Classe Assistente, que herda Funcionario.
'''
class Assistente(Funcionario):
    'Assistente'
    def __init__(self, nome, cpf, salarioBase):
        super().__init__(nome, cpf, salarioBase)
        

    def calculaSalario(self):
        return float(self._salarioBase)
    

'''
Classe Vendedor. Herda de Funcionario, alem de implementar um novo construtor, o qual recebe
comissao como parametro para definir o atributo de classe de mesmo nome.
'''
class Vendedor(Funcionario):
    'Vendedor'
    def __init__(self, nome, cpf, salarioBase):
        super().__init__( nome, cpf, salarioBase)
        

    def __init__(self, nome, cpf, salarioBase):
        self._nome = nome
        self._cpf = cpf
        self._salarioBase = salarioBase

        self.comissao = input("Digite o valor da comissão para o vendedor: ")

    def calculaSalario(self):
        return float(self._salarioBase) + float(self.comissao)