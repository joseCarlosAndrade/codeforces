public abstract class Funcionario
{
    private String nome;
    private String CPF;
    protected double salarioBase;

    /**
     * Método abstrato que retorna o calculo do salario de acordo com o cargo.
     * @return double -> Salário
     */
    public abstract double calculaSalario();

    /**
     * Método abstrato que retorna o cargo do funcionario.
     * @return String -> Cargo
     */
    // public abstract String getCargo();

    /**
     * Método set para inicializar atributos padrões da classe base Funcionario.
     * @param Nome
     * @param CPF_numero
     * @param salarioBase_numero
     */
    public void setInformacoes(String Nome, String CPF_numero, double salarioBase_numero)
    {
        nome = Nome;
        salarioBase = salarioBase_numero; 

        if (Funcionario.verificaCPF(CPF_numero)) CPF = CPF_numero;

        else throw new Error("CPF inválido.");

    }

    /**
     * Método que retorna o nome da classe para obter o cargo do funcionário.
     * @return String
     */
    public String getCargo()
    {
        return this.getClass().getSimpleName();
    }

    /**
     * Getter para nome.
     * @return String -> nome.
     */
    public String getNome()
    {
        return nome;
    }

    /**
     * Getter para CPF
     * @return String -> CPF.
     */
    public String getCPF()
    {
        return CPF;
    }


    /**
     * Método estático que valida o CPF passado como parâmetro.
     * @param CPF
     * @return boolean -> CPF válido ou não.
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