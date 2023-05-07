public class Dado {
    private int lados, numero;

    private String dado1 =
"+-----+\n"+   
"|     |\n" +    
"|  *  |\n" +    
"|     |\n" +    
"+-----+\n";

    private String dado2 =
"+-----+\n"+   
"|     |\n" +    
"|  *  |\n" +    
"|     |\n" +    
"+-----+\n";

    private String dado3 =
"+-----+\n"+   
"|     |\n" +    
"|  *  |\n" +    
"|     |\n" +    
"+-----+\n";

    private String dado4 =
"+-----+\n"+   
"|     |\n" +    
"|  *  |\n" +    
"|     |\n" +    
"+-----+\n";

    private String dado5 =
"+-----+\n"+   
"|     |\n" +    
"|  *  |\n" +    
"|     |\n" +    
"+-----+\n";

    private String dado6 =
"+-----+\n"+   
"|     |\n" +    
"|  *  |\n" +    
"|     |\n" +    
"+-----+\n";

    private String[] lista_dados = {dado1, dado2, dado3, dado4, dado5, dado6};

    /**
     * Construtor padrao, sem parametro.
     * @return void 
     */
    public Dado()
    {
        lados = 6;
    }

    /**
     * Construtor com parametro k -> numero de lados. Caso o k seja menor ou igual a 0, o dado será construido com 6 lados.
     * @return void 
     */

    public Dado(int k)
    {
        if (k > 0)
        {
            lados = k;
        }
        else {
            System.out.println("Tamanho inválido. Será criado um dado de 6 lados.\n");
            lados = 6;
        }
    }
    
    public int getLado()
    {
        return numero;
    }

    public int rolar()
    {
        // int n = EntradaTeclado.leInt();
        Random r = new Random();
        numero = r.getIntRand(lados) +1;

        return numero;
    }

    @Override
    public String toString()
    {
        return lista_dados[numero-1];
        // System.out.println(lista_dados[numero-1]);
        // switch (numero)
        // {
        //     case 0:
        //     System.out.println(dado1);
        // }
    }
}
