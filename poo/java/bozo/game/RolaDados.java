import java.util.Arrays;


public class RolaDados {
    private Dado [] lista_dados;
    private int n_dados = 5;

    public RolaDados(int n)
    {
        lista_dados = new Dado[n];
        n_dados = n;
        for (int i = 0; i < n; i++)
        {
            lista_dados[i] = new Dado();
        }
    }

    // rola todos os lados
    public int[] rolar() throws InterruptedException
    {   
        // int[] valor_dados = new int[5];
        int[] valor_dados = {};
        for ( Dado dado : lista_dados )
        {
            // System.out.println(dado.rolar());
            valor_dados = appendArrayInt(valor_dados, dado.rolar());
            
        }
        return valor_dados;

    }

    // Dado rola() somente quando true é passado no boolean
    // Caso false, Dado getLado()
    public int[] rolar (boolean[] quais) throws InterruptedException
    {
        int[] valor_dados = {};
        
        for (int i =0; i < lista_dados.length; i++)
        {
            if (quais[i]){
                valor_dados = appendArrayInt(valor_dados, lista_dados[i].rolar());
            }
            else {
                valor_dados = appendArrayInt(valor_dados, lista_dados[i].getLado());
            }
        }
        return valor_dados;
    }

    public int[] rolar (String s) throws InterruptedException
    {
        int [] valor_dados = {};
        // for (int i = 0; i < lista_dados.length; i++)
        // {    
        // }
        String [] alterar_valores = s.split(" ");

        for (int i = 0; i < lista_dados.length; i++)
        {
            valor_dados = appendArrayInt(valor_dados, lista_dados[i].getLado());
        }

        for (String number : alterar_valores)
        {
            int index = Integer.parseInt(number);
            valor_dados[index-1] = lista_dados[index-1].rolar(); 
        }
        

        return valor_dados;
    }

    @Override
    public String toString()
    {
        String horizontal = ("");

        for (int i =0; i < n_dados; i++)
        {
            horizontal += ((i+1) + "         "); // 3 de espaço entre cada dado
        }

        horizontal += ("\n");
        
        for (int j=0; j < 5; j++)
        {
            for (int i = 0 ; i< n_dados; i++)
            {
                int adder_string = j*7 ;

                horizontal += (lista_dados[i].toString().substring(0 + adder_string, 7+adder_string) + "   ");
            }
            horizontal += ("\n");
        }

        return horizontal;
    }
    
    public int[] appendArrayInt(int[] array, int elemento)
    {
        int[] arr = Arrays.copyOf(array, array.length+1);
        arr[array.length] = elemento;

        return arr;
    }

    // public int[] returnArrayDados()
    // {
    //     int[] lista_valor = new int[n_dados];

    //     for (Dado dado : lista_dados)
    //     {

    //     }

    //     return lista_valor;
    // }
}
