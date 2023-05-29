public class Bozo
{
    public static void main(String args[]) throws java.io.IOException, InterruptedException
    {
        // Criacao dos objetos necessarios para tomar conta do jogo
        RolaDados dados = new RolaDados(5);
        Placar placar = new Placar();
        // Dado dado_individual = new Dado(6);
        // System.out.println(dado_individual.rolar());

        while (true)
        {
            // rolar os 5 dados + printar
            int[] array_dados = dados.rolar();
            System.out.println(dados.toString());

            // laco para alterar os dados ate 2 vezes mais
            // if entrada = nao -> skip; else -> rolar
            for (int i = 0; i <2; i++)
            {
                System.out.println("Dados a seguir. Caso queira rolar novamente algum dos dados, digite ex: 1 3 4 para rolar os dados 1, 3 e 4, ou 0 para continuar deste jeito.\n");
                String rolar_mais = "0";
                
                rolar_mais = EntradaTeclado.leString();
                
                if (rolar_mais.compareTo("") == 0) { 
                    break;
                }
                
                // System.out.println(rolar_mais.length());
                array_dados = dados.rolar(rolar_mais);
                System.out.println(dados.toString());
            }


            // escolha da posicao do tabuleiro e mostra o placar
            System.out.println("\nPlacar atual: \n");
            System.out.println(placar.toString());

            System.out.println("Escolha uma das posiçoes para preencher: ");
            while (true){
                int posicao = EntradaTeclado.leInt();
                if (posicao > 0 && posicao < 11) { 
                    placar.add(posicao, array_dados);
                    break;
                }
                System.out.println("Erro. Digite uma posicao valida.");
            }

            System.out.println("\nPlacar atual: \n");
            System.out.println(placar.toString());
            System.out.printf("Pontuacao atual: %d\n", placar.getScore());

            if (placar.endReached())
            {
                System.out.printf("\nFim de jogo! Pontuação final: %d.\n", placar.getScore());
                break;
            }

        }
    }
}