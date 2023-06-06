public abstract class Funcionario
{
    private String nome;
    private String CPF;
    protected double salarioBase;
    public abstract double calculaSalario();

    public void setInformacoes(String Nome, String CPF_numero, double salarioBase_numero)
    {
        nome = Nome;
        salarioBase = salarioBase_numero; 

        if (Funcionario.verificaCPF(CPF_numero)) CPF = CPF_numero;

        else throw new Error("CPF inválido.");

    }

    public String getNome()
    {
        return nome;
    }


    /*
     * Metodo estatico definido para avaliar se o cpf é valido ou nao.
     */
    public static boolean verificaCPF(String CPF)
    {
        long primeiraValidacao = 0;
        long segundaValidacao = 0;
        // CPF: String 111.111.111-11
        int verificador1 = Integer.parseInt(CPF.substring(9, 10));
        int verificador2 = Integer.parseInt(CPF.substring(10, 11));
        for (int i = 0; i < 10; i ++)
        {
            // primeira vaidacao
            if (i < 9)
            {
                primeiraValidacao += (10-i) * Integer.parseInt(CPF.substring(i, i+1));
            }
            segundaValidacao += (11-i) * Integer.parseInt(CPF.substring(i, i+1));
            

        }

        long resto1 = (primeiraValidacao*10)%11;
        long resto2 = (segundaValidacao*10)%11;

        if (resto1 == 10 || resto1 == 11) resto1 = 0;
        if (resto2 == 10 || resto2 == 11) resto2 = 0;

        // System.out.printf("%d %d %d %d", primeiraValidacao, segundaValidacao, resto1, resto2);
        if (resto1 != verificador1) return false;
        if (resto2 != verificador2) return false;

        return true;
    }
}