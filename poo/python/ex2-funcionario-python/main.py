from cargos import Vendedor, Gerente, Assistente
from funcionario import Funcionario

def main():

    lista_funcionarios = []

    funcionarios_map = {
        'vendedor' : Vendedor,
        'gerente': Gerente,
        'assistente' : Assistente
    }

    print("(Digite SAIR para interromper o programa)")
    while True:
        nome = input("\nDigite o nome do funcionario: (SAIR para parar de inserir funcionarios) \n")
        if nome == 'SAIR':
            break
        cpf = str(input("Digite o cpf do funcionario: "))
        salario_base = input("Digite o salario base do funcionario: ")
        cargo = input("Digite o cargo do funcionario (ex. vendedor, gerente ou assistente): ")

        if Funcionario.verificaCPF(cpf=cpf):   

            try:
                lista_funcionarios.append(funcionarios_map[cargo](nome, cpf, salario_base))

            except Exception as err:
                print(f"Erro. Cargo não encontrado. '{cargo}'")
        else:
            print("Erro! CPF inválido. Funcionário não adicionado.")
    

    print("\nOperação finalizada! Folha de pagamentos da empresa: ")
    salario_total = 0
    for funcionario in lista_funcionarios:
        salario = funcionario.calculaSalario()
        salario_total += salario
        print(f"==========================================\nFuncionario: {funcionario.getNome()}. Cargo: {funcionario.getClass()}. CPF: {funcionario.getCPF()}\nSalario base: R$ {funcionario.getSalarioBase()}. Salario final: R$ {salario}.\n")
    
    print(f"\nTotal de salários: R$ {salario_total}")

if __name__ == "__main__":
    main()