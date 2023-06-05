public class Folha {
    
    public static void main(String args[])
    {
        // 41409331863 cpf invalido
        String nomes[] = {"jose", "andrade", "marcos", "pedro", "maria"};

        String cpf[] = {"47696231863", "41409331865", "41409331865", "41409331865", "4140931865"};
        Funcionario funcionarios[];

        for (int i = 0; i < 2; i++)
        {
            funcionarios[i] = new Assistente(nomes[i], cpf[i], 1000);
        }

        for (int i = 2; i < 4; i++)
        {
            funcionarios[i] = new Gerente(nomes[i], cpf[i], 2000);

        }

        for (int i = 4; i < 5; i++)
        {
            funcionarios[i] = new Vendedor(nomes[i], cpf[i], 1000, 500);

        }

        double totalSalario = 0;

        for (int i = 0; i < 5; i++)    
        {
            double salario = funcionarios[i].calculaSalario();
            System.out.printf("Nome: %s; Salario: %d\n", funcionarios[i].getNome(), salario);
            totalSalario += salario;
        }
    
        System.out.printf("Total em R$: \n", totalSalario);
        // Gerente g = new Gerente("jose", cpf, 10);
        // System.out.println(g.calculaSalario());
    
    }
}
