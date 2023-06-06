import java.io.IOException;
import java.util.Arrays;

import javax.swing.text.Style;
public class Folha {
    
    public static void main(String args[]) throws IOException
    {
        /* Instanciando arrays e cada funcionário. */
        Assistente assistentes[] ={};
        Gerente gerentes[] ={};
        Vendedor vendedores[] ={};

        // assistentes = appendElemento(assistentes, new Assistente("José", "47696231863", 1000));
        // gerentes = appendElemento(gerentes, new Gerente("José", "47696231863", 1000));
        // vendedores = appendElemento(vendedores, new Vendedor("José", "47696231863", 1000, 100));
        
        while (true)
        {
            System.out.println("Digite as informações do(a) funcionário(a). (Digite SAIR para interromper o cadastro e mostrar o resultado.) ");

            System.out.print("Nome: ");
            String nome = EntradaTeclado.leString();
            if (nome.equals("SAIR")) break;

            System.out.print("CPF: ");
            String cpf = EntradaTeclado.leString();

            // checa se o cpf é valido. Caso não seja, lança um erro.
            if (!Funcionario.verificaCPF(cpf)) throw new Error("Erro - CPF inválido.");

            System.out.print("Salário Base: ");
            Double salarioBase = EntradaTeclado.leDouble();            

            System.out.print("Insira o cargo (ex. vendedor, gerente ou assistente): ");
            String cargo = EntradaTeclado.leString();
            

            if (cargo.equals("vendedor")) {
                System.out.print("Digite a comissão do(a) vendedor(a): ");
                Double comissao = EntradaTeclado.leDouble();
                vendedores = appendElemento(vendedores, new Vendedor(nome, cpf, salarioBase, comissao));
                
            }
            else if (cargo.equals("assistente")) assistentes = appendElemento(assistentes, new Assistente(nome, cpf, salarioBase));
            
            else if (cargo.equals("gerente")) gerentes = appendElemento(gerentes, new Gerente(nome, cpf, salarioBase));
        
            else System.out.println("Cargo não encontrado.");

            System.out.println();
        }

        double totalSalario = 0;

        System.out.println("\n====== Informações dos(as) funcionários(as): ======\n");

        /* Saída para apresentar todos os funcionários e somar o salário total.
         */
        for (Assistente assistente : assistentes) {
            System.out.printf("Funcionario(a): %s; Cargo: %s; CPF: %s; Salario final: R$ %.2f;\n\n", assistente.getNome(), assistente.getCargo(), assistente.getCPF(), assistente.calculaSalario());
            totalSalario += assistente.calculaSalario();
        }

        for (Gerente assistente : gerentes) {
            System.out.printf("Funcionario(a): %s; Cargo: %s; CPF: %s; Salario final: R$ %.2f;\n\n", assistente.getNome(), assistente.getCargo(), assistente.getCPF(), assistente.calculaSalario());
            totalSalario += assistente.calculaSalario();

        }
        for (Vendedor assistente : vendedores) {
            System.out.printf("Funcionario(a): %s; Cargo: %s; CPF: %s; Salario final: R$ %.2f;\n\n", assistente.getNome(), assistente.getCargo(), assistente.getCPF(), assistente.calculaSalario());
            totalSalario += assistente.calculaSalario();
        }
    
        System.out.printf("Total em R$: %.2f\n", totalSalario);
        // Gerente g = new Gerente("jose", cpf, 10);
        // System.out.println(g.calculaSalario());
    
    }

    /**
     * Metodo estatico para adicionar um elemento generico a uma lista do mesmo tipo.
     * @param <T> Parametro generico
     * @param array
     * @param elemento
     * @return
     */
    public static <T> T[] appendElemento(T[] array, T elemento)
    {
        T [] arr = Arrays.copyOf(array, array.length+1);
        arr[array.length] = elemento;
        
        return arr;
    }    
}

