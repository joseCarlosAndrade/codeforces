import java.util.Date;
import java.util.concurrent.TimeUnit;
import java.lang.Thread;
public class Dado {
    private int lados, numero;

    private String dado1 =
"+-----+"+   
"|     |" +    
"|  *  |" +    
"|     |" +    
"+-----+";

    private String dado2 =
"+-----+"+   
"|*    |" +    
"|     |" +    
"|    *|" +    
"+-----+";

    private String dado3 =
"+-----+"+   
"|*    |" +    
"|  *  |" +    
"|    *|" +    
"+-----+";

    private String dado4 =
"+-----+"+   
"|*   *|" +    
"|     |" +    
"|*   *|" +    
"+-----+";

    private String dado5 =
"+-----+"+   
"|*   *|" +    
"|  *  |" +    
"|*   *|" +    
"+-----+";

    private String dado6 =
"+-----+"+   
"|*   *|" +    
"|*   *|" +    
"|*   *|" +    
"+-----+";

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

    public int rolar() throws InterruptedException
    {
  
        Date date = new Date();

        Thread.sleep(100);
        Random r = new Random(date.getTime());
        numero = r.getIntRand(lados) +1;

        return numero;
    }

    @Override
    public String toString()
    {
        return lista_dados[numero-1];


    }
}
