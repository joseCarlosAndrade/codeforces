
public class Vendedor extends Funcionario  {
    long comissao;
    public Vendedor(String nome, String cpf, double salarioBase, long comissao_valor)
    {
        setInformacoes(nome, cpf, salarioBase);
        comissao = comissao_valor;
    }

    @Override
    public double calculaSalario()
    {
        return salarioBase + comissao;
    }
}
