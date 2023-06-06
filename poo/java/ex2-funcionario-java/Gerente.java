
public class Gerente extends Funcionario  {
    public Gerente(String nome, String cpf, double salarioBase)
    {
        setInformacoes(nome, cpf, salarioBase);
    }

    @Override
    public double calculaSalario()
    {
        return 2*salarioBase;
    }

    // @Override
    // public String getCargo()
    // {
    //     return this.getClass().getSimpleName();
    // }
}
