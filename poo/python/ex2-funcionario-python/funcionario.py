from abc import ABC, abstractmethod

'''
Classe pai que todas as outras herdam. Define o metodo abstrato calculaSalario() -> float,
além do método estático verificaCPF() -> bool'''
class Funcionario:

    def __init__(self, nome, cpf, salarioBase):
        self._nome = nome
        self._cpf = cpf
        self._salarioBase = salarioBase

    def getNome(self):
        return self._nome
    
    def getSalarioBase(self):
        return self._salarioBase
    
    def getCPF(self):
        return self._cpf

    @abstractmethod
    def calculaSalario():
        pass

    '''
    Retorna o cargo do funcionário.
    '''
    @classmethod
    def getClass(cls) -> str:
        return cls.__doc__

    '''
    Método estático que verifica a autenticidade do CPF passado como argumento.
    '''
    @staticmethod
    def verificaCPF(cpf) -> bool:
        primeira_soma = 0
        segunda_soma = 0

        validacao_1 = int(cpf[-1])
        validacao_2 = int(cpf[-2])
        for i in range(len(cpf)-1):
            if i<9:
                primeira_soma += int(cpf[i])*(10-i)

            segunda_soma += int(cpf[i])*(11-i)

        # print(primeira_soma, segunda_soma)

        resto1 = (primeira_soma*10)%11
        resto2 = (segunda_soma*10)%11

        if (resto1 == 10 or resto1 == 11):
            resto1 = 0
        if (resto2 == 10 or resto2 == 11):
            resto2 = 0

        if (resto1 != validacao_1):
            return True
        if (resto2 != validacao_2):
            return True

        return True

