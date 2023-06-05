
public class Assistente extends Funcionario  {
    public Assistente(String nome, String cpf, double salarioBase)
    {
        setInformacoes(nome, cpf, salarioBase);
    }

    @Override
    public double calculaSalario()
    {
        return salarioBase;
    }
}
