import java.util.List;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class Placar {

    private int[] posicoes_ocupadas = new int[10];
    private int[] placar = {0,0,0,0,0,0,0,0,0,0};

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

            placar[posicao-1] = pontuacao_atual;
        }
        // posiçao em casos fixos
        else {
            int[] frequencia = checar_por_soma(dados);

            switch (posicao){
                // full hand
                case 7:
                {  
                    
                    break;
                }
                case 8:
                case 9:
                case 10:

            }
        }


    }

    // TO DO
    public int[] checar_por_soma(int[] dados)
    {
        int[] score;
        int[] old_list;

        for (int i=0; i < dados.length; i++)
        {
            for (int o =0; o< old_list.length; o++)
            {
                if (dados[i] == old_list[o]){
                    continue;
                }
            }

            int[] buffer;
            for (int j=0; j<dados.length;j++)
            {
                if(dados[i] == dados[j])
                {
                    buffer = appendArrayInt(buffer, dados[j]);
                    old_list = appendArrayInt(old_list, dados[j]);
                }
            }

            // score = appendArrayInt(score, )
        }

        return dados;
    }

    public int getScore()
    {
        int soma = 0;
        for (int i=0; i<placar.length ; i++)
        {
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
            if (placar[i] ==0 )
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
"(2) %s  |   20  %s   | %s  (5)  \n"+
"-------------------------- \n"+
"(3) %s  |   30  %s   | %s  (6)  \n"+
"-------------------------- \n"+
"        |   (10)  %s |     \n"+
"        +------------+        \n", lp[0],lp[1],lp[2],lp[3],lp[4],lp[5],lp[6],lp[7],lp[8],lp[9]);

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
    
}

