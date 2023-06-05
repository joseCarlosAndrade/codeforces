public class Folha {
    
    public static void main(String args[])
    {
        String cpf = "47696231863";

        if (!Funcionario.verificaCPF(cpf))
        {
            System.out.println("invalid cpf");
            throw new Error("CPF invalido");
        }
    
        Gerente g = new Gerente("jose", cpf, 10);
        System.out.println(g.calculaSalario());
    
    }
}
