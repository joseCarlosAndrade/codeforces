public class MegaSena

{
    public static void main(String[] args) throws Exception {
        System.out.println("Digite um número inteiro para semente: ");
        // EntradaTeclado entrada = new EntradaTeclado();
        // int semente = entrada.leInt();
        int semente = EntradaTeclado.leInt();
        Random r = new Random(semente);

        r.setSemente(semente);

        r.getSemente();
        for (int i =0 ; i < 6; i++)
        {
            // pegar numerp aleatório entre 1 e 60
            int k = r.getIntRand(60) + 1;
            System.out.println(k);

        }
    }
} 