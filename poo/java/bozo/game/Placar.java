import java.util.Arrays;

public class Placar {

    private int[] posicoes_ocupadas = new int[10];
    private int[] placar = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    // private List<Integer> posicoes_ocupadas = new ArrayList<>();
    
    public Placar()
    {
// construtor vazio
    }

    public void add(int posicao , int[] dados) throws IllegalArgumentException
    {
// posicao - Posição a ser preenchida. As posições 1 a 6 correspondem às quantidas de uns até seis, ou seja, as laterais do placar. As outas posições são: 7 - full hand; 8 - sequencia; 9 - quadra; e 10 - quina

        // lidando com Exceptions
        if (posicao < 1 && posicao > 10) {
            throw new IllegalArgumentException("Posicao inválida.");
        }
        for (int i = 0; i < posicoes_ocupadas.length; i++)
        {
            if (posicao == posicoes_ocupadas[i])
            {
                throw new IllegalArgumentException("Posicao já ocupada.");
            }
        }

        // adiciona a posicao a lista de posicoes ocupadas
        // add(posicao, posicoes_ocupadas);
        posicoes_ocupadas = appendArrayInt(posicoes_ocupadas, posicao);
        

        int pontuacao_atual = 0;
        // pontuaçao em casos nao fixos
        
        if (posicao < 7)
        {
            
            for (int i = 0; i < 5; i++)
            {
                // dados = {1, 2, 4, 5, 6}
                if (posicao == dados[i])
                {
                    pontuacao_atual += 1;
                }
            }

            placar[posicao-1] = pontuacao_atual * posicao;
        }
        // posiçao em casos fixos
        else {
            int[] frequencia = checar_frequencia_por_soma(dados);
            pontuacao_atual = 0;
            // retorna uma lista com a frequencia de cada numero nos 5 dados
            // 0, 1, 2, 3, 4 (index)
            // 1, 2, 3, 4, 5 (dados)
            // 0, 3, 2, 0, 0 -> 3 dados numero 2, 2 dados numero 3

            switch (posicao){
                // full hand 15 pontos  
                case 7:
                {  
                    if (elemento_na_lista(2, frequencia) && elemento_na_lista(3, frequencia))
                    {
                        pontuacao_atual = 15;
                    }
                    
                    break;
                }
                case 8: // sequencia 20 pontos
                {
                   
                    if (checar_sequencia(dados) == 1) {
                        
                        pontuacao_atual = 20;
                    }
                    
                    break;
                }
                case 9: // quadra 30 pontos
                {
                    for (int i=0; i < dados.length; i++)
                    {
                        if (frequencia[i]>=4)
                        {
                            pontuacao_atual = 30;
                        } 
                    }
                    break;
                }
                case 10: // quina 40 pontos
                {
                    for (int i=0; i < dados.length; i++)
                    {
                        if (frequencia[i]==5)
                        {
                            pontuacao_atual = 40;
                        } 
                    }
                    break;
                }

            }
            placar[posicao-1] = pontuacao_atual;
        }

    }


    // a partir daqui sao funcoes nao inclusas no javadoc, feitas para facilitar algumas logicas

    public boolean elemento_na_lista(int elemento, int[] lista)
    // retorna true se lista contem elemento
    {
        for (int i = 0; i < lista.length; i++)
        {
            if (lista[i] == elemento)
            {
                return true;
            }
        }
        return false;
    }

    public int checar_sequencia(int[] dados)
    {
        // define o menor numero na array
        int menor_numero = dados[0];

        for (int i = 0; i < dados.length; i++)
        {
            if (dados[i] < menor_numero){
                menor_numero = dados[i];
            }
        }
        // System.out.printf("menor numero: %d", menor_numero);

        int contador_sequencia= 0;
        for (int i = 0; i < dados.length; i++)
        {
            for (int j = 0; j < dados.length; j++)
            {
                if (dados[j] == menor_numero+1)
                {
                    contador_sequencia++;
                    menor_numero = dados[j];
                    // continue;
                }
            }
        }
  
        if (contador_sequencia == dados.length-1) {
            // retorna 1, sequencia encontrada
            return 1;
        }
        // caso contrario, retorna 0
        return 0;
    }

    public int[] checar_frequencia_por_soma(int[] dados)
    {
        int [] frequencia = { 0, 0, 0, 0, 0, 0 };

        // loop em cada face  
        for (int i=1; i < 7; i++)
        {
            for (int j = 0; j < dados.length; j++)
            {
                if (dados[j] == i)
                {
                    frequencia[i-1] += 1;
                }
            }
        }

        return frequencia;

    }

    public int getScore()
    {
        int soma = 0;
        for (int i=0; i<placar.length ; i++)
        {
            if (placar[i] ==-1 )
            {
                continue;
            }
            soma += placar[i];
        }
        return soma;
    }

    @Override
    public String toString()
    {
        String[] lp = new String[10];
        for (int i = 0; i < placar.length; i++)
        {
            if (placar[i] ==-1 )
            {
                lp[i] = " ";
            }
            else
            {
                lp[i] = Integer.toString(placar[i]);
            }
        }
        String placar_string  = 
String.format(
"(1) %s  |   (7) %s   | %s  (4) \n"+ 
"-------------------------- \n"+
"(2) %s  |   (8) %s   | %s  (5)  \n"+
"-------------------------- \n"+
"(3) %s  |   (9) %s   | %s  (6)  \n"+
"-------------------------- \n"+
"        |   (10)  %s |     \n"+
"        +------------+        \n", lp[0],lp[6],lp[3],lp[1],lp[7],lp[4],lp[2],lp[8],lp[5],lp[9]);

        return placar_string;
    }

    public int[] appendArrayInt(int[] array, int elemento)
    {
        int[] arr = Arrays.copyOf(array, array.length+1);
        arr[array.length-1] = elemento;

        return arr;
    }

    public String[] appendArrayString(String[] array, String elemento)
    {
        String [] arr = Arrays.copyOf(array, array.length+1);
        arr[array.length-1] = elemento;
        
        return arr;
    }

    public boolean endReached()
    {
        for (int i=0; i<placar.length ; i++)
        {
            if (placar[i] == -1 )
            {
                return false;
            }
        }
        return true;
    }
    
}

