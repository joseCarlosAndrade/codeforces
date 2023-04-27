/**
 * Classe para exemplificar sobrecarga de metodos
 */
public class Sobrecarga {
    public static void main(String args[])
    {
        System.out.println("Hello");
    }

    // varios metodos com o mesmo nome e MESMO RETORNO, porem com parametros DIFERENTES
    // podemos diferenciar o retorno deles somente se os parametros forem diferentes 
    public int metodo(int k)
    {
        return 0;
    }

    public int metodo(double x)
    {
        return 0;
    }

    public int metodo(int k, double x)
    {
        return 0;
    }

    public double metodo(double k, double x)
    {
        return 0;
    }

    // ==========
    public int getIntRand()
    {
        // stuff
        return 0;
    }
    public int getIntRand(int maximo)
    {
        // stuff
        return 0;
    }
    // explicitando que este metodo pode lançar uma exception
    public int getIntRand(int minimo, int maximo) throws IllegalArgumentException 
    {
        // checar se maxmio é menor que o minimo
        if (maximo <=minimo)
        {
            // instanciando objeto de erro para illegal argument exception com throw new
            // porem devemos agora declarar no começo do metodo throws IllegalArgumentException
            throw new IllegalArgumentException("Parâmetros inválidos");
        }
        return 0;
    }
}

