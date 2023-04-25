public class Senha {
    public static void main(String[] args) throws Exception {
        System.out.println("Digite o valor de N (número maximo aleatório): ");

        int n = EntradaTeclado.leInt();
        Random r = new Random();
        int numero = r.getIntRand(n) +1;
        int contador = 1;

        while (true)
        {
            System.out.println("Digite seu " + contador + "º palpite:");
            int palpite = EntradaTeclado.leInt();

            if (palpite == numero)
            {
                System.out.println("Parabéns! Você acertou na " + contador + "º tentativa o número: " + numero);
                break;
            }
            else if (palpite > numero) {
                System.out.println("O número é menor que " + palpite);
            }
            else {
                System.out.println("O número é maior que " + palpite);
            }
            contador += 1;
        }
    }    
}

