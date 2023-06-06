
public class Vendedor extends Funcionario  {
    double comissao;
    public Vendedor(String nome, String cpf, double salarioBase, double comissao_valor)
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
