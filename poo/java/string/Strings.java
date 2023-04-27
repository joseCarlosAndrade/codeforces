/** 
 * Documentação da classe vai aqui, neste formato.
 * Assim podemos descrever brevemente como ela funciona.
 * Senhor delamaro.
 * @author Jose Carlos
*/


public class Strings
{
    public static void main(String args[])
    {
        String s = new String("argumento aqui");
        String p = "string pode serr feita assim";
    
        // concatenando strings
        String abc = s + p;
        String r = "a";
        r += abc;

        System.out.println(r);
        r = "string a ser comparada";
        if (r.equals("string a ser comparada")){
            System.out.println("\naaaa é igual");
        
        }
        
        String a = "Como assim string".substring(4, 8);
        // devolve a posiçao do caractere ss
        int i = a.indexOf('s');
        System.out.println(a+ i);
    }
    
    /**
     * Descriçao deste metodo, 
     * @return void -> nao retorna nada, apenas recebe como parametro
     * @param parametro descriçao do parametro
     * @throws Exception descriçao do erro que pode lançar
     */
    public void metodo(int parametro)
    {
        System.out.println(parametro);
    }
    /**
     * Sobrescrever metodo
     */
    // @Override
    // public String toString()
    // {
    //     return xi + ""; 
    // }

}